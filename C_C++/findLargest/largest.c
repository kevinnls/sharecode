#include<stdio.h>
#include<stdlib.h>

void printIntArray(int *arr);
void printCharArray(char **arr);

int findLargest (int *arr) {
    int aggLarge;
    for (int i = 0 ; i < sizeof(arr) ; i++) {
	if( arr[i] > arr[i+1]) {
	    aggLarge = arr[i];
	} else {
	    aggLarge = arr[i+1];
	}
    }
    return aggLarge;
}
void integeriseArgv (int len, char **argv, int *memloc) {
    for(int i=0; i < len-1; i++){
	memloc[i] = atoi(argv[i+1]);
    }
    return;
}
int main(int argc, char **argv) {
    if(argc > 1) {
	int *arr;
	integeriseArgv(argc, argv, arr);
	//findlargest(arr)
	return 0;
    } else {
	fprintf(stderr, "ERR: no arguments provided\n");
	return 1;
    }
}

void printIntArray(int *arr){
    int len = sizeof(arr);
    for (int i=0; i<len; i++){
	printf("%d", arr[i]);
    }
}
void printCharArray(char **arr){
    int len = sizeof(arr);
    for (int i=0; i<len; i++){
	printf("%s", arr[i]);
    }
}
