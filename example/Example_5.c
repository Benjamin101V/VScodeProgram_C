#include<stdio.h>
/*输入三个整数 x、y、z，请把这三个数由小到大输出*/
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

int main()
{
    int x,y,z;
    scanf("%d%d%d",&x,&y,&z);
    if(x>y){
        swap(&x,&y);
    }
    if(x>z){
        swap(&x,&z);
    }
    if(y>z){
        swap(&y,&z);
    }
    printf("%d %d %d\n",x,y,z);

    return 0;
}