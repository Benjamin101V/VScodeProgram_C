#include<stdio.h>
/*古典问题（兔子生崽）：有一对兔子，从出生后第3个月起每个月都生一对兔子，小兔子长到第三个月后每个月又生一对兔子，假如兔子都不死，问每个月的兔子总数为多少？（输出前40个月即可）*/
int fibonaci(int n)
{
    if(n==1){
        return 1;
    }else if(n==2){
        return 1;
    }else{
        return fibonaci(n-1)+fibonaci(n-2);
    }

}

int main()
{   /*累加法*/
    int x=1,y=1,temp;
    printf("%12d%12d\n",x,y);
    for(int i=3;i<=40;i+=2){
        temp=x+y;
        printf("%12d",temp);
        x=y;
        y=temp;
        temp=x+y;
        printf("%12d\n",temp);
        x=y;
        y=temp;
    }

    /*递归法*/
    printf("%12d%12d\n",fibonaci(1),fibonaci(2));
    for(int i=3;i<=40;i++){
        printf("%12d",fibonaci(i));
        if(i%2==0){
            printf("\n");
        }
    }

    return 0;
}