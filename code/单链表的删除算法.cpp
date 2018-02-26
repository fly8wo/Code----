#include<stdio.h>  
#include <malloc.h>  
#define SIZE  100  
#define  INCREMENT_SIZE 10  
typedef struct  LNode  
{  
   int data;  
   LNode *next;  
}LNode,*LinkList;  
  
//creat a LinkList  
bool creatLinklist(LinkList&L,int n)  
{  
    LinkList p,q,t,s;  
    L=(LNode*)malloc(n*sizeof(LNode));  
    if(!L)  
        return false;  
    L->next=NULL;  
    for(int i=n;i>0;i--)  
    {  
        p=(LNode*)malloc(sizeof(LNode));  
        scanf("%d",&p->data);  
        p->next=L->next;  
        L->next=p;  
    }  
    p=L->next;//The first Node  
    q=p->next;//The second Node  
    p->next=NULL;   
    while(q)  
    {  
        t=q->next;// keep the third Node  
        q->next=p;// the second Node points to the first Node in a loop  
        p=q;      //p points to next Node  
        q=t;      //q points to next Node  
    }  
    L->next=p;    //set head Node  
    return true;  
}  
//delete a Node  
bool LinklistDelete(LinkList&L,int i,int &e)  
{  
    LinkList p,q;  
    int j=0;  
    p=L->next;  
    while(p)  
    {  
        j++;  
        if(j<i-1)  
            p=p->next;  
        else  
            break;  
    }  
    if(j>i-1||!p)  
        return false;  
    q=p->next;  
    p->next=q->next;  
    e=q->data;  
    free(q);  
    return true;  
}  
int main()  
{  
    LinkList Llist,p;  
    int k;  
    int elemet;  
    int position;  
    printf("input the number of LinkList to be created:");  
    scanf("%d",&k);  
    creatLinklist(Llist,k);  
    printf("\n");  
    printf("input the position to delete in LinkList:");  
    scanf("%d",&position);  
    printf("\n");  
    LinklistDelete(Llist,position,elemet);  
    printf("output the deleted data of Node:%d\n",elemet);  
    printf("\n");  
    printf("output the new LinkList:\n");  
    p=Llist->next;  
    while(p)  
    {  
        printf("%d ",p->data);  
        p=p->next;  
    }  
    printf("\n");  
    free(Llist);  
}  
