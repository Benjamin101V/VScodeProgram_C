#include<stdio.h>

const int daysInMonth[]={31,28,31,30,31,30,31,31,30,31,30,31};

int main()
{
    int day,mon,year;
    printf("\nPlease input the detail date(year,month,day) to count\n");
    if(scanf("%d,%d,%d",&year,&mon,&day)!=3 || mon<1 || mon>12 ||day<1 || day>31 || (!(year%4==0 && year%100!=0 || year%400==0) && mon==2 && day>28)){
        printf("Invalid Data\n");
        return 1;
    }
    int sum=0;
    for(int i=0;i<mon-1;i++){
        sum+=daysInMonth[i];
    }
    sum+=day;

    int leap=(year%4==0 && year%100!=0 || year%400==0);
    if(leap && mon>2){
        sum++;
    }
    printf("Sum of the day is %d\n",sum);

    return 0;
}