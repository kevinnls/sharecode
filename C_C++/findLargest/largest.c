#include<stdio.h>

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
  int *arr;
  printf("%d",argc);
  return 0;
 integeriseArgv(argc, argv, arr);
  for(int i = 0; i < argc; i++)
  printf("%d\n", arr[i]);
  return 0;
}