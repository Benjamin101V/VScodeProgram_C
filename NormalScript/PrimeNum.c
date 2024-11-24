#include<stdio.h>
#include<math.h>

int main()
{
    int a,b;
    while(scanf("%d %d",&a,&b)!=EOF){
        for(;a<=b;a++){
            int flag=1;
            int i;

            for(i=2;i<sqrt(a)+1;i++){  //2为最小的素数，故从2开始循环
                if(a%i==0){          //从0开始会出现算法错误，无法除以0
                    flag=0;
                    break;
                }
            }
            if(flag==1){
                printf("%d ",a);
            }
        }
    }

    return 0;
}