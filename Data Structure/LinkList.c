#include<stdio.h>
#include<stdlib.h>

#define LEN sizeof(Nodes)

typedef int ElemType1;
typedef double ElemType2;

typedef struct Nodes
{
    ElemType2 score;
    ElemType1 id;
    struct Node *next;
}Node;

typedef Node *LinkList;
typedef int Status;

int main()
{
    Node student1,student2,student3;
    student1.id=101;student1.score=95.5;
    student2.id=102;student2.score=85.3;
    student3.id=103;student3.score=100;

    Node *ptr;
    ptr=&student1;
    student1.next=&student2;
    student2.next=&student3;
    student3.next=NULL;

    do{
        printf("S_ID:%d\tS_Score:%.3lf\n",ptr->id,ptr->score);
        ptr=ptr->next;

    }while(ptr!=NULL);

    return 0;
}