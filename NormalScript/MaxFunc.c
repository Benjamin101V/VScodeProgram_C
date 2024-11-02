#include<stdio.h>

int max(int x,int y)
{
    int n;
    (x>y)?(n=x):(n=y);
    return n;
}

int main()
{
    int a,b;
    scanf("%d %d",&a,&b);
    int r=max(a,b);
    printf("%d",r);

    return 0;
}