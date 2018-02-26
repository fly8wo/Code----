#include<stdio.h>
#include<stdlib.h>
struct list{
    int data;
    struct list *next;
};
//���������ںϣ�����������
void sort(struct list *l1,struct list *l2);
//�������
void output(struct list *head);
//��������
void input(struct list *head,int num);
 
int main()
{
    int n;
    list *h1,*h2;  //���������ͷ���������г�ʼ������
    h1=(struct list*)malloc(sizeof(struct list));
    h2=(struct list*)malloc(sizeof(struct list));
    h1->next=NULL;
    h2->next=NULL;
    //������������
    printf("�������һ������ڵ�����\n"); 
    scanf("%d",&n);
    input(h1,n);
    printf("������ڶ�������ڵ�����\n"); 
    scanf("%d",&n);
    input(h2,n);
    //�ϲ���������
    sort(h1,h2);
    //����ϲ��������
    output(h1);
}
 
void input(struct list *head,int num)
{
    struct list *tmp;
    struct list *end;
    end=head;
    printf("����������ڵ㣺\n");
    for(int i=0;i!=num;i++)
    {
        tmp=(struct list *)malloc(sizeof(struct list));
        scanf("%d",&tmp->data);
        end->next=tmp;
        tmp->next=NULL;
        end=tmp;
    }
}
 
void sort(struct list *l1,struct list *l2)
{
    struct list *p1,*p2,*tmp;
    p1=l1;
    p2=l2->next;
    while(p1->next&&p2)
    {
        if(p1->next->data>p2->data)
        {
            tmp=p2->next;
            p2->next=p1->next;
            p1->next=p2;
            p2=tmp;
        }
        else
            p1=p1->next;
    }
    if(p2)
        p1->next=p2;
}
 
void output(struct list *head)
{
    while(head->next)
    {
        printf(" %d ",head->next->data);
        head=head->next;
    }
}
