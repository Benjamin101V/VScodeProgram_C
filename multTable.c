#include<stdio.h>

int main()
{
    int r,l;

    for(r=1;r<=9;r++){
        for(l=1;l<=r;l++){

            printf("%d*%d=%d\t",r,l,r*l);
        }
        printf("\n");
    }

    return 0;
}