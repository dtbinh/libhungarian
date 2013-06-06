#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "hungarian.h"
#include "mex.h"


/* Define the various input and outputs from/to Matlab, for easier-to-read code. */

#define COST_MAT prhs[0]
#define MATCHING plhs[0]
#define COST plhs[1]

typedef struct csv_details {
    int max_rows;
    int max_cols;
    double ** csv_data;    /* Access as 2d array csv_data[COL][ROW] */
} csv_struct_t;

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


void Free2DArray(double ** Array, int y)
{
	int i;

	for( i=0; i<y; i++ ) {
		free(Array[i]);
	}

	free(Array);
}

void hungarian_free(hungarian_problem_t* p) {
  int i;
  for(i=0; i<p->num_rows; i++) {
    free(p->cost[i]);
    free(p->assignment[i]);
  }
  free(p->cost);
  free(p->assignment);
  p->cost = NULL;
  p->assignment = NULL;
}


void mexFunction( int nlhs, mxArray  *plhs[], int nrhs, const mxArray  *prhs[] ) {

	int max_row,max_col;	/* row and column size, resp. */
	int row,col;		/* current row/col index. */
	int matrix_size;
	
	csv_struct_t  csv_struct_ptr;
	
	hungarian_problem_t p;
	
	max_row = mxGetM(COST_MAT);	/* These two lines get the row and col dimensions of the Matlab array */
	max_col = mxGetN(COST_MAT);
	
	printf(" - I found %d columns, %d rows\n", max_col, max_row);
	
	/* Next three lines initialize our matrix */
	csv_struct_ptr.max_cols = max_col;
	csv_struct_ptr.max_rows = max_row;
	csv_struct_ptr.csv_data = make2dArray( max_col, max_row );
	
	MATCHING = mxCreateDoubleMatrix(max_row,1,mxREAL);	/* Initialize output variables */
	COST = mxCreateDoubleScalar(0);
	
	/* This double for loop reads the Matlab array COST_MAT into our matrix */
	for (col=0; col < max_col; col++)
		for (row=0; row < max_row; row++)
			csv_struct_ptr.csv_data[row][col] = (mxGetPr(COST_MAT))[row+col*max_row];
	
	/* Initialize the structure holding the matrix, and tell the algorithm to minimize */
	matrix_size = hungarian_init(&p, csv_struct_ptr.csv_data , max_row, max_col, HUNGARIAN_MODE_MINIMIZE_COST);
	
	/* Do the Magyarena */
	hungarian_solve(&p);
	
	/* Return the structure we want: the matchings as an n-vector, cost as scalar */
	for(row=0;row<p.num_rows;row++){
		for(col=0;col<p.num_cols;col++){
			if(p.assignment[row][col]==1) {
				(mxGetPr(MATCHING))[row]=col;					/* mxGetPr(object) returns a pointer to the object */
				(mxGetPr(COST))[0] += csv_struct_ptr.csv_data[row][col];
			}
		}
	}
	
	
	Free2DArray(csv_struct_ptr.csv_data,max_row);  /* Freedom from the yoke of tyrrany! (a.k.a. this little module really shouldn't leak memory) */
	hungarian_free(&p);
}


