#include <stdio.h>
#include <stdlib.h>
#include <malloc.h> 

#define SIZE  100  
#define  INCREMENT_SIZE 10  


 typedef struct LNode
 {
	int data; 	 
 	  LNode *next;
 }LNode,*LinkList;/*������Ķ���*/ 
 
 
Status InitList(LinkList &L)
{
	L=new LNode;
	L->next=NULL;
	return OK;
 }/* ������ĳ�ʼ��*/ 
 
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
}/*�������ȡֵ*/ 

LNode *LocateElem(LinkList L, ElemType e)
{
	p=L->next;
	while(p && p->data!=e)
		p=p->next; 
	return p;
}/*������Ĳ���*/ 

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
	
}/*�������ɾ��*/ 
int main(){
 int i;
 Node *pHead=NULL;
 InitList(LinkList &L);
 pHead=create(pHead);
 printList(pHead);
 printf("�������ڵ�λ��\n");
 scanf("%d",&i);
 insert_data(&pHead,i);
 printList(pHead);
 printf("����ɾ���ڵ�λ��\n");
 scanf("%d",&i);
 delete_data(&pHead,i);
 printList(pHead);
 printf("������ҽڵ�\n");
 scanf("%d",&i);
 printf("�ڵ�����λ�ã�%d",search_data(pHead,i));
 return 0;
}


