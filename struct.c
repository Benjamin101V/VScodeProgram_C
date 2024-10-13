#include<stdio.h>
#include<string.h>

struct books    //结构体定义
{
    char title[50];
    char author[50];
    char subject[50];
    int bookID;     /*定义时初始化*/
}book1={"The C Programming Language","BW.K DM.R","Programming Language",19700101};

void bookInfo(struct books book,int n)    //结构体作为函数参数
{
    printf( "Book%d title : %s\n", n,book.title);
    printf( "Book%d author : %s\n", n,book.author);
    printf( "Book%d subject : %s\n", n,book.subject);
    printf( "Book%d bookID : %d\n", n,book.bookID);    
}

void bookInfo_ptr(struct books *book,int n)    //结构体指针作为函数参数
{
    printf( "Book%d title : %s\n", n,book->title);
    printf( "Book%d author : %s\n", n,book->author);    //使用结构体成员访问操作符（->）访问结构体成员
    printf( "Book%d subject : %s\n", n,book->subject);
    printf( "Book%d bookID : %d\n", n,book->bookID);
    
}

union Data  //定义共用体
{
    int i;  /*共用体是一种特殊的数据类型，允许您在相同的内存位置存储不同的数据类型*/
    float j;
    char string[25];
};

int main()
{
    printf("Book1 title: %s\nBook1 author: %s\nBook1 subject: %s\nBook1 bookID: %d\n",book1.title,book1.author,book1.subject,book1.bookID);

    struct books book2={"CTFer","NU1L","Security",19700102}; //声明book2，类型为books，并直接初始化
    /*strcpy( book2.title, "CTFer");
    strcpy( book2.author, "NU1L");
    strcpy( book2.subject, "Security");    //使用字符串函数初始化
    book2.bookID = 19700102;*/
    printf( "Book2 title : %s\n", book2.title);
    printf( "Book2 author : %s\n", book2.author);  //使用结构体访问操作符（.）访问结构体成员
    printf( "Book2 subject : %s\n", book2.subject);
    printf( "Book2 bookID : %d\n", book2.bookID);

    struct books book3;
    strcpy( book3.title, "CTF实战");
    strcpy( book3.author, "安恒信息");
    strcpy( book3.subject, "Security");
    book3.bookID = 19700103;
    bookInfo(book3,3);    //调用函数

    struct books book4;
    strcpy( book4.title, "线上幽灵");
    strcpy( book4.author, "K.W");
    strcpy( book4.subject, "Security");
    book3.bookID = 19700104;
    bookInfo_ptr(&book4,4);   //调用函数，参数为结构体指针（地址）

    int ret1=sizeof(book1);
    int ret2=sizeof(book2);     //计算结构体大小
    int ret3=sizeof(book3);
    int ret4=sizeof(book4);
    printf("结构体 book1 大小为: %zu 字节\n", ret1);
    printf("结构体 book2 大小为: %zu 字节\n", ret2);
    printf("结构体 book3 大小为: %zu 字节\n", ret3);
    printf("结构体 book4 大小为: %zu 字节\n", ret4);
    struct books book5;
    printf("结构体 book5 大小为: %zu 字节\n", sizeof(book5));
    /*结构体的大小可能会受到编译器的优化和对齐规则的影响，编译器可能会在结构体中插入一些额外的填充字节以对齐结构体的成员变量，以提高内存访问效率。因此，结构体的实际大小可能会大于成员变量大小的总和*/
    /*因此book5的大小比正常情况大两个字节*/

    union Data data;
    data.i=5;
    data.j=0.25;
    strcpy(data.string,"VIRTUALGUARD");
    printf( "data.i : %d\n", data.i);   
    printf( "data.j : %f\n", data.j);   
    printf( "data.str : %s\n", data.string);
    /*使用共用体时可以定义一个带有多成员的共用体，但是任何时候只能有一个成员带有值*/
    /*因此上面的代码在编译并执行后可以看到共用体的 i 和 j 成员的值有损坏，因为最后赋给变量的值占用了内存位置，这也是 string 成员能够完好输出的原因*/

    data.i=5;
    printf( "data.i : %d\n", data.i);   
    data.j=0.25;
    printf( "data.j : %.2f\n", data.j);   
    strcpy( data.string, "VIRTUALGUARD");
    printf( "data.str : %s\n", data.string);
    /*这次我们在同一时间只使用一个变量，这也演示了使用共用体的主要目的*/
    /*以上代码在编译并执行后所有的成员都能完好输出，因为同一时间只用到一个成员*/

    return 0;
}