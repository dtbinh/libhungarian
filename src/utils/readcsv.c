// Based on code from http://www.paulodowd.com/2011/01/c-for-csv-files.html

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "readcsv.h"
#define NEWLINE 10
#define COMMA    44

double ** make2dArray( int x, int y ) {
    double ** array_ptr;
    int i,j;

    array_ptr = (double **)malloc( sizeof( double *) * x );

    // Check for not enough memory
    if( array_ptr == NULL ) return NULL;

    for( i = 0; i < y; i++ ) {

        array_ptr[i] = (double *)malloc( sizeof( double ) * y );

        // Check for not enough memory
        if( array_ptr == NULL ) return NULL;

    }

    return array_ptr;
}

int readCSV( csv_struct_t * csv_struct_ptr, char * file) {
    
    int col;
    int row;
    int i,j;
    char buf[40];
    int c;
    FILE * fp;

    // We try to open the file.
    printf(file);
    fp = fopen(file, "r");
    if( fp == NULL ) {
        printf(" - Could not open file! Abort!\n");
        return 0;
    }

    printf("\n Attempting to find out row and column dimensions...\n");
    row = 0;
    col = 0;
    i = 0;
    j = 0;
    while( ( c = fgetc( fp )) != EOF ) {
        if( c != COMMA && c != NEWLINE ) {
            i++;
        } else if( c == COMMA ) {
            j++;
            i = 0;
        } else if ( c == NEWLINE ) {
            if( i != 0 ) j++;
            if( j > col ) col = j;
            
            j = 0;
            row++;
        }
    }
    fclose( fp );
    
    printf(" - I found %d columns, %d rows\n", col, row);

    // Create an array large enough to hold all of our data    
    csv_struct_ptr->max_cols = col;
    csv_struct_ptr->max_rows = row;
    csv_struct_ptr->csv_data = make2dArray( col, row );

    if( csv_struct_ptr->csv_data == NULL ) {
        printf(" Not enough memory :(\n");
        printf(" abort\n");
        return 0;
    }
        
    // Finally, read in the data from each file and store
    // in our array.

        // Open the file to read

        fp = fopen( file, "r" );
        if( fp == NULL ) {
            printf(" Error, could not open %s, abort\n", file);
            return 0;
        }    
        
        // Reset variables that index the arrays
        i = 0;
        col = 0;
        row = 0;
        c = 0;
        memset( buf, '\0', sizeof(buf));

        // Read in the file data.
        while( ( c = fgetc( fp ) ) != EOF )  {

            if( c != COMMA && c != NEWLINE ) {

                // We have a character
                buf[i] = c;
                i++;

            } else if ( c == COMMA ) {
                // We save the data, jump a column
		csv_struct_ptr->csv_data[row][col] = atof( buf );
		//printf("%i %i %f",row, col,csv_struct_ptr->csv_data[row][col]);
		//printf(",");

                // Clear the buffer
                memset( buf, '\0', sizeof( buf ));

                col++;
                i = 0;

            } else if ( c == NEWLINE ) {		    
                if( i != 0 ) {
                    // We save the data, jump a column
                    csv_struct_ptr->csv_data[row][col] = atof( buf );
		    //printf("%i %i %f",row,col,csv_struct_ptr->csv_data[row][col]);
		    //printf("\n");
                    memset( buf, '\0', sizeof( buf ));
                }
                // We want to drop a line.
                i = 0;
		col = 0;
                row++;    
            }    
        }    

        // Close that file, ready for the next
        fclose( fp );
        printf(" - Done\n");

	
	return 1;
    
}


