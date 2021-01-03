#include<stdio.h>

int startCount, endCount = 0;
void killLlamas();

int main() {
    printf("how many llamas do you have? ");
    scanf("%d", &startCount);
    printf("how many llamas do you want? ");
    scanf("%d", &endCount);

    if(endCount<startCount){
	killLlamas();
    }
    return 0;
}

void killLlamas(){
    printf("\nyou want %d llamas", endCount);
    printf("\ngo kill/sell %d llamas.", startCount-endCount);
    printf("\nif you're quick, you need only 1 day!☠️\n");
}

