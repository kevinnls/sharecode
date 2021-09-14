#include<stdio.h>
#include<stdlib.h>

int main(int argc, char **argv) {
    if(argc > 1) {
	int aggLarge = 0;
	for (int i = 0 ; i < argc-1 ; i++) {
	    int num = atoi(argv[i+1]);
	    if ( num > aggLarge ) {
		aggLarge = num;
	    }
	}
	printf("%d\n", aggLarge);
	return 0;
    } else {
	fprintf(stderr, "ERR: no arguments provided\n");
	return 1;
    }
}
