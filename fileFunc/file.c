#include<stdio.h>
#include<winsock2.h>

int main()
{
    FILE *fp=NULL;
    fp=fopen("E:/VScodeProgram/LearningCode/C/fileFunc/test1.txt","w+");
    fprintf(fp,"This is testing for fprintf...\n");
    fputs("This is testing for fprintf...\n",fp);
    fclose(fp);
    /*mode（访问模式）：w（重新写入），r（读取），a（追加写入），w+（重新读写），r+（读写），a+（从头读取，追加写入）*/

    FILE *fp1=NULL;
    char string[101];
    fp1=fopen("E:/VScodeProgram/LearningCode/C/fileFunc/test2.txt","r");
    fscanf(fp1,"%s",string);
    printf("1.%s\n",string);
    fgets(string,101,(FILE*)fp1);
    printf("2.%s\n",string);
    fgets(string,101,(FILE*)fp1);
    printf("3.%s\n",string);
    fclose(fp1);
    /*fscanf() 方法只读取了 This，因为它在后边遇到了一个空格。其次，调用 fgets() 读取剩余的部分，直到行尾。最后，调用 fgets() 完整地读取第二行*/

    /*size_t fread(void *ptr, size_t size_of_elements, size_t number_of_elements, FILE *a_file);
              
    size_t fwrite(const void *ptr, size_t size_of_elements, size_t number_of_elements, FILE *a_file);*/
    //这两个函数用于二进制输入和输出
    return 0;
}