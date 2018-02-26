#include <stdio.h>
#include <stdlib.h>
#include <malloc.h> 

#define SIZE  100  
#define  INCREMENT_SIZE 10  


 typedef struct LNode
 {
	int data; 	 
 	  LNode *next;
 }LNode,*LinkList;/*单链表的定义*/ 
 
 
Status InitList(LinkList &L)
{
	L=new LNode;
	L->next=NULL;
	return OK;
 }/* 单链表的初始化*/ 
 
 Status GetElem(LinkList L,int i,ElemType &e)
{
	p=L->next;j=1;
	while(p&&j<1)
   {
   	p=p->next;
     ++j;		
   }	
	if(!p||j>i)return ERROR;
	e=p->data;
	return OK;
}/*单链表的取值*/ 

LNode *LocateElem(LinkList L, ElemType e)
{
	p=L->next;
	while(p && p->data!=e)
		p=p->next; 
	return p;
}/*单链表的查找*/ 

Status ListDelete(LinkList &L,int i)
{
	p=L;j=0;
	while((p->next) && (j<i-1))
	{p=p->next; ++j;}
	if(!(p->next)||(j>i-1))
	q=p->next;
	p->next=q->next;
	delete q;
	return OK;  
	
}/*单链表的删除*/ 
int main(){
 int i;
 Node *pHead=NULL;
 InitList(LinkList &L);
 pHead=create(pHead);
 printList(pHead);
 printf("输入插入节点位置\n");
 scanf("%d",&i);
 insert_data(&pHead,i);
 printList(pHead);
 printf("输入删除节点位置\n");
 scanf("%d",&i);
 delete_data(&pHead,i);
 printList(pHead);
 printf("输入查找节点\n");
 scanf("%d",&i);
 printf("节点所在位置：%d",search_data(pHead,i));
 return 0;
}


