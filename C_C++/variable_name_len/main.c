#include<stdio.h>
#include<string.h>

// tested with gcc
//
// ........found out only later gcc doesn't have a limit on
// identifier length

int main(){

    char* var31 = "_abcdefghijklmnopqrstuvwxyz0123";
    char* var32 = "_abcdefghijklmnopqrstuvwxyz01234";
    char* var33 = "_abcdefghijklmonpqrstuvwxyz012345";
    int _abcdefghijklmnopqrstuvwxyz012345 = 100;
    int _abcdefghijklmnopqrstuvwxyz01234 = 1000;
    int _abcdefghijklmnopqrstuvwxyz0123 = 10000;

    printf("var31: len: %d\n", strlen(var31));
    printf("\t%d\n", _abcdefghijklmnopqrstuvwxyz0123);
    printf("var32: len: %d\n", strlen(var32));
    printf("\t%d\n", _abcdefghijklmnopqrstuvwxyz01234);
    printf("var33: len: %d\n", strlen(var33));
    printf("\t%d\n", _abcdefghijklmnopqrstuvwxyz012345);
    return 0;
}
