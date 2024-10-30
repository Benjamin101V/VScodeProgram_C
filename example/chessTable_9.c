#include<stdio.h>
/*要求输出国际象棋棋盘,由64个黑白相间的格子组成，分为8行*8列*/
int main()
{
    int i,j;
    for(i=0;i<8;i++){
        for(j=0;j<8;j++){
            if((i+j)%2==0){
                printf("%c%c",219,219); //终端必须要有ASCII字符支持
            }else{
                printf("  ");
            }
        }
        printf("\n");
    }

    return 0;
}