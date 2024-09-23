#include<stdio.h>

double getAverage(int *arr,int size)
{
    int i,sum=0;
    double avg;
    for(i=0;i<size;i++){
        sum+=arr[i];
    }
    avg=(double)sum/size;
    return avg;
}

int main()
 {
    int sz=5;
    int balance[sz];
    int i;
    for(i=0;i<sz;i++){
        scanf("%d",&balance[i]);
    }
    double avg=getAverage(balance,sz);
    printf("%lf",avg);

    return 0;
}