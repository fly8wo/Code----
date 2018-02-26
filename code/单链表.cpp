#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    char data;
    struct node *next;
}linklist;                     
int main()
{
    linklist *creatlistr1();         
    void insert( linklist *L, char x );     
    int deletes( linklist *L, int n );     
    linklist *get( linklist *L, char n );   
    void output( linklist *L );      
    linklist *p,*q;
    char indata;       
    int inlocate,deletedx;         
   
    printf("请输入数据：");
    p=creatlistr1();         
    printf("原始数据为：");
    output(p);               
    printf("请输入要插入的数据：");
    scanf("%c",&indata);                      
    printf("请输入要插入的位置：");
    scanf("%d",&inlocate);
    q = get(p,inlocate-1);       
    insert(q,indata);            
    printf("插入后的数据：");
    output(p);             
    printf("请输入要删除的位置：");
 scanf("%d",&deletedx);            
    deletes( p, deletedx );        
    printf("删除后的数据：");
    output(p);             
    return 0; 
}
void output( linklist *p )      
{
 linklist *r=p;
 while ( r->next!=NULL )
 {
  printf("%c ",r->next->data);
  r=r->next;
 }
 printf("\n\n");
}
linklist *creatlistr1()        
{
 char ch;
 linklist *head,*s,*r;
 head = (linklist *)malloc(sizeof(linklist));
 r=head;
 ch = getchar();
 while ( ch!='$' )       
 {
  s = (linklist *)malloc(sizeof(linklist));
  s->data = ch;
  r->next = s;
  r = s;
  ch = getchar();
 }
 getchar();
 r->next = NULL;
 return head;
}
linklist *get( linklist *p, char n )       
{
    int i;
 linklist *r;
 r=p;
 i=0;
 while ( (r->next != NULL) && (i<n) )
 {
  r=r->next;
  i++;
 }
 if( i==n )
     return r;
 else
     return NULL;
}
int deletes( linklist *p, int n )         
{
 linklist *r,*s;
 int i;
 i = n-1;
 r = get(p,i);
 s = r->next;
 if( (r!=NULL) && ( r->next!=NULL) )
    {
        r->next = s->next;
        free(s);
    }
    else
    printf("error\n");
}
void insert( linklist *p, char x )          
{
 linklist *s;
 
 s = (linklist *)malloc(sizeof(linklist));
 s->data = x;
 s->next = p->next;
 p->next = s;
}
