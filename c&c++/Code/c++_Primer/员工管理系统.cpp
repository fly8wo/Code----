/* 
����������ÿ��Ա������Ϣ��������š��������Ա𡢳������¡�ѧ����ְ�񡢵绰��סַ�ȡ�ϵͳ�ܹ����Ա����Ϣ�Ĳ�ѯ�����¡����롢ɾ��������ȹ��ܡ� 
����Ҫ�����򣺰���ͬ�ؼ��֣�������Ա������Ϣ�������򣻲�ѯ�����ض���������Ա�������£�����Ŷ�ĳ��Ա����ĳ����Ϣ�����޸ģ����룬������Ա������Ϣ��ɾ���������ɾ������ְ��Ա������Ϣ�� 
ѡ�����ݣ�ʵ��ͼ���û����档 
ͨ������ʵ�� 
���ݽṹ�� 
struct workers 
{ 
    char name[15];//���� 
    char  department[18];//��λ 
    char gender;//�Ա� 
    unsigned int age;//���� 
    unsigned long telephone;//�绰 
    unsigned long wage;//���� 
    unsigned long num;//ְ���� 
    struct workers *next; 
}; 
����ʵ�֣� 
/*����ְ����Ϣ��ͨ������ʵ��*/  
/*����ʵ��ְ����Ϣ�Ĳ���*/  
/*��ְ����Ϣ��ɾ������*/  
/*�޸Ĳ���*/  
/*ʵ�ֶ�Ա����Ϣ�Ĳ���*/  
/*����*/  
/* ���Ա����Ϣ */  
/* ��ʾְ��������� ����ƽ������*/  
  
