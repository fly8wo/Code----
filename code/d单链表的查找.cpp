
#include <stdio.h>
#include <malloc.h>
#include <string.h> /*����һЩ�ַ�����������ͷ�ļ�*/
#define N 10 
typedef struct node
{
��char name[20];
��struct node *link;
}stud;

stud * creat(int n) /*��������ĺ���*/
{
��stud *p,*h,*s;
��int i;
��if((h=(stud *)malloc(sizeof(stud)))==NULL)
��{
����printf("���ܷ����ڴ�ռ�!");
����exit(0);
��}
��h-��name[0]='\0';
��h-��link=NULL;
��p=h;
��for(i=0;i��n;i++)
��{
����if((s= (stud *) malloc(sizeof(stud)))==NULL)
����{
������printf("���ܷ����ڴ�ռ�!");
������exit(0);
����}
����p-��link=s;
����printf("�������%d���˵�����",i+1);
����scanf("%s",s-��name);
����s-��link=NULL;
����p=s;
��}
��return(h);
}

stud * search(stud *h,char *x) /*��������ĺ���������hָ��������ı�ͷָ�룬xָ����Ҫ���ҵ��˵�����*/
{
��stud *p; /*��ǰָ�룬ָ��Ҫ�������ҵ������ȽϵĽ��*/
��char *y; /*��������������������ָ��*/
��p=h-��link;
��while(p!=NULL)
��{
����y=p-��name;
����if(strcmp(y,x)==0) /*�������������������Ҫ���ҵ������Ƚϣ�����ͬ�򷵻�0������������*/
������return(p); /*��������Ҫ���ҽ��ĵ�ַ*/
����else p=p-��link;
��}
��if(p==NULL)
����printf("û�в��ҵ�������!");
}

int main()
{
��int number;
��char fullname[20];
��stud *head,*searchpoint; /*head�Ǳ�ͷָ�룬searchpoint�Ǳ�����������Ľ���ַ��ָ��*/
��number=N;
��head=creat(number);
��printf("��������Ҫ���ҵ��˵�����:");
��scanf("%s",fullname);
��searchpoint=search(head,fullname); /*���ò��Һ��������ѽ������searchpointָ��*/
}
