#include<stdio.h>
#include<stdlib.h>

int main(int argc, char **argv) {
    if(argc > 1) {
	int largest = 0;
	for (int i = 0 ; i < argc-1 ; i++) {
	    int num = atoi(argv[i+1]);
	    if ( num > largest ) {
		largest = num;
	    }
	}
	printf("%d\n", largest);
	return 0;
    } else {
	fprintf(stderr, "ERR: no arguments provided\n");
	return 1;
    }
}
