#include<stdio.h>
/*数组与指针专题学习*/
#define LENGTH(array) sizeof(array)/sizeof(array[0])    //宏定义计算数组长度

void printArray(int arr[],int size) //数组（指针）作为参数
{
    for(int i=0;i<size;i++){
        printf("arr1[%d]=%d\n",i,arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr1[5];    //数组定义
    int len=sizeof(arr1)/sizeof(arr1[0]);   //数组长度（元素个数）计算
    int length=LENGTH(arr1);    //宏定义
    printf("Length of arr1=%d\n",len);
    printf("Length of arr1=%d\n",length);
    printf("\n");

    for(int i=0;i<5;i++){
        arr1[i]=101+i;  //初始化数组元素
    }
    for(int i=0;i<5;i++){
        printf("arr1[%d]=%d\n",i,arr1[i]);   //遍历打印
    }
    printf("\n");

    printArray(arr1,len);

    return 0;
}