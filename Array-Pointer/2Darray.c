#include<stdio.h>

int main()
{
    int arr[3][4]; //声明一个3行4列的整型二维数组
    /*遍历输入*/
    int temp=101;
    for(int i=0;i<3;i++){ //行数
        
        for(int j=0;j<4;j++){ //列数
            arr[i][j]=temp+j;
            //scanf("%d",&arr[i][j]);
        }
        temp++;
    }
    /*遍历输出*/
    for(int i=0;i<3;i++){
        
        for(int j=0;j<4;j++){
            printf("arr[%d][%d]=%d\t",i,j,arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}