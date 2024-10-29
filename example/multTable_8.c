#include<stdio.h>
/*输出 9*9 口诀表*/
int main()
{
    int x,y;
    for(x=1;x<10;x++){
        for(y=1;y<=x;y++){
            printf("%d*%d=%d\t",x,y,x*y);
        }
        printf("\n");
    }

    return 0;
}