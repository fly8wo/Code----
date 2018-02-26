/*制作一个学生档案管理系统，可以添加，插入，删除，查看，替换。*/
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h> 
#include<string.h>
#define number 3
typedef struct node
{
    char name[20];
    struct node *link;
}stud;

stud *creat(int n)
{
    int i;
    stud *p,*h,*s;
    if((h=(stud*)malloc(sizeof(stud)))==NULL)
    {
        printf("不能分配内存空间!");
        exit(0);
    }
    h->name[0]='\0';
    h->link=NULL;
    p=h;
    for(i=0;i<n;i++)
    {
        if((s=(stud*)malloc(sizeof(stud)))==NULL)
        {
            printf("不能分配内存空间!");
            exit(0);
        }
        p->link=s;
        p=s;
        printf("请输入第%d个人的姓名:",i+1);
        scanf("%s",s->name);
        s->link=NULL;
    }
    return(h);
}

stud *search(stud *h,char *x)    //返回当前节点的地址，也就可以找到下一个节点的地址p->link 
{
    stud *p;
    char *y;
    int i;
    p=h->link;
    while(p!=NULL) {
        y=p->name;
        i++;
        if(strcmp(x,y)==0)
        {
            printf("存在该档案!");
            printf("它在第%d位\n",i);
            return(p);
        }
        else p=p->link;
    }
    if(p==NULL)
    printf("没有该名字!");
}

void insert(stud *p) /*插入函数，在指针p后插入*/
{
char stuname[20];
stud *s; /*指针s是保存新结点地址的*/
if((s= (stud *)malloc(sizeof(stud)))==NULL)
{
printf("不能分配内存空间!");
exit(0);
}
printf("请输入你要插入的人的姓名:");
scanf("%s",stuname);
strcpy(s->name,stuname); /*把指针stuname所指向的数组元素拷贝给新结点的数据域*/
s->link=p->link; /*本来p->link是指向下一个节点，现在把值赋给新节点，把新结点的链域指向原来p结点的后继结点*/
p->link=s; /*p结点的链域指向新结点*/
}

stud *search2(stud *h,char *x)
{
    stud *p,*s;
    char *y;
    s=h;
    p=h->link ;
    while(p!=NULL)
    {
        y=p->name;
        if(strcmp(x,y)==0)
            return(s);
        else 
        {
            p=p->link ;
            s=s->link ;
        }
    }
    if(p==NULL)
    printf("不存在该档案!");
}

void del(stud *x,stud *y)   //x为前一个节点的指针，y为当前节点指针 
{
    x->link =y->link ;
    free(y);
    printf("成功删除档案!\n"); 
}

void prin(stud *h)
{
    char *stun,c;
    stud *s;
    int i=0;
    s=h->link;
    while(s!=NULL)
    {
        i++;
        stun=s->name;
        printf("第%d个人的姓名:%s\n",i,stun);
        s=s->link ;
    }
}
int main(){
    stud *head,*searchpoint,*search2point;
    char fullname[20];
    int num;
    printf("/************************");
    printf("档案管理系统"); 
    printf("************************/\n");
    printf(" *   \t1:查找\t\t2:删除\t\t3:插入\t\t    *\n");
    printf(" *   \t4:显示档案\t\t\t0:退出\t\t    *\n");
    printf("/************************");
    printf("档案管理系统"); 
    printf("************************/\n");
    head=creat(number);
    printf("档案创建完成！\n");
    while(1){
    printf("请输入：");
    scanf("%d",&num);
    if(num==0)
    exit(0);
    else if(num==1){
        printf("请输入要查找的名字：");
        scanf("%s",fullname);
        searchpoint=search(head,fullname);
    }
    else if(num==2){
        printf("请输入要删除的名字：");
        scanf("%s",fullname);
        searchpoint=search(head,fullname);
        search2point=search2(head,fullname);
        del(search2point,searchpoint);
    }
    else if(num==3){
        printf("请输入要插在哪个名字后面：");
        scanf("%s",fullname);
        searchpoint=search(head,fullname);
        insert(searchpoint);
    }else if(num==4){
        prin(head);
    }
    else printf("错误输入！\n");
}
}
