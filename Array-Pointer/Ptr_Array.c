#include<stdio.h>

int main()
{
    double arr1[5]={15.0,25.5,45.3,33.7,12.4};
    double *ptr=arr1;
    for(int i=0;i<5;i++){
        printf("arr[%d]=%lf\t",i,arr1[i]);
        printf("*(arr+%d)=%lf\t",i,*(arr1+i));        
        printf("*(ptr+%d)=%lf\n",i,*(ptr+i));
    }

    int arr2[3][4];
    printf("arr2:%#p\n",arr2);
    printf("arr2+1:%#p\n",arr2+1);

    int n=1;
    int arr[3][4]={
        1,2,3,4,
        2,3,4,5,
        3,4,5,6
    };
    //scanf("%d",&n);
    //printf("arr[0][0]=%d\n",**arr);
    printf("&arr[%d][0]:%#p\n",n,&arr[n][0]);
    printf("arr[%d]:%#p\n",n,arr[n]);
    printf("*(arr+%d):%#p\n",n,*(arr+n));
    printf("**(arr+%d)=%d\n",n,**(arr+n));

    int i=1,j=3;
    printf("arr[%d][%d]=%d\n",i,j,arr[i][j]);
    printf("*(*(arr+%d)+%d)=%d\n",i,j,*(*(arr+i)+j));
    
    return 0;
}