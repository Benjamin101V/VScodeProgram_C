#include<stdio.h>
    
int main()
{
    int i,j,k;

    for(i=1;i<5;i++){
        for(j=1;j<5;j++){
            for(k=1;j<5;j++){

                if(i!=j && j!=k && i!=k){
                    printf("%d %d %d\n",i,j,k);
                }
            }
        }
    }

    return 0;
}