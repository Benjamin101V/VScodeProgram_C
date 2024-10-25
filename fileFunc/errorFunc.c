#include<stdio.h>
#include<errno.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    FILE *fp=NULL;
    int errnum;
    char fileName[125];
    //char input[125];
    gets(fileName);
    fp=fopen(fileName,"r");
    if(fp==NULL){
        errnum=errno;
        fprintf(stderr, "错误号: %d\n", errno);
        perror("通过 perror 输出错误");
        fprintf(stderr, "打开文件错误: %s\n", strerror( errnum ));
    }
    else{
        //scanf("%s\n",input);
        //fputs(input,fp);
        char string[125];
        fgets(string,125,(FILE*)fp);
        printf("%s\n",string);
        fclose(fp);
    }

    double dividend;
    double divisor;
    scanf("%lf%lf",&dividend,&divisor);
    if(divisor==0){
        fprintf(stderr,"Arithmetic exception!\n");
        exit(EXIT_FAILURE);
    }
    double quotient=dividend/divisor;
    fprintf(stderr,"quotient = %.3lf\n",quotient);
    exit(EXIT_SUCCESS);

    return 0;
}