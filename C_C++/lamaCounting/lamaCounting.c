#include<stdio.h>

int years, startCount, endCount = 0;
void wantPrompt();
void killLlamas();
void keepLlamas();
int countYears(int start, int end);

int main() {

    welcomeMenu();

    if(endCount<startCount){
	killLlamas();
    } else if(endCount==startCount){
	keepLlamas();
    } else {
	years=countYears(startCount, endCount);
    }

    return 0;
}

void welcomeMenu(){
    printf("hello rugged shepherd! i will count the years you need to raise your llama");
    printf("how many llamas do you have? ");
    scanf("%d", &startCount);
    printf("how many llamas do you want? ");
    scanf("%d", &endCount);
}
void wantPrompt(){
    printf("\nyou want %d llamas", endCount);
}
void killLlamas(){
    wantPrompt();
    printf("\ngo kill/sell %d llamas.", startCount-endCount);
    printf("\nif you're quick, you need only 1 day!☠️\n");
}
void keepLlamas(){
    wantPrompt();
    printf("you already reached your target");
}
