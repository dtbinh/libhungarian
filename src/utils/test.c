#include <stdio.h>
#include "readcsv.h"

int main(void) {

	// Variable declaration
	csv_struct_t my_csv_files;
	int row, col;

	// Function call, imports your files.
	readCSV( &my_csv_files, "../../testfiles/3intarray");

	for( row = 0; row < my_csv_files.max_rows; row++ ) {
            for( col = 0; col < my_csv_files.max_cols; col++ ) {
                printf("%f ", my_csv_files.csv_data[row][col]);
            }
	printf("\n");
	}
}
