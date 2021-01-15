#include<stdio.h>
#include<string.h>

int main (int argc, char *argv[]){
    for(int j=1; j<27; j++){
	for(int i=0; i<strlen(argv[1]); i++){
	    if(argv[1][i] == 32){
		printf(" ");
	    } else if(argv[1][i]+j > 122) {
		int tmp = argv[1][i]+j - 122;
		printf("%c", (char)96+tmp);
	    } else {
		printf("%c", (char)argv[1][i]+j);
	    }
	}
	printf("\n");
    }
    return 0;
}
