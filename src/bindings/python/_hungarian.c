#include <Python.h>
#include "hungarian.h"
#include <numpy/arrayobject.h>
#include <stdlib.h>


static char module_docstring[] = "This module provides an interface for the Hungarian algorithm using C.";
static char hungarian_docstring[] = "Calculate the minimum cost matching in a bipartite graph.";

static PyObject *hungarian_hungarian(PyObject *self, PyObject *args);

static PyMethodDef module_methods[] = {
    {"hungarian", hungarian_hungarian, METH_VARARGS, hungarian_docstring},
    {NULL, NULL, 0, NULL}
};

double ** make2dArray( int x, int y ) {
    double ** array_ptr;
    int i;

    array_ptr = (double **)malloc( sizeof( double *) * x );

    /* Check for not enough memory */
    if( array_ptr == NULL ) return NULL;

    for( i = 0; i < y; i++ ) {

        array_ptr[i] = (double *)malloc( sizeof( double ) * y );

        /* Check for not enough memory */
        if( array_ptr == NULL ) return NULL;

    }

    return array_ptr;
}

PyMODINIT_FUNC init_hungarian(void)
{
    PyObject *m = Py_InitModule3("_hungarian", module_methods, module_docstring);
    if (m == NULL)
        return;

    /* Load `numpy` functionality. */
    import_array();
}

static PyObject *hungarian_hungarian(PyObject *self, PyObject *args) {
	
	hungarian_problem_t p;
	PyObject *cost_matrix_obj;
	int max_row,max_col;
	int row,col;

    /* Parse the input tuple */
    if (!PyArg_ParseTuple(args, "O", &cost_matrix_obj))
        return NULL;


    /* Interpret the input objects as numpy arrays. */
    PyObject *cost_array = PyArray_FROM_OTF(cost_matrix_obj, NPY_DOUBLE, NPY_IN_ARRAY);
    
    /* If that didn't work, throw an exception. */
    if (cost_array == NULL ) {
        Py_XDECREF(cost_array);
        return NULL;
    }

    /* What is the size of the matrix? */
    max_row = (int)PyArray_DIM(cost_array, 0);
    max_col = (int)PyArray_DIM(cost_array, 1); 

    /* allocate memory for the cost array */
    double **cost = make2dArray( max_col, max_row );
    
    /* Fill the cost array with data from the numpy array */
	for (col=0; col < max_col; col++)
		for (row=0; row < max_row; row++)
			cost[row][col] = *((double *)PyArray_GETPTR2(cost_array,row,col));
    


    /* Initialize the data structure */
    hungarian_init(&p,cost,max_row,max_col,HUNGARIAN_MODE_MINIMIZE_COST);
	
    /* Call the external C function to compute the matching. */
    hungarian_solve(&p);


    /* Clean up. */
    Py_DECREF(cost_array);

    /* Build assignments */
    int c_assignment[max_col];

    for(row=0; row<p.num_rows; row++){
	    for(col=0; col<p.num_cols; col++){
		    if(p.assignment[row][col]==1){ c_assignment[row]=col; }
	    }
    }

    /* Deallocate the data structure */
    hungarian_free(&p);    

    /* Build the output list */
    PyObject *assignment = PyList_New(max_col);

    if (!assignment) return NULL;

    for (row=0;row<max_row;row++) {
	    PyObject *num = Py_BuildValue("i",c_assignment[row]);
	    if (!num) {
		   Py_DECREF(assignment);
		   return NULL;
	    }
	    PyList_SetItem(assignment, row, num);   // reference to num stolen
    }

    return assignment;
}
