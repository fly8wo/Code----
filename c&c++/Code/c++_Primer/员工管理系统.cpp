/* 
问题描述：每个员工的信息包括：编号、姓名、性别、出生年月、学历、职务、电话、住址等。系统能够完成员工信息的查询、更新、插入、删除、排序等功能。 
基本要求：排序：按不同关键字，对所有员工的信息进行排序；查询：按特定条件查找员工；更新，按编号对某个员工的某项信息进行修改；插入，加入新员工的信息；删除，按编号删除已离职的员工的信息。 
选作内容：实现图形用户界面。 
通过链表实现 
数据结构： 
struct workers 
{ 
    char name[15];//姓名 
    char  department[18];//单位 
    char gender;//性别 
    unsigned int age;//年龄 
    unsigned long telephone;//电话 
    unsigned long wage;//工资 
    unsigned long num;//职工号 
    struct workers *next; 
}; 
操作实现： 
/*插入职工信息，通过链表实现*/  
/*具体实现职工信息的插入*/  
/*对职工信息的删除操作*/  
/*修改操作*/  
/*实现对员工信息的查找*/  
/*排序*/  
/* 输出员工信息 */  
/* 显示职工工资情况 计算平均工资*/  
  
#include<stdio.h>  
#include<math.h>  
#include<stdlib.h>  
#include<string.h>  
#include<iostream>  
using namespace std;  
typedef struct workers  
{  
    char name[15];//姓名  
    char  department[18];//单位  
    char gender;//性别  
    unsigned int age;//年龄  
    unsigned long tel;//电话  
    unsigned long wage;//工资  
    unsigned long num;//职工号  
    struct workers *next;  
}Node;  
void input(Node *p)  
{  
    printf("请输入姓名：\n");  
    scanf("%s",p->name);  
    printf("请输入单位：\n");  
    scanf("%s",p->department);  
    getchar();  
    printf("请输入性别：\n");  
    scanf("%c",&p->gender);  
    printf("请输入年龄：\n");  
    scanf("%d",&p->age);  
    printf("请输入电话：\n");  
    scanf("%ld",&p->tel);  
    printf("请输入工资：\n");  
    scanf("%ld",&p->wage);  
    printf("请输入职工号：\n");  
    scanf("%ld",&p->num);  
    p->next=NULL;  
}  
Node *create()  
{  
    int i,n;  
    Node *p,*h,*q;  
    h=(Node*)malloc(sizeof(Node));  
    p=h;  
    printf("请输入你想新增员工的人数：\n");  
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
    printf("请输入你想查找的员工的职工号：\n");  
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
            printf("请重新输入姓名：\n");  
            scanf("%s",p->name);  
            printf("请重新输入单位：\n");  
            scanf("%s",p->department);  
            getchar();  
            printf("请重新输入性别：\n");  
            scanf("%c",&p->gender);  
            printf("请重新输入年龄：\n");  
            scanf("%d",&p->age);  
            printf("请重新输入电话：\n");  
            scanf("%ld",&p->tel);  
            printf("请重新输入工资：\n");  
            scanf("%ld",&p->wage);  
            printf("请重新输入职工号：\n");  
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
    printf("姓名    单位    性别    年龄      电话      工资        职工号   \n");  
    printf("%-8s%-8s%-8c%-8d%-12ld%-12ld%-8ld\n",p->name,p->department,p->gender,p->age,p->tel,p->wage,p->num);  
}  
void output_age(Node *p[],int n)  
{  
    printf("姓名    单位    性别    年龄      电话      工资        职工号   \n");  
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
        printf("现在一个人都没有！\n");  
        return;  
    }  
    printf("姓名    单位    性别    年龄      电话      工资        职工号   \n");  
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
    printf("请输入你想查询的项目：\n");  
    printf("1.姓名 2.单位 3.性别 4.年龄 5.电话 6.工资 7.职工号\n");  
    scanf("%d",&i);  
    switch(i)  
    {  
        case 1:  
            printf("请输入姓名：\n");  
            scanf("%s",na);  
            p=search_name(h,na);  
            if(p)  
              output(p);  
            else  
             printf("不存在这个人！\n");  
            break;  
        case 2:  
            printf("请输入单位：\n");  
            scanf("%s",dep);  
            p=search_department(h,dep);  
            if(p)  
              output(p);  
            else  
              printf("不存在这个人！\n");  
            break;  
        case 3:  
            printf("请输入性别：\n");  
            getchar();  
            scanf("%c",&gen);  
            search_gender(h,k,gen,&sum);  
            if(sum)  
              output_age(k,sum);  
            else  
              printf("不存在这种性别！\n");  
            break;  
        case 4:  
            printf("请输入年龄：\n");  
            scanf("%d",&ag);  
            p=search_age(h,ag);  
            if(p)  
              output(p);  
            else  
              printf("不存在这个人！\n");  
            break;  
        case 5:  
            printf("请输入电话：\n");  
            scanf("%ld",&te);  
            p=search_telephone(h,te);  
            if(p)  
              output(p);  
            else  
              printf("不存在这个人！\n");  
            break;  
        case 6:  
            printf("请输入工资：\n");  
            scanf("%ld",&wa);  
            p=search_wage(h,wa);  
            if(p)  
              output(p);  
            else  
              printf("不存在这个人！\n");  
            break;  
        case 7:  
            printf("请输入职工号：\n");  
            scanf("%ld",&nu);  
            p=search_num(h,nu);  
            if(p)  
              output(p);  
            else  
              printf("不存在这个人！\n");  
            break;  
        default:  
            printf("输入有误，请重新输入！\n");  
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
    printf("你想以何种形式查询你想删除的项目：\n");  
    printf("1.姓名 2.单位 3.性别 4.年龄 5.电话 6.工资 7.职工号\n");  
    scanf("%d",&i);  
    switch(i)  
    {  
        case 1:  
            printf("请输入姓名：\n");  
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
                printf("不存在这个人！\n");  
                return 0;  
            }  
            break;  
        case 2:  
            printf("请输入单位：\n");  
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
                printf("不存在这个人！\n");  
                return 0;  
            }  
            break;  
        case 3:  
            printf("请输入性别：\n");  
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
                printf("不存在这种性别！\n");  
                return 0;  
            }  
            break;  
        case 4:  
            printf("请输入年龄：\n");  
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
                printf("不存在这个人！\n");  
                return 0;  
            }  
            break;  
        case 5:  
            printf("请输入电话：\n");  
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
                printf("不存在这个人！\n");  
                return 0;  
            }  
            break;  
        case 6:  
            printf("请输入工资：\n");  
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
                printf("不存在这个人！\n");  
                return 0;  
            }  
            break;  
        case 7:  
            printf("请输入职工号：\n");  
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
                printf("不存在这个人！\n");  
                return 0;  
            }  
            break;  
        default:  
            printf("输入有误，请重新输入！\n");  
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
    printf("排序后的结果为：\n");  
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
    printf("排序后的结果为：\n");  
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
    printf("排序后的结果为：\n");  
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
    printf("排序后的结果为：\n");  
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
    printf("排序后的结果为：\n");  
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
    printf("排序后的结果为：\n");  
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
    printf("排序后的结果为：\n");  
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
    printf("排序后的结果为：\n");  
    travel(h);  
}  
void sort(Node *h)  
{  
    Node *p;  
    int i,j;  
    char na[20];  
    unsigned int ag;  
    unsigned long wa,nu;  
    printf("你想以何种形式对你的员工进行排序：\n");  
    printf("1.姓名 2.年龄 3.工资 4.职工号\n");  
    scanf("%d",&i);  
    switch(i)  
    {  
        case 1:  
          printf("请选择升序还是降序：\n");  
          printf("1.升序 2.降序\n");  
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
          printf("请选择升序还是降序：\n");  
          printf("1.升序 2.降序\n");  
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
          printf("请选择升序还是降序：\n");  
          printf("1.升序 2.降序\n");  
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
          printf("请选择升序还是降序：\n");  
          printf("1.升序 2.降序\n");  
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
          printf("输入有误，请重新输入！\n");  
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
        printf("平均工资是%.2lf元！\n",s/n);  
    }  
    else  
        printf("员工个数为0,不存在平均工资一说！\n");  
  
}  
void menu()  
{  
    printf("\n1.新建员工的信息\n");  
    printf("2.插入员工的信息\n");  
    printf("3.修改员工的信息\n");  
    printf("4.删除员工的信息\n");  
    printf("5.查询员工的信息\n");  
    printf("6.排序员工的信息\n");  
    printf("7.显示所有人的信息\n");  
    printf("8.显示平均工资\n");  
    printf("9.退出系统\n\n");  
}  
int main()  
{  
    int i,j,n,ret;  
    unsigned long nu;  
    Node *h;  
    printf("欢迎来到员工信息管理系统！\n");  
LL1:menu();  
    printf("请选择你的操作：\n");  
    scanf("%d",&i);  
    switch(i)  
    {  
        case 1:  
          h=create();  
          travel(h);  
          goto LL1;  
        case 2:  
          printf("请输入你想插入员工信息的条数：\n");  
          scanf("%d",&n);  
          for(j=0;j<n;j++)  
           insert(h);  
          travel(h);  
          goto LL1;  
        case 3:  
          ret=update(h);  
          if(!ret)  
            printf("你要找的职工号不存在!");  
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
          printf("谢谢你的使用，再见！\n");  
          exit(0);  
        default:  
          printf("你的输入有误，请重新输入！\n");  
          goto LL1;  
    }  
}  


