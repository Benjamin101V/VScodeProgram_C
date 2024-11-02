#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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

void selection_sort(int arr[],int len)
{   /*选择排序*/
    for(int i=0;i<len-1;i++){
        int min=i;  //定义变量min为最小下标，默认为第一个元素
        for(int j=i+1;j<len;j++){
            if(arr[j]<arr[min]){
                min=j;  //更新最小元素下标
            }
        }
        if(min!=i){
            swap(&arr[min],&arr[i]);
        }
    }
}

void insertion_sort(int arr[],int len)
{   /*插入排序*/
    for(int i=1;i<len;i++){
        int temp=arr[i];    //待插入元素
        int j=i;
        while(j>0 && arr[j-1]>temp){
            arr[j]=arr[j-1];    //右移大于temp的元素
            j--;
        }
        arr[j]=temp;
    }
}

void shell_sort(int arr[],int len)
{   /*希尔排序*/
    for(int gap=len-2;gap>0;gap/=2){    //计算初始间隔
        for(int i=gap;i<len;i++){//对每个间隔进行插入排序
            int temp=arr[i];    //待插入元素
            int j=i;
            while(j>=gap && arr[j-gap]>temp){
                arr[j]=arr[j-gap];  //移动大于temp的元素
                j-=gap;
            }
            arr[j]=temp;    //插入元素到正确位置
        }
    }
}

int min(int x,int y)
{
    return x<y?x:y;
}

void merge_sort(int arr[],int len)
{   /*归并排序*/
    int *a=arr;
    int *p=(int *)malloc(len*sizeof(int));
    if(p==NULL){
        fprintf(stderr,"Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    for(int seg=1;seg<len;seg+=seg){
        for(int start=0;start<len;start+=seg+seg){
            int low=start;
            int mid=min(start+seg,len);
            int high=min(start+seg+seg,len);
            int k=low;
            int start1=low,end1=mid;
            int start2=mid,end2=high;
            while(start1<end1 && start2<end2){
                p[k++]=a[start1]<a[start2]?a[start1++]:a[start2++];
            }
            while(start1<end1){
                p[k++]=a[start1++];
            }
            while(start2<end2){
                p[k++]=a[start2++];
            }
        }
        int *temp=a;
        a=p;
        p=temp;
    }
    if(a!=arr){
        for(int i=0;i<len;i++){
            p[i]=a[i];
        }
        p=a;
    }
    free(p);
}

int main()
{
    int arr1[]={22,34,3,32,82,55,89,50,37,5,64,35,9,70};
    int len1=sizeof(arr1)/sizeof(arr1[0]);
    bubble_sort(arr1,len1);
    for(int i=0;i<len1;i++){
        printf("%d ",arr1[i]);
    }
    printf("\n");

    int arr2[]={12,4,5,65,23,45,90,56,78,43,7,22,33,50,101};
    int len2=sizeof(arr2)/sizeof(arr2[0]);
    selection_sort(arr2,len2);
    for(int i=0;i<len2;i++){
        printf("%d ",arr2[i]);
    }
    printf("\n");

    int arr3[]={1,3,78,45,67,97,23,45,70,47,101,98,77,95,105};
    int len3=sizeof(arr3)/sizeof(arr3[0]);
    insertion_sort(arr3,len3);
    for(int i=0;i<len3;i++){
        printf("%d ",arr3[i]);
    }
    printf("\n");

    int arr4[]={1,34,65,778,90,13,11,33,22,56,99,76,88,79,14,48,98};
    int len4=sizeof(arr4)/sizeof(arr4[0]);
    shell_sort(arr4,len4);
    for(int i=0;i<len4;i++){
        printf("%d ",arr4[i]);
    }
    printf("\n");

    int arr5[]={12,54,8,99,16,78,43,56,76,667,234,543,124,669,6547,2344,876};
    int len5=sizeof(arr5)/sizeof(arr5[0]);
    merge_sort(arr5,len5);
    for(int i=0;i<len5;i++){
        printf("%d ",arr5[i]);
    }
    printf("\n");

    return 0;
}