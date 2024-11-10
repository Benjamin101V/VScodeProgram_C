#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void swap(int *a,int *b)
{
    *a=*a ^ *b;
    *b=*a ^ *b;   //异或运算交换两数的值
    *a=*a ^ *b;
}

void bubble_sort(int arr[],int len)
{   /*冒泡排序*/
    for(int i=0;i<len-1;i++){
        for(int j=0;j<len-1;j++){
            if(arr[j]>arr[j+1]){
                swap(&arr[j],&arr[j+1]);
            }
        }
    }
}

double getAverage(int arr[],int len)
{
    double sum;
    for(int i=0;i<len;i++){
        sum+=arr[i];
    }

    return sum/len;
}

int *getRandom()
{
    static int r[5];
    srand((unsigned int)time(NULL));
    for(int i=0;i<5;i++){
        r[i]=rand()%100;
        printf("r[%d]=%d\n",i,r[i]);
    }
    printf("\n");

    return r;
}

int main()
{
    int arr[10]={101,104,31,354,6,78,12,65,99,343};
    int length=sizeof(arr)/sizeof(arr[0]);
    bubble_sort(arr,length);
    for(int i=0;i<length;i++){
        printf("arr[%d]=%d\n",i,arr[i]);
    }
    printf("%.3lf\n",getAverage(&arr[0],length));
    
    int *ptr=getRandom();
    for(int i=0;i<5;i++){
        printf("r[%d]=*(p+%d)=%d\n",i,i,*(ptr+i));
    }

    return 0;
}