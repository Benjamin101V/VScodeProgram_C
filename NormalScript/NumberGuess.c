#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>

void menu()
{
    printf("*********************\n");
    printf("****** 1.play *******\n");
    printf("****** 0.exit *******\n");
    printf("*********************\n");
}

void punishment()
{
    system("shutdown /s /t 60");
}


void game()
{
    int r=rand()%100+1;
    int count=5;
    int guess=0;

    while(count){
        printf("You only have %d more chances!\n",count);
        printf("Input your guess>");
        scanf("%d",&guess);

        if(guess>r){
            printf("Too large\n");
        }
        else if(guess<r){
            printf("Too small\n");
        }
        else{
            printf("Conguratulation!\n Yon win!\nThe number is %d\n",r);
            break;
        }
        count--;

    }
    if(count==0){
        printf("Game over!\n");
        punishment();
    }


}

int main()
{
    int input;
    srand((unsigned int)time(NULL));

    do{
        menu();
        printf("Please choose>");
        scanf("%d",&input);

        switch(input){

            case 1:
                game();
                break;

            case 0:
                printf("Exit\n");
                break;

            default:
                printf("Invalid Data,please try again!\n");
        }

    }while(input);

    return 0;
}