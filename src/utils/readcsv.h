typedef struct csv_details {
    int max_rows;
    int max_cols;
    double ** csv_data;    // Access as 2d array csv_data[COL][ROW]
} csv_struct_t;

// Function call, provide base file name and pointer to struct.
int readCSV( csv_struct_t * csv_struct_ptr, char * file );
double ** make2dArray( int x, int y );