#include<stdio.h>  
#include<math.h>  
#include<stdlib.h>  
#include<string.h>  
#include<iostream>  
using namespace std;  
typedef struct workers  
{  
    char name[15];//����  
    char  department[18];//��λ  
    char gender;//�Ա�  
    unsigned int age;//����  
    unsigned long tel;//�绰  
    unsigned long wage;//����  
    unsigned long num;//ְ����  
    struct workers *next;  
}Node;  
void input(Node *p)  
{  
    printf("������������\n");  
    scanf("%s",p->name);  
    printf("�����뵥λ��\n");  
    scanf("%s",p->department);  
    getchar();  
    printf("�������Ա�\n");  
    scanf("%c",&p->gender);  
    printf("���������䣺\n");  
    scanf("%d",&p->age);  
    printf("������绰��\n");  
    scanf("%ld",&p->tel);  
    printf("�����빤�ʣ�\n");  
    scanf("%ld",&p->wage);  
    printf("������ְ���ţ�\n");  
    scanf("%ld",&p->num);  
    p->next=NULL;  
}  
Node *create()  
{  
    int i,n;  
    Node *p,*h,*q;  
    h=(Node*)malloc(sizeof(Node));  
    p=h;  
    printf("��������������Ա����������\n");  
    scanf("%d",&n);  
    for(i=0;i<n;i++)  
    {  
        q=(Node*)malloc(sizeof(Node));  
        input(q);  
        p->next=q;  
        p=q;  
    }  
    return h;  
}  
int update(Node *h)  
{  
    unsigned long nu;  
    Node *p;  
    p=h->next;  
    printf("������������ҵ�Ա����ְ���ţ�\n");  
    scanf("%ld",&nu);  
    if(!p)  
     return 0;  
    else  
    {  
        while(p&&p->num!=nu)  
        {  
            p=p->next;  
        }  
        if(!p)  
         return 0;  
        else  
        {  
            printf("����������������\n");  
            scanf("%s",p->name);  
            printf("���������뵥λ��\n");  
            scanf("%s",p->department);  
            getchar();  
            printf("�����������Ա�\n");  
            scanf("%c",&p->gender);  
            printf("�������������䣺\n");  
            scanf("%d",&p->age);  
            printf("����������绰��\n");  
            scanf("%ld",&p->tel);  
            printf("���������빤�ʣ�\n");  
            scanf("%ld",&p->wage);  
            printf("����������ְ���ţ�\n");  
            scanf("%ld",&p->num);  
            return 1;  
        }  
    }  
}  
void insert(Node *h)  
{  
    Node *p,*q;  
    p=h;  
    q=(Node*)malloc(sizeof(Node));  
    input(q);  
    while(p->next)  
    {  
        p=p->next;  
    }  
    p->next=q;  
}  
void output(Node *p)  
{  
    printf("����    ��λ    �Ա�    ����      �绰      ����        ְ����   \n");  
    printf("%-8s%-8s%-8c%-8d%-12ld%-12ld%-8ld\n",p->name,p->department,p->gender,p->age,p->tel,p->wage,p->num);  
}  
void output_age(Node *p[],int n)  
{  
    printf("����    ��λ    �Ա�    ����      �绰      ����        ְ����   \n");  
    int i;  
    for(i=0;i<n;i++)  
      printf("%-8s%-8s%-8c%-8d%-12ld%-12ld%-8ld\n",p[i]->name,p[i]->department,p[i]->gender,p[i]->age,p[i]->tel,p[i]->wage,p[i]->num);  
}  
void travel(Node *h)  
{  
    Node *p;  
    p=h->next;  
    if(!h->next)  
    {  
        printf("����һ���˶�û�У�\n");  
        return;  
    }  
    printf("����    ��λ    �Ա�    ����      �绰      ����        ְ����   \n");  
    while(p)  
    {  
        printf("%-8s%-8s%-8c%-8d%-12ld%-12ld%-8ld\n",p->name,p->department,p->gender,p->age,p->tel,p->wage,p->num);  
        p=p->next;  
    }  
}  
Node *search_name(Node *h,char na[])  
{  
    Node *p;  
    p=h->next;  
    while(p&&strcmp(p->name,na)!=0)  
    {  
        p=p->next;  
    }  
    if(!p)  
     return NULL;  
    else  
     return p;  
}  
Node *search_department(Node *h,char dep[])  
{  
    Node *p;  
    p=h->next;  
    while(p&&strcmp(p->department,dep)!=0)  
    {  
        p=p->next;  
    }  
    if(!p)  
     return NULL;  
    else  
     return p;  
}  
void search_gender(Node *h,Node *gender[],char gen,int *sum)  
{  
    Node *p;  
    int i=0;  
    p=h->next;  
    while(p)  
    {  
        if(p->gender==gen)  
          gender[i++]=p;  
        p=p->next;  
    }  
    *sum=i;  
}  
Node *search_age(Node *h,unsigned int ag)  
{  
    Node *p;  
    p=h->next;  
    while(p&&p->age!=ag)  
    {  
        p=p->next;  
    }  
    if(!p)  
     return NULL;  
    else  
     return p;  
}  
Node *search_telephone(Node *h,unsigned long te)  
{  
    Node *p;  
    p=h->next;  
    while(p&&p->tel!=te)  
    {  
        p=p->next;  
    }  
    if(!p)  
     return NULL;  
    else  
     return p;  
}  
Node *search_wage(Node *h,unsigned int wa)  
{  
    Node *p;  
    p=h->next;  
    while(p&&p->wage!=wa)  
    {  
        p=p->next;  
    }  
    if(!p)  
     return NULL;  
    else  
     return p;  
}  
Node *search_num(Node *h,unsigned int nu)  
{  
    Node *p;  
    p=h->next;  
    while(p&&p->num!=nu)  
    {  
        p=p->next;  
    }  
    if(!p)  
     return NULL;  
    else  
     return p;  
}  
void search(Node *h)  
{  
    Node *k[20],*p;  
    int i,sum;  
    char na[20],dep[20],gen;  
    unsigned int ag;  
    unsigned long te,wa,nu;  
    printf("�����������ѯ����Ŀ��\n");  
    printf("1.���� 2.��λ 3.�Ա� 4.���� 5.�绰 6.���� 7.ְ����\n");  
    scanf("%d",&i);  
    switch(i)  
    {  
        case 1:  
            printf("������������\n");  
            scanf("%s",na);  
            p=search_name(h,na);  
            if(p)  
              output(p);  
            else  
             printf("����������ˣ�\n");  
            break;  
        case 2:  
            printf("�����뵥λ��\n");  
            scanf("%s",dep);  
            p=search_department(h,dep);  
            if(p)  
              output(p);  
            else  
              printf("����������ˣ�\n");  
            break;  
        case 3:  
            printf("�������Ա�\n");  
            getchar();  
            scanf("%c",&gen);  
            search_gender(h,k,gen,&sum);  
            if(sum)  
              output_age(k,sum);  
            else  
              printf("�����������Ա�\n");  
            break;  
        case 4:  
            printf("���������䣺\n");  
            scanf("%d",&ag);  
            p=search_age(h,ag);  
            if(p)  
              output(p);  
            else  
              printf("����������ˣ�\n");  
            break;  
        case 5:  
            printf("������绰��\n");  
            scanf("%ld",&te);  
            p=search_telephone(h,te);  
            if(p)  
              output(p);  
            else  
              printf("����������ˣ�\n");  
            break;  
        case 6:  
            printf("�����빤�ʣ�\n");  
            scanf("%ld",&wa);  
            p=search_wage(h,wa);  
            if(p)  
              output(p);  
            else  
              printf("����������ˣ�\n");  
            break;  
        case 7:  
            printf("������ְ���ţ�\n");  
            scanf("%ld",&nu);  
            p=search_num(h,nu);  
            if(p)  
              output(p);  
            else  
              printf("����������ˣ�\n");  
            break;  
        default:  
            printf("�����������������룡\n");  
            search(h);  
    }  
}  
void delete_node(Node *h,Node*p)  
{  
    Node *pre;  
    pre=h;  
    while(pre->next!=p)  
    {  
        pre=pre->next;  
    }  
    pre->next=p->next;  
    free(p);  
}  
int delete_info(Node *h)  
{  
    Node *p,*k[20];  
    int i,j,sum;  
    char na[20],dep[20],gen;  
    unsigned int ag;  
    unsigned long te,wa,nu;  
    printf("�����Ժ�����ʽ��ѯ����ɾ������Ŀ��\n");  
    printf("1.���� 2.��λ 3.�Ա� 4.���� 5.�绰 6.���� 7.ְ����\n");  
    scanf("%d",&i);  
    switch(i)  
    {  
        case 1:  
            printf("������������\n");  
            scanf("%s",na);  
            p=search_name(h,na);  
            if(p)  
            {  
                delete_node(h,p);  
                travel(h);  
                return 1;  
            }  
            else  
            {  
                printf("����������ˣ�\n");  
                return 0;  
            }  
            break;  
        case 2:  
            printf("�����뵥λ��\n");  
            scanf("%s",dep);  
            p=search_department(h,dep);  
            if(p)  
            {  
                delete_node(h,p);  
                travel(h);  
                return 1;  
            }  
            else  
            {  
                printf("����������ˣ�\n");  
                return 0;  
            }  
            break;  
        case 3:  
            printf("�������Ա�\n");  
            getchar();  
            scanf("%c",&gen);  
            search_gender(h,k,gen,&sum);  
            if(sum)  
            {  
                for(j=0;j<sum;j++)  
                  delete_node(h,k[j]);  
                travel(h);  
                return 1;  
            }  
            else  
            {  
                printf("�����������Ա�\n");  
                return 0;  
            }  
            break;  
        case 4:  
            printf("���������䣺\n");  
            scanf("%d",&ag);  
            p=search_age(h,ag);  
            if(p)  
            {  
                delete_node(h,p);  
                travel(h);  
                return 1;  
            }  
            else  
            {  
                printf("����������ˣ�\n");  
                return 0;  
            }  
            break;  
        case 5:  
            printf("������绰��\n");  
            scanf("%ld",&te);  
            p=search_telephone(h,te);  
            if(p)  
            {  
                delete_node(h,p);  
                travel(h);  
                return 1;  
            }  
            else  
            {  
                printf("����������ˣ�\n");  
                return 0;  
            }  
            break;  
        case 6:  
            printf("�����빤�ʣ�\n");  
            scanf("%ld",&wa);  
            p=search_wage(h,wa);  
            if(p)  
            {  
                delete_node(h,p);  
                travel(h);  
                return 1;  
            }  
            else  
            {  
                printf("����������ˣ�\n");  
                return 0;  
            }  
            break;  
        case 7:  
            printf("������ְ���ţ�\n");  
            scanf("%ld",&nu);  
            p=search_num(h,nu);  
            if(p)  
            {  
                delete_node(h,p);  
                travel(h);  
                return 1;  
            }  
            else  
            {  
                printf("����������ˣ�\n");  
                return 0;  
            }  
            break;  
        default:  
            printf("�����������������룡\n");  
            delete(h);  
            break;  
    }  
}  
void sort_name_1(Node *h)  
{  
    Node *pre,*p,*tail,*temp;  
    if(h->next&&h->next->next)  
    {  
        tail=NULL;  
        while(h->next!=tail)  
        {  
            pre=h;  
            p=pre->next;  
            while(p->next!=tail)  
            {  
                if(strcmp(p->name,p->next->name)>0)  
                {  
                    temp=p->next;  
                    p->next=temp->next;  
                    temp->next=p;  
                    pre->next=temp;  
                    p=temp;  
                }  
                pre=pre->next;  
                p=p->next;  
            }  
            tail=p;  
        }  
    }  
    printf("�����Ľ��Ϊ��\n");  
    travel(h);  
}  
void sort_name_2(Node *h)  
{  
    Node *pre,*p,*tail,*temp;  
    if(h->next&&h->next->next)  
    {  
        tail=NULL;  
        while(h->next!=tail)  
        {  
            pre=h;  
            p=pre->next;  
            while(p->next!=tail)  
            {  
                if(strcmp(p->name,p->next->name)<0)  
                {  
                    temp=p->next;  
                    p->next=temp->next;  
                    temp->next=p;  
                    pre->next=temp;  
                    p=temp;  
                }  
                pre=pre->next;  
                p=p->next;  
            }  
            tail=p;  
        }  
    }  
    printf("�����Ľ��Ϊ��\n");  
    travel(h);  
}  
void sort_age_1(Node *h)  
{  
    Node *pre,*p,*tail,*temp;  
    if(h->next&&h->next->next)  
    {  
        tail=NULL;  
        while(h->next!=tail)  
        {  
            pre=h;  
            p=pre->next;  
            while(p->next!=tail)  
            {  
                if(p->age>p->next->age)  
                {  
                    temp=p->next;  
                    p->next=temp->next;  
                    temp->next=p;  
                    pre->next=temp;  
                    p=temp;  
                }  
                pre=pre->next;  
                p=p->next;  
            }  
            tail=p;  
        }  
    }  
    printf("�����Ľ��Ϊ��\n");  
    travel(h);  
}  
void sort_age_2(Node *h)  
{  
    Node *pre,*p,*tail,*temp;  
    if(h->next&&h->next->next)  
    {  
        tail=NULL;  
        while(h->next!=tail)  
        {  
            pre=h;  
            p=pre->next;  
            while(p->next!=tail)  
            {  
                if(p->age<p->next->age)  
                {  
                    temp=p->next;  
                    p->next=temp->next;  
                    temp->next=p;  
                    pre->next=temp;  
                    p=temp;  
                }  
                pre=pre->next;  
                p=p->next;  
            }  
            tail=p;  
        }  
    }  
    printf("�����Ľ��Ϊ��\n");  
    travel(h);  
}  
void sort_wage_1(Node *h)  
{  
    Node *pre,*p,*tail,*temp;  
    if(h->next&&h->next->next)  
    {  
        tail=NULL;  
        while(h->next!=tail)  
        {  
            pre=h;  
            p=pre->next;  
            while(p->next!=tail)  
            {  
                if(p->wage>p->next->wage)  
                {  
                    temp=p->next;  
                    p->next=temp->next;  
                    temp->next=p;  
                    pre->next=temp;  
                    p=temp;  
                }  
                pre=pre->next;  
                p=p->next;  
            }  
            tail=p;  
        }  
    }  
    printf("�����Ľ��Ϊ��\n");  
    travel(h);  
}  
void sort_wage_2(Node *h)  
{  
    Node *pre,*p,*tail,*temp;  
    if(h->next&&h->next->next)  
    {  
        tail=NULL;  
        while(h->next!=tail)  
        {  
            pre=h;  
            p=pre->next;  
            while(p->next!=tail)  
            {  
                if(p->wage<p->next->wage)  
                {  
                    temp=p->next;  
                    p->next=temp->next;  
                    temp->next=p;  
                    pre->next=temp;  
                    p=temp;  
                }  
                pre=pre->next;  
                p=p->next;  
            }  
            tail=p;  
        }  
    }  
    printf("�����Ľ��Ϊ��\n");  
    travel(h);  
}  
void sort_num_1(Node *h)  
{  
    Node *pre,*p,*tail,*temp;  
    if(h->next&&h->next->next)  
    {  
        tail=NULL;  
        while(h->next!=tail)  
        {  
            pre=h;  
            p=pre->next;  
            while(p->next!=tail)  
            {  
                if(p->num>p->next->num)  
                {  
                    temp=p->next;  
                    p->next=temp->next;  
                    temp->next=p;  
                    pre->next=temp;  
                    p=temp;  
                }  
                pre=pre->next;  
                p=p->next;  
            }  
            tail=p;  
        }  
    }  
    printf("�����Ľ��Ϊ��\n");  
    travel(h);  
}  
void sort_num_2(Node *h)  
{  
    Node *pre,*p,*tail,*temp;  
    if(h->next&&h->next->next)  
    {  
        tail=NULL;  
        while(h->next!=tail)  
        {  
            pre=h;  
            p=pre->next;  
            while(p->next!=tail)  
            {  
                if(p->num<p->next->num)  
                {  
                    temp=p->next;  
                    p->next=temp->next;  
                    temp->next=p;  
                    pre->next=temp;  
                    p=temp;  
                }  
                pre=pre->next;  
                p=p->next;  
            }  
            tail=p;  
        }  
    }  
    printf("�����Ľ��Ϊ��\n");  
    travel(h);  
}  
void sort(Node *h)  
{  
    Node *p;  
    int i,j;  
    char na[20];  
    unsigned int ag;  
    unsigned long wa,nu;  
    printf("�����Ժ�����ʽ�����Ա����������\n");  
    printf("1.���� 2.���� 3.���� 4.ְ����\n");  
    scanf("%d",&i);  
    switch(i)  
    {  
        case 1:  
          printf("��ѡ�������ǽ���\n");  
          printf("1.���� 2.����\n");  
          scanf("%d",&j);  
          switch(j)  
          {  
              case 1:  
                sort_name_1(h);  
                break;  
              case 2:  
                sort_name_2(h);  
                break;  
              default:  
                break;  
          }  
          break;  
        case 2:  
          printf("��ѡ�������ǽ���\n");  
          printf("1.���� 2.����\n");  
          scanf("%d",&j);  
          switch(j)  
          {  
              case 1:  
                sort_age_1(h);  
                break;  
              case 2:  
                sort_age_2(h);  
                break;  
              default:  
                break;  
          }  
          break;  
        case 3:  
          printf("��ѡ�������ǽ���\n");  
          printf("1.���� 2.����\n");  
          scanf("%d",&j);  
          switch(j)  
          {  
              case 1:  
                sort_wage_1(h);  
                break;  
              case 2:  
                sort_wage_2(h);  
                break;  
              default:  
                break;  
          }  
          break;  
        case 4:  
          printf("��ѡ�������ǽ���\n");  
          printf("1.���� 2.����\n");  
          scanf("%d",&j);  
          switch(j)  
          {  
              case 1:  
                sort_num_1(h);  
                break;  
              case 2:  
                sort_num_2(h);  
                break;  
              default:  
                break;  
          }  
          break;  
        default:  
          printf("�����������������룡\n");  
          sort(h);  
          break;  
    }  
}  
void ave_wage(Node *h)  
{  
    Node *p=h->next;  
    int n=0;  
    double s=0;  
    if(p)  
    {  
        while(p)  
        {  
            n++;  
            s+=p->wage;  
            p=p->next;  
        }  
        printf("ƽ��������%.2lfԪ��\n",s/n);  
    }  
    else  
        printf("Ա������Ϊ0,������ƽ������һ˵��\n");  
  
}  
void menu()  
{  
    printf("\n1.�½�Ա������Ϣ\n");  
    printf("2.����Ա������Ϣ\n");  
    printf("3.�޸�Ա������Ϣ\n");  
    printf("4.ɾ��Ա������Ϣ\n");  
    printf("5.��ѯԱ������Ϣ\n");  
    printf("6.����Ա������Ϣ\n");  
    printf("7.��ʾ�����˵���Ϣ\n");  
    printf("8.��ʾƽ������\n");  
    printf("9.�˳�ϵͳ\n\n");  
}  
int main()  
{  
    int i,j,n,ret;  
    unsigned long nu;  
    Node *h;  
    printf("��ӭ����Ա����Ϣ����ϵͳ��\n");  
LL1:menu();  
    printf("��ѡ����Ĳ�����\n");  
    scanf("%d",&i);  
    switch(i)  
    {  
        case 1:  
          h=create();  
          travel(h);  
          goto LL1;  
        case 2:  
          printf("�������������Ա����Ϣ��������\n");  
          scanf("%d",&n);  
          for(j=0;j<n;j++)  
           insert(h);  
          travel(h);  
          goto LL1;  
        case 3:  
          ret=update(h);  
          if(!ret)  
            printf("��Ҫ�ҵ�ְ���Ų�����!");  
          else  
            travel(h);  
          goto LL1;  
        case 4:  
          delete_info(h);  
          goto LL1;  
        case 5:  
          search(h);  
          goto LL1;  
        case 6:  
          sort(h);  
          goto LL1;  
        case 7:  
          travel(h);  
          goto LL1;  
        case 8:  
          ave_wage(h);  
          goto LL1;  
        case 9:  
          printf("лл���ʹ�ã��ټ���\n");  
          exit(0);  
        default:  
          printf("��������������������룡\n");  
          goto LL1;  
    }  
}  


