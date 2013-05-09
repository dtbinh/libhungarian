#include <stdio.h>
#include <stdlib.h>

int main( int argc, char *argv[] ) {
	int row,col,max_cost;
//	char * filename
	int r,c;
	
	int random[row][col];
	
//	filename = argv[1];
	row = atoi(argv[1]);
	col = atoi(argv[2]);
	max_cost = atoi(argv[3]);
	
	srand(time(NULL));
	
	for (r=0;r<row;r++) {
		for (c=0;c<col-1;c++) {
			printf("%f,",(float)rand()/((float)RAND_MAX/max_cost) );
		}
		printf("%f\n",(float)rand()/((float)RAND_MAX/max_cost));
	}
}