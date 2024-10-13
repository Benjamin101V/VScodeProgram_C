#include<stdio.h>
#include<string.h>

/*C 中有大量操作字符串的函数
详情可参考 https://www.runoob.com/cprogramming/c-standard-library-string-h.html
下面所列举的字符串操作函数相对常见*/

int main()
{
	char str[8]={'V','I','R','T','U','A','L','\0'};
	char string1[]="VIRTUAL";
	printf("%s\n%s\n",str,string1);
	
	char string2[]="GUARD";
	char string3[8];
				//string1=str
	strcpy(string3,string1);	//复制粘贴 string1->string3
	printf("strcpy()->%s\n",string3);
	strcat(string3,string2);	//连接 string3-string2
	printf("strcat()->%s\n",string3);
	int len=strlen(string3);	//计算连接后string3的总长度
	printf("length of string3:%d\n",len);
	
	char passwd[]="VIRTUAL";
	char input1[25]="VIRTUAL";
	//scanf("%s",input1);
	if(strcmp(input1,passwd)==0){//比较字符串,相同返回0
		printf("Pass!\n");
	}
	else{
		int ret=strcmp(input1,passwd);
		printf("Error!\n");
		printf("return %d",ret);//不同，如果 input<passwd 则返回小于0；如果 input>passwd 则返回大于0
	}

	char string4[]="VIRTUALGUARD{}";
	char input2='{';
	//scanf("%c",input2);
	char *ptr1=strchr(string4,input2);//返回字符串string4中第一次出现字符input2的地址
	if(ptr1!=NULL){
		printf("First occurrence of '%c' found at position: %p\n",input2,ptr1-str);
	}
	else{
		printf("Character not found\n");
	}

	char string5[]="VIRTUALGUARD{}";
	char in[]="GUARD";
	char *ptr2=strstr(string5,in);
	if(ptr2!=NULL){
		printf("First occurrence of '%s' found at position: %p\n",in,ptr2-str);
	}
	else{
		printf("String not found\n");
	}

	char src[]="VIRTUALGUARD{}";
	char dest[25];
	memcpy(dest,src,strlen(src)+1);   //从src复制strlen(src)+1个字符到dest中（相当于函数void *memmove(void *dest,void *src size_t,strlen(scr)+1)）
	printf("Copied memory: %s\n", dest);
	
	return 0;
}