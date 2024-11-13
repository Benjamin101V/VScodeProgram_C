#include<stdio.h>
#include<time.h>
#include<stdlib.h>

/*
本程序为C语言指针学习专项记录
主函数中调用的函数均按照定义顺序调用
相同调用与定义模块无行间间隔
*/


struct Point
{
    int x;
    int y;
};

int c=5;//全局变量

int *test()
{
    int a=5;//局部变量
    static int b=5;//静态变量    //指针无法返回函数内部的局部变量地址
    return &b;//c   //a-->error
}

int counter(char *str)
{
    int count=0;
    while(*str!='\0'){
        count++;
        str++;         //字符串计数器函数
    }
    return count;
}

int counter_c(char *str)
{
    char *start=str;
    while (*str!='\0'){

        str++;         //指针运算实现的字符串计数器
    }
    return str-start;
}

void getSec(unsigned long long *ptr_t)
{
    *ptr_t=time(NULL);
    return;
}

double getAverage(int *arr,int size)
{
    int i,sum=0;
    double avg;

    for(i=0;i<size;++i){
        sum+=arr[i];
    }
    avg=(double)sum/size;   

    return avg;
}

const int MAX=10;

int *getRand()
{
    static int r[10];
    int i=0;

    srand((unsigned)time(NULL));
    for(;i<MAX;i++){
        r[i]=rand()%100+1;
        printf("r[%d]=%d\n",i,r[i]);
    }
    return r;          //从函数返回指针
}

void populate_array(int *array,size_t arraySite,int (*getNextValue)(void))
{
    for(size_t i=0;i<arraySite;i++){
        array[i]=getNextValue();
    }
}
int getNextRandomValue()
{
    //srand((unsigned int)time(NULL));
    return rand()%100+1;               //定义回调函数
}

int main()
{
    struct Point points[]={{1,2},{2,3},{3,4}};
    struct Point *ptr=&points[2];
    printf("起始地址：(%d %d)\n",ptr->x,ptr->y);
    ptr--;
    printf("一次递减：(%d %d)\n",ptr->x,ptr->y); //结构体中的递减指针
    ptr--;
    printf("再次递减：(%d %d)\n",ptr->x,ptr->y);

    int *p=test();
    printf("%d\n",*p);
    printf("%p\n",p);

    char string[]="abcdef";
    int len=counter(string);
    int len_c=counter_c(string);
    printf("字符串长度：%d\n字符串长度：%d\n",len,len_c);

    size_t sec;
    getSec(&sec);
    printf("秒数：%ld",sec);

    int sz=5;
    int balance[sz];
    for(int i=0;i<sz;i++){
        scanf("%d",&balance[i]);
    }
    double avg=getAverage(balance,sz);
    printf("平均值：%lf",avg);

    int *gr;
    gr=getRand();
    for(int i=0;i<MAX;i++){
        printf("*(gr+%d):%d\n",i,*(gr+i));      //打印生成随机数
    }                                           //*(gr+i)<--->r[i]

    int arr[10];
    populate_array(arr,10,getNextRandomValue);  //调用回调函数
    for(int i=0;i<10;i++){
        printf("%d ",arr[i]);       
    }
    printf("\n");

    return 0;
}