/********************************************************************
 ********************************************************************
 **
 ** libhungarian by Cyrill Stachniss, 2004
 **
 **
 ** Solving the Minimum Assignment Problem using the 
 ** Hungarian Method.
 **
 ** ** This file may be freely copied and distributed! **
 **
 ** Parts of the used code was originally provided by the 
 ** "Stanford GraphGase", but I made changes to this code.
 ** As asked by  the copyright node of the "Stanford GraphGase", 
 ** I hereby proclaim that this file are *NOT* part of the
 ** "Stanford GraphGase" distrubition!
 **
 ** This file is distributed in the hope that it will be useful,
 ** but WITHOUT ANY WARRANTY; without even the implied 
 ** warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 ** PURPOSE.  
 **
 ********************************************************************
 ********************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include "hungarian.h"
#include "readcsv.h"

int main( int argc, char *argv[] ) {

  hungarian_problem_t p;
  
  FILE* inf; // input file stream
  char * file; 
  size_t row = 0;
  size_t column = 0;
  csv_struct_t csvdata;

  file=argv[1];
//  inf = fopen( file , "r" );

  // use CSV code to open and read file into grid
  readCSV( &csvdata, file );

//  int** grid = allocate_memory_for_grid( row, column );
//  read_grid_from_file( grid, row, column, inf );
    

  /* initialize the hungarian_problem using the cost matrix*/
  int matrix_size = hungarian_init(&p, csvdata.csv_data , csvdata.max_rows,csvdata.max_cols, HUNGARIAN_MODE_MINIMIZE_COST) ;

  fprintf(stderr, "assignement matrix has a now a size %d rows and %d columns.\n\n",  matrix_size,matrix_size);

  /* some output */
  //fprintf(stderr, "cost-matrix:");
  //hungarian_print_costmatrix(&p);

  /* solve the assignement problem */
  hungarian_solve(&p);


  /* some output */
  fprintf(stderr, "assignment:");
  hungarian_print_assignment(&p);

  /* free used memory */
  hungarian_free(&p);

  return 0;
}

