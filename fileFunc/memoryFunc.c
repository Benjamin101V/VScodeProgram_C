#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    char string[101];
    char *pstring;
    strcpy(string,"VIRTUAGUARD");    
    pstring=(char *)malloc(200 * sizeof(char)); /*动态内存分配*/
    if(pstring==NULL){
        fprintf(stderr,"Error:%d - Unable to allocate required memory\n",errno);
        exit(EXIT_FAILURE);
    }else{
        strcpy(pstring,"Computer Science is fun!\n");
    }
    printf("%s\n",string);
    printf("%s\n",pstring);
    free(pstring);  /*使用free()释放内存*/

    char *description;
    description=(char *)malloc(35 * sizeof(char));
    if(description==NULL){
        fprintf(stderr,"Error:%d - Unable to allocate required memory\n",errno);
        exit(EXIT_FAILURE);
    }else{
        strcpy(description,"Information Security is also fun!\n");
    }
//    printf("%s\n",description);
    description=(char *)realloc(description,200 * sizeof(char));
    if(description==NULL){
        fprintf(stderr,"Error:%d - Unable to allocate required memory\n",errno);
        exit(EXIT_FAILURE);
    }else{
        strcat(description,"However,I think Information Security is more funny than basic Computer Science.\n");
    }
    printf("%s\n",description);
    free(description);

    return 0;
}