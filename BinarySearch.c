#include<stdio.h>

int main()
{
    int arr[]={1,2,3,4,5,6,7,8,9,10};
    int num;
    scanf("%d",&num);
    int sz=sizeof(arr)/sizeof(arr[0]);
    int left=0;
    int right=sz-1;
    while(left<=right){
        int mid=left+(right-left)/2;
        if(arr[mid]<num){
            left=mid+1;
        }
        else if(arr[mid]>num){
            right=mid-1;
        }
        else{
            printf("Get it!\n");
            printf("%d",arr[mid]);
            break;
        }
        if(left>right){
            printf("False\n");
        }
    }


    return 0;
}