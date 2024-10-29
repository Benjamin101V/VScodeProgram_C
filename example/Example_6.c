#include<stdio.h>
/*用*号输出字母C的图案*/
int main()
{   /*方案<1>*/
    printf("*******\n");
    printf("*\n");
    printf("*\n");
    printf("*******\n");

    /*方案<2>*/
    const char *c_pattern[] = {
        "*******",
        "*",
        "*",
        "*******"
    };
    // 输出字符图形
    for (int i = 0; i < sizeof(c_pattern) / sizeof(c_pattern[0]); i++) {
        printf("%s\n", c_pattern[i]);
    }

    return 0;
}