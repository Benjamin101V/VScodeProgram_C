#include<stdio.h>
#include<time.h>
#include<stdlib.h>

const int MAX=10;

int *getRand()
{
    static int r[10];
    int i=0;

    srand((unsigned)time(NULL));
    for(;i<MAX;i++){
        r[i]=rand()%30+1;
        printf("%d\n",r[i]);
    }
    return r;          //从函数返回指针
}

int main()
{
    int *p;
    p=getRand();
    for(int i=0;i<MAX;i++){
        printf("*(p+%d):%d\n",i,*(p+i));
    }

    return 0;
}