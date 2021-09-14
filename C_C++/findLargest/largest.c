#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int main(int argc, char **argv) {
    if(argc > 1) {
	int largest = INT_MIN;
	for (int i = 1 ; i < argc ; i++) {
	    int num = atoi(argv[i]);
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
