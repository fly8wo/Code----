/*����һ��ѧ����������ϵͳ��������ӣ����룬ɾ�����鿴���滻��*/
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
        printf("���ܷ����ڴ�ռ�!");
        exit(0);
    }
    h->name[0]='\0';
    h->link=NULL;
    p=h;
    for(i=0;i<n;i++)
    {
        if((s=(stud*)malloc(sizeof(stud)))==NULL)
        {
            printf("���ܷ����ڴ�ռ�!");
            exit(0);
        }
        p->link=s;
        p=s;
        printf("�������%d���˵�����:",i+1);
        scanf("%s",s->name);
        s->link=NULL;
    }
    return(h);
}

stud *search(stud *h,char *x)    //���ص�ǰ�ڵ�ĵ�ַ��Ҳ�Ϳ����ҵ���һ���ڵ�ĵ�ַp->link 
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
            printf("���ڸõ���!");
            printf("���ڵ�%dλ\n",i);
            return(p);
        }
        else p=p->link;
    }
    if(p==NULL)
    printf("û�и�����!");
}

void insert(stud *p) /*���뺯������ָ��p�����*/
{
char stuname[20];
stud *s; /*ָ��s�Ǳ����½���ַ��*/
if((s= (stud *)malloc(sizeof(stud)))==NULL)
{
printf("���ܷ����ڴ�ռ�!");
exit(0);
}
printf("��������Ҫ������˵�����:");
scanf("%s",stuname);
strcpy(s->name,stuname); /*��ָ��stuname��ָ�������Ԫ�ؿ������½���������*/
s->link=p->link; /*����p->link��ָ����һ���ڵ㣬���ڰ�ֵ�����½ڵ㣬���½�������ָ��ԭ��p���ĺ�̽��*/
p->link=s; /*p��������ָ���½��*/
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
    printf("�����ڸõ���!");
}

void del(stud *x,stud *y)   //xΪǰһ���ڵ��ָ�룬yΪ��ǰ�ڵ�ָ�� 
{
    x->link =y->link ;
    free(y);
    printf("�ɹ�ɾ������!\n"); 
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
        printf("��%d���˵�����:%s\n",i,stun);
        s=s->link ;
    }
}
int main(){
    stud *head,*searchpoint,*search2point;
    char fullname[20];
    int num;
    printf("/************************");
    printf("��������ϵͳ"); 
    printf("************************/\n");
    printf(" *   \t1:����\t\t2:ɾ��\t\t3:����\t\t    *\n");
    printf(" *   \t4:��ʾ����\t\t\t0:�˳�\t\t    *\n");
    printf("/************************");
    printf("��������ϵͳ"); 
    printf("************************/\n");
    head=creat(number);
    printf("����������ɣ�\n");
    while(1){
    printf("�����룺");
    scanf("%d",&num);
    if(num==0)
    exit(0);
    else if(num==1){
        printf("������Ҫ���ҵ����֣�");
        scanf("%s",fullname);
        searchpoint=search(head,fullname);
    }
    else if(num==2){
        printf("������Ҫɾ�������֣�");
        scanf("%s",fullname);
        searchpoint=search(head,fullname);
        search2point=search2(head,fullname);
        del(search2point,searchpoint);
    }
    else if(num==3){
        printf("������Ҫ�����ĸ����ֺ��棺");
        scanf("%s",fullname);
        searchpoint=search(head,fullname);
        insert(searchpoint);
    }else if(num==4){
        prin(head);
    }
    else printf("�������룡\n");
}
}
