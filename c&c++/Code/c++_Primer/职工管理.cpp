#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int saveflag=0	 ;            /* �������������޷����ı䣬�Ƿ���Ҫ���̵ı�־���� */
struct employee
{
	char num[10];          /* ���� */
	char name[15];         /* ���� */
	char sex[7];           /* �Ա� */
	int age;               /* ���� */
	char education[15];    /* ѧ�� */
	int salary;            /* ���� */
	char phone[20];        /* �绰���� */
	char address[30];      /* סַ */
};

typedef struct Node 
{ 
	struct employee data; 
	struct Node *next; 
}ListNode,*LinkList;

void InitList(LinkList *head)   /*���������ʼ��Ϊ�ա���̬����һ��ͷ��㣬����ͷ����ָ������Ϊ��*/
{
	if((*head=(LinkList)malloc(sizeof(ListNode)))==NULL)   /*Ϊͷ������һ���洢�ռ�*/
		printf("ϵͳ����洢�ռ�ʧ�ܣ�\n");
	exit(-1);
	(*head)->next=NULL;   /*��ͷ����ָ������Ϊ��*/
}

ListNode *Locatenum(LinkList head,char find[])     //ͨ��ְ�����Ų��ң����ض�λָ�롣
{
	LinkList p;
	p=head->next;
	if(!p)       //���ְ����Ϣ��¼Ϊ�գ�����NULL��
		return NULL;
	while(p)
	{
		if(strcmp(p->data.num,find)==0)
			return p;
		p=p->next;
	}
	return NULL;
}

ListNode *Locatename(LinkList head,char find[])     //ͨ��ְ���������ң����ض�λָ�롣
{
	LinkList p;
	p=head->next;
	if(!p)       //���ְ����Ϣ��¼Ϊ�գ�����NULL��
		return NULL;
	while(p)
	{
		if(strcmp(p->data.name,find)==0)
			return p;
		p=p->next;
	}
	return NULL;
}
//�㷨˼�룬����ְ�����ʲ�ѯ��¼���ܣ����ض�λָ�롣 
ListNode *Locatesalary(LinkList head,int salary)    //ͨ��ְ�����ʲ��ң����ض�λָ�롣
{
	LinkList p;
	p=head->next;
	if(!p)       //���ְ����Ϣ��¼Ϊ�գ�����NULL��    
    	return NULL;
	while(p)
	{
		if(p->data.salary==salary)
			return p;
		p=p->next;
	}
	return NULL;
}

void Nofind()
{
	printf("\n***��ʾ***��û���ҵ���ְ����\n");
}

void Modify(LinkList L)    //�޸Ĺ��ܡ�
{
	   ListNode *p; 
	   char find[20]; 
	   if(!L->next) 
	   { 
		   printf("\n***��ʾ***:û�����Ͽ����޸�!\n"); 
		   return; 
	   } 
	   
	   printf("��������Ҫ�޸ĵ�ְ�����ţ�"); 
	   scanf("%s",find); 
	   p=Locatenum(L,find); 
	   
	   if(p) 
	   { 
		   printf("���������µĹ���(ԭ����%s):",p->data.num); 
		   scanf("%s",p->data.num); 
		   getchar();
		   printf("\n");
		   
		   printf("���������µ�����(ԭ����%s):",p->data.name); 
		   scanf("%s",p->data.name); 
		   getchar(); 
		   printf("\n");
		   
		   printf("���������µ��Ա�(ԭ����%s):",p->data.sex); 
		   scanf("%s",p->data.sex); 
		   getchar(); 
		   printf("\n");
		   
		   printf("���������µ�����(ԭ����%d):",p->data.age); 
		   scanf("%d",&p->data.age);
		   printf("\n");
		   
		   printf("���������µ�ѧ��(ԭ����%s):",p->data.education); 
		   scanf("%s",p->data.education); 
		   getchar(); 
		   printf("\n");
		   
		   printf("���������µĹ���(ԭ����%d):",p->data.salary); 
		   scanf("%d",&p->data.salary); 
		   printf("\n");

		   printf("���������µĵ绰(ԭ����%s):",p->data.phone); 
		   scanf("%s",p->data.phone); 
		   getchar(); 
		   printf("\n");

		   printf("���������µ�סַ(ԭ����%s):",p->data.address); 
		   scanf("%s",p->data.address); 
		   getchar(); 
		   printf("\n");
		   printf("\n***��ʾ***:�����޸ĳɹ�!\n");
		   saveflag=1;
	   } 
	   else 
		   Nofind(); //if(p)����
}  //void Modify(LinkList L)    //�޸Ĺ��ܽ���
//�����㷨˼�롣�������ݵĲ��� 
void Add(LinkList head)   /* ¼��ְ����Ϣ */
{
	system("cls");
	ListNode *p,*r,*s;    /* ʵ����Ӳ�������ʱ�Ľṹ��ָ����� */
	int sign;             /* ����ظ����ŵı��� */
	char num[10];
	r=head;
	s=head->next;         /* ����û�нڵ�ʱ��s=NULL;�����нڵ�ʱ��ָ���һ��ְ���ڵ� */
	while(r->next!=NULL)  /* ������ں�̽��ʱ��rָ�����һ�� */
		r=r->next;        /* ��ָ��������������ĩβ��׼����Ӽ�¼ */
	printf("����'#'���˳�ְ����Ϣ¼�룬�˻������˵���\n\n");
	while(1)
	{
		printf("��PS:ְ����Ϊ'#'���˳�¼�빦�ܣ�\n\n");
		printf("������ְ���ţ�");
		fflush(stdin);          //�����������
		gets(num);
		if(strcmp(num,"#")==0)  /* ����'0',����while(1),������Add()���� */
			break;
		s=head->next;           /* ÿ�δӵ�һ���ڵ㿪ʼ�ң���num�Ƿ��ظ���*/
			while(s)
			{
				if(strcmp(s->data.num,num)==0)
				{
					printf("***��ʾ***\n����Ϊ��'%s'��ְ����Ϣ�Ѿ����ڣ�\n",num);
					printf("��Ҫ�޸��밴'4'�������밴'0'��\n");
					scanf("%d",&sign);
					if(sign==4)
						Modify(head);
					else
						return;
				}
				s=s->next; 
			}//while(s)
			if((p=(LinkList)malloc(sizeof(ListNode)))==NULL)  //����û��ֵ���½ڵ� p��
			{
				printf("ϵͳ����洢�ռ�ʧ�ܣ�\n");
				printf("�˳�����\n");
				exit(-1);
			}
			strcpy(p->data.num,num);
			printf("\n");
			printf("�������ְ��������");
			scanf("%s",p->data.name);
			getchar();
			printf("\n");
			printf("�������ְ�����Ա𣺣�ע�����ԣ�male��Ů�ԣ�female��");
			scanf("%s",p->data.sex);
			getchar();
			printf("\n");
			printf("�������ְ�������䣺");
			scanf("%d",&p->data.age);
			printf("\n");
			printf("�������ְ����ѧ����");
			scanf("%s",p->data.education);
			getchar();
			printf("\n");
			printf("�������ְ���Ĺ��ʣ�");
			scanf("%d",&p->data.salary);
			printf("\n");
			printf("�������ְ���ĵ绰���룺");
			scanf("%s",p->data.phone);
			getchar();
			printf("\n");
			printf("�������ְ����סַ��");
			gets(p->data.address);
			printf("\n");
			p->next=NULL;   /* �������������β����� */
			r->next=p;      /* ���½��Ľ���������β���� */
			r=p;
			saveflag=1;
			printf("\n");
	}//while(1)����Ϊ�棬һֱִ����䡣 
}//void Add����������
//int main()������ 
//dasdaw�����������Ƿ���Ч�� 
void printline()      //��ӡ���ߡ�
{
	printf("--------------------------------------------------------------------------------\n");
}

void printsubject()   //��ӡ��������⡣
{
	printf(" �� ��\t �� ��   �� ��  �� ��  ѧ ��     �� ��    �� ��\t\t  ס ַ\n");
}

void printLinkList(LinkList p)   //��ӡp���������ݳ�Ա��ֵ��
{
	printf("  %s   %s  %s   %d  %s  %d   %s   %s\n",p->data.num,p->data.name,p->data.sex,p->data.age,p->data.education,p->data.salary,p->data.phone,p->data.address);
}

void Allemployeeinfo(LinkList head)  //��ʾ����ְ����Ϣ��
{
	int count=0;
	ListNode *p;
	p=head->next;
	if(!p)
	{
		printf("***��ʾ***��Ŀǰû�д洢�κ�ְ����¼��\n");
		printf("�������˵���������ѡ���ܣ�\n");
		return;
	}
	printf("\t\t\t\t��ʾ���\n");
	printline();
	printsubject();
	printf("\n");
	while(p)
	{
		printLinkList(p);
		p=p->next;
		count++;
	}
	printline();
	printf("\n");
	printf("�Ѿ��洢��%d��ְ����Ϣ��\n",count);
}

void Wrong()
{
	printf("\n***��ʾ***:�������\n");
}

void menu()   //���˵���
{
	printf("\n");
	printf("\t###################################################################\n");
	printf("\t*      -_-                                              -_-       *\n");
	printf("\t*                                                                 *\n");
	printf("\t*                 < ְ����Ϣ����ϵͳ_������ʵ�� >                 *\n");
	printf("\t*                                                                 *\n");
	printf("\t*       [1]    ¼��ְ����Ϣ            [2]    ɾ��ְ����Ϣ        *\n");
	printf("\t*       [3]    ��ѯְ����Ϣ            [4]    �޸�ְ����Ϣ        *\n");
	printf("\t*       [5]    ����ְ����¼            [6]    ͳ��ְ����Ϣ        *\n");
	printf("\t*       [7]    ����                    [8]    ����ְ����Ϣ        *\n");
	printf("\t*       [9]    ��ʾ����ְ����¼        [0]    �˳�ϵͳ            *\n");
	printf("\t*      -_-                                               -_-      *\n");
	printf("\t*                                                                 *\n");
	printf("\t*                                                 �ň�������      *\n");
	printf("\t*                                                 ���繤��1601    *\n");
	printf("\t*                                                                 *\n");
	printf("\t###################################################################\n");
} //void menu�˵�������

void Del(LinkList L)  //ɾ��ְ����Ϣ��
{
	int select;       //ɾ����ʽѡ���¼������
	ListNode *p,*r;
	char find[20];
	if(!L->next)      //��list�޺�̽��ʱ����ʾ�ͽ���Del()������
	{
		printf("\n***��ʾ***��û�м�¼����ɾ����\n"); 
		return; 
	} 
	printf("\n������ɾ�����밴'1'\n������ɾ�����밴'2'\n");
	printf("\n=====>����ѡ��");
	scanf("%d",&select);
	if(select==1)
	{
		printf("������Ҫɾ����ְ�����ţ�");
		scanf("%s",find);
		getchar();
		p=Locatenum(L,find);
		if(p)
		{
			r=L;
			while(r->next!=p)
				r=r->next;  //�ӵ�һ���������ֱ������r->next=p, �Ǵ�ɾ�����,����ѭ����
			r->next=p->next;
			free(p);
			printf("\n***��ʾ***����ְ����Ϣ�ѳɹ�ɾ����\n");
			saveflag=1;
		}
		else
			Nofind();
	}//if(select==1).
	else if(select==2)
	{
		printf("������Ҫɾ����ְ��������");
		scanf("%s",find);
		getchar();
		p=Locatename(L,find);
		if(p)
		{
			r=L;
			while(r->next!=p)
				r=r->next;
			r->next=p->next;
			free(p);
			printf("\n***��ʾ***����ְ����Ϣ�ѳɹ�ɾ����\n");
			saveflag=1;
		}
		else
			Nofind();
	}//if(select==2).
	else
		Wrong();    //��ʾ�������Ļ�
}//void Del()ɾ������������

void Search(LinkList L)      //��ѯְ����Ϣ��
{
	int select;
	int salary;
	int sign=0;
	char find[20];
	ListNode *p;             //ʵ�ֲ�ѯ��������ʱ�ṹ��ָ�������
	if(!L->next)
	{
		printf("\n***��ʾ***��û��ְ����Ϣ���Ͽ��Բ�ѯ��\n");
		printf("�������˵���������ѡ���ܣ�\n");
		return;
	}
	printf("\n�����Ų��ң��밴'1'\n�����ʲ��ң��밴'2'\n���������ң��밴'3'\n");
	printf("\n=====>����ѡ��");
	scanf("%d",&select);
	printf("\n");
	if(select==1)             //���š�
	{
		printf("������Ҫ���ҵĹ��ţ�");
		scanf("%s",find);
		getchar();
		p=Locatenum(L,find);
		if(p)
		{
			printf("\t\t\t\t   ���ҽ��\n");
			printline();        //��ӡ���ߡ�
			printsubject();     //��ӡ��������⡣
			printLinkList(p);   //��ӡp���������ݳ�Ա��ֵ��
			printline();        //��ӡ���ߡ�
		}
		else
			Nofind();
	}
	else if(select==2)          //���ʡ�
	{
		printf("������Ҫ���ҵĹ��ʣ�");
		scanf("%d",&salary);
		p=Locatesalary(L,salary);
		if(p)
		{
			printf("\t\t\t\t���ҽ��\n");
			printline();
			printsubject();
			printLinkList(p);
			printline();
			sign++;
		}
		while(p)
		{
			p=Locatesalary(p,salary);
			if(p)
		{
			printf("\t\t\t\t���ҽ��\n");
			printline();
			printsubject();
			printLinkList(p);
			printline();
			sign++;
		}
		}
		if(sign==0)
			Nofind();
	}
	else if(select==3)         //������
	{
		printf("������Ҫ���ҵ�������");
		scanf("%s",find);
		getchar();
		p=Locatename(L,find);
		if(p)
		{
			printf("\t\t\t\t���ҽ��\n");
			printline();
			printsubject();
			printLinkList(p);
			printline();
		}
		else
			Nofind();
	}
	else
		Wrong();
}//void Search()��ѯ����������

 void Save(LinkList L)                            //��Ϣ���浽�ļ��С�
{
	FILE *fp;
	ListNode *p;
	int count=0;
	int flag=1;
	fp=fopen("Employeeinfo.txt","wb");
	if(fp==NULL)
	{
		printf("\n***��ʾ***�����ļ�ʱ��������\n");
		return;
	}
	p=L->next;
	while(p)
	{
		if(fwrite(p,sizeof(ListNode),1,fp)==1)    //����һ����¼���ֵд���ļ��� 
		   { 
			   p=p->next;                         //����д����һ������ֵ��
			   count++;                           //�ļ��ļ�¼��+1��
		   } 
		   else 
		   { 
			   flag=0; 
			   printf("д���ļ����̷�������\n");
			   break; 
		   } 
	}//while(p).
	if(count>0)
	{
		printf("\n***��ʾ***���ļ�����ɹ���(��%d����¼�Ѿ����档)\n",count); 
		saveflag=0; 
	}
	else
	{
		system("cls");//������
		printf("�ļ�����ʧ�ܣ�'0'����¼�����档\n");
	}
	fclose(fp);
}//void Save()����������

void Sort(LinkList L)        //�����ܺ�����
{
	ListNode *p,*m,*n;
	int i,j,count=0;
	p=L->next;
	if(!p)
	{
		system("cls");       //������
		printf("���κ�ְ����Ϣ��\n");
		printf("�������˵���\n");
		return;
	}
	system("cls");           //������
	printf("�����ʴӵ͵�������\n");
	printf("***����Ϊ����ǰ������ְ����¼***\n");
	Allemployeeinfo(L);
	while(p)
	{
		count++;            //������ͷ����ְ����Ϣ�����ܸ�����
		p=p->next;
	}
	for(i=0;i<count-1;i++)  //�������ð������
		for(j=0;j<count-1-i;j++)
		{
			n=L;
			p=L->next;
			m=p->next;
			while(m)
			{
				if(p->data.salary>m->data.salary)
				{
					n->next=p->next;
					p->next=m->next;
					m->next=p;
					n=m;
					m=p->next;
				}
				else
				{
					n=p;
					p=m;
					m=m->next;
				}
			}
		}
		printf("***����Ϊ����������ְ����¼***\n");
		Allemployeeinfo(L);
		saveflag=1;
		printf("����ɹ���\n");
}

void Statistics(LinkList L) //ͳ��ְ���е���߹��ʺ���͹��ʡ�
{
	ListNode *Max,*Min;
	int i;
	ListNode *t=L->next;
	if(!t)
	{
		system("cls");      //������
		printf("û�д����κ�ְ����¼��\n");
		printf("�������˵�������¼��ְ����Ϣ��\n");
		return;
	}
	system("cls");
	Max=Min=t;
	t=t->next;
	while(t)
	{
		if(Max->data.salary<t->data.salary)
			Max=t;          //Maxָ��ָ����߹��ʵ�ְ����㡣
		if(Min->data.salary>t->data.salary)
			Min=t;          //Minָ��ָ����͹��ʵ�ְ����㡣
		t=t->next;
	}
	printf("��߹���Ϊ��%d\n",Max->data.salary);
	printf("��͹���Ϊ��%d\n",Min->data.salary);
	printf("��Ҫ�鿴��ͣ���߹��ʵ����ְ����Ϣ��\n");
	printf("�밴'1'��Ȼ������ʾ������ز�����\n");
	printf("�����밴'1'������κ����ּ����˳�ͳ�ƹ��ܣ��������˵���\n");
	printf("\n=====>����ѡ��");
	scanf("%d",&i);
	if(i==1)
		Search(L);          //��ʾ����Ҫ���ְ����Ϣ��
	else
		return;
}

void Insert(LinkList L)     //�����µ�ְ����Ϣ��
{
	printf("�����ܿ���ͨ�������͹��Ų��ҵ�����Ҫ���\n");  //���ܽ��ܡ�
	printf("���ְ����Ϣ��Ȼ����ϣ����ӽ�ȥ���µ�\n");
	printf("ְ����Ϣ���뵽��ְ����Ϣ��¼�ĺ��档\n");
	ListNode *p,*s;
	char find[20];          //��Ź��ź������ı�����
	int i;
	printf("ͨ���������ң��밴'1'��\n");
	printf("ͨ�����Ų��ң��밴'2'��\n");
	printf("�������˵����밴'3'��\n");
	printf("\n=====>����ѡ��");
	scanf("%d",&i);
	printf("\n");
	if(i==3)
	{
		system("cls");      //�˳����빦�ܣ��������˵���
		return;
	}
	else if(i==1)
	{
		printf("���������ڴ洢��¼�е�ְ��������");
		scanf("%s",find);
		getchar();
		p=Locatename(L,find); //��λ��
		if(!p)
		{
			printf("������ĸ�ְ������������Ϣ��¼�У������º���\n");
			printf("�������˵���\n");
			return;
		}
		s=(LinkList)malloc(sizeof(ListNode));
		if(!s)
		{
			printf("ϵͳ����洢�ռ�ʧ�ܣ�\n");
			system("cls");
			return;
		}
		printf("��������ְ�����ţ�");
		gets(s->data.num);
		printf("\n");
		printf("��������ְ��������");
		scanf("%s",s->data.name);
		getchar();
		printf("\n");
		printf("��������ְ�����Ա𣺣�ע�����ԣ�male��Ů�ԣ�female��");
		scanf("%s",s->data.sex);
		getchar();
		printf("\n");
		printf("��������ְ�������䣺");
		scanf("%d",&s->data.age);
		printf("\n");
		printf("��������ְ����ѧ����");
		scanf("%s",s->data.education);
		getchar();
		printf("\n");
		printf("��������ְ���Ĺ��ʣ�");
		scanf("%d",&s->data.salary);
		printf("\n");
		printf("��������ְ���ĵ绰���룺");
		scanf("%s",s->data.phone);
		getchar();
		printf("\n");
		printf("��������ְ����סַ��");
		scanf("%s",s->data.address);
		getchar();
		printf("\n");
		s->next=p->next;
		p->next=s;
		printf("����Ϊ��%s����ְ����Ϣ�ѳɹ��嵽����Ϊ��%s��ְ����Ϣ��¼���档\n",s->data.name,p->data.name);
		saveflag=1;          //�����ѸĶ��Ĵ洢������
	}
	else if(i==2)
	{
		printf("���������ڴ洢��¼�е�ְ�����ţ�");
		scanf("%s",find);
		getchar();
		p=Locatenum(L,find); //��λ��
		if(!p)
		{
			printf("������ĸ�ְ�����Ų�����Ϣ��¼�У������º���\n");
			printf("�������˵���\n");
			return;
		}
		s=(LinkList)malloc(sizeof(ListNode));
		if(!s)
		{
			printf("ϵͳ����洢�ռ�ʧ�ܣ�\n");
			system("cls");
			return;
		}
		printf("��������ְ�����ţ�");
		gets(s->data.num);
		printf("\n");
		printf("��������ְ��������");
		scanf("%s",s->data.name);
		getchar();
		printf("\n");
		printf("��������ְ�����Ա𣺣�ע�����ԣ�male��Ů�ԣ�female��");
		scanf("%s",s->data.sex);
		getchar();
		printf("\n");
		printf("��������ְ�������䣺");
		scanf("%d",&s->data.age);
		printf("\n");
		printf("��������ְ����ѧ����");
		scanf("%s",s->data.education);
		getchar();
		printf("\n");
		printf("��������ְ���Ĺ��ʣ�");
		scanf("%d",&s->data.salary);
		printf("\n");
		printf("��������ְ���ĵ绰���룺");
		scanf("%s",s->data.phone);
		getchar();
		printf("\n");
		printf("��������ְ����סַ��");
		scanf("%s",s->data.address);
		getchar();
		printf("\n");
		s->next=p->next;
		p->next=s;
		printf("����Ϊ��%s����ְ����Ϣ�ѳɹ��嵽����Ϊ��%s��ְ����Ϣ��¼���档\n",s->data.name,p->data.name);
		saveflag=1;
	}
	else
	{
		printf("����ѡ�����󣡷������˵���\n");
		return;
	}
}

int main()
{
	   LinkList L; /*��������*/ // struct Node *list;
	   FILE *fp;  /* �ļ�ָ�� */ 
	   int choose; /*����ѡ��������*/
	   char ch;     /*����(y,Y,n,N)*/
	   int count=0; /*�����ļ��еļ�¼���������������*/
	   struct Node *p,*r;   /*�����¼ָ�����*/
	   printf("\t\t\t\tְ����Ϣ����ϵͳ\n\t\t\t\t\n"); 
	   L=(struct Node*)malloc(sizeof(struct Node)); 
	   if(!L)
	   {
		   printf("\nϵͳ����洢�ռ�ʧ�ܣ�\n"); /*��û�����뵽����ӡ��ʾ��Ϣ*/
		   return 0;             /*���ز˵�*/
	   }
	   L->next=NULL; 
	   r=L; 
	   fp=fopen("Employeeinfo.txt","rb"); 
	   if(fp==NULL) 
	   { 
		   printf("\n***��ʾ***���洢ְ����Ϣ���ļ��������ڣ��Ƿ񴴽���(y/n)\n"); 
		   scanf("%c",&ch); 
		   if(ch=='y'||ch=='Y') 
		   {
			   fp=fopen("Employeeinfo.txt","ab+"); 
			   printf("�ļ������ɹ���\n");
		   }
		   else 
		   {
			   printf("�ļ�û�д������޷�д��ְ����Ϣ��\n\n");
			   printf("<-----�� �� ְ �� �� Ϣ �� �� ϵ ͳ----->\n");
			   exit(0); 
		   }
	   } //	if(fp==NULL) 
	   
	   printf("\n=====>��ʾ:�ļ��Ѿ���,���ڵ����¼......\n"); 
	   
	   while(!feof(fp)) //û�е��ļ�βʱ��ѭ��
	   { 
		   p=(struct Node*)malloc(sizeof(struct Node)); 
		   if(!p)
		   {
			   printf(" memory malloc failure!\n");    /*û������ɹ�*/
			   exit(0);       /*�˳�*/
		   }
		   
		   if(fread(p,sizeof(struct Node),1,fp)) /* ���ļ����������ݷ������� */ 
		   { 
			   p->next=NULL; 
			   r->next=p; 
			   r=p; /* ���ý�����������, rָ�����Ľڵ� */ 
			   count++; 
		   } 
	   } //while(!feof(fp)) 
	   
	   fclose(fp); /* �ر��ļ� */ 
	   printf("\n=====>��ʾ:��¼�������,������%d����¼��\n",count); 
	   while(1) 
	   { 
		   menu(); 
		   printf("\t\t====>��ѡ��");
		   scanf("%d",&choose);
		   if(choose==0) 
		   { 
			   if(saveflag==1) 
			   { 
				   getchar(); 
				   printf("\n=====>��ʾ:�����Ѿ��Ķ�,�Ƿ񽫸Ķ����浽�ļ���(y/n)?\n"); 
				   scanf("%c",&ch); 
				   if(ch=='y'||ch=='Y') 
					   Save(L); 
			   } 
			   printf("\n***��ʾ***�����Ѿ��˳�ϵͳ,��ӭ�ٴ�ʹ�ã�~\n"); 
			   break; 
		   }//if 
		switch(choose)
		{
		case 1:Add(L);
			break;
		case 2:Del(L);
			break;
		case 3:Search(L);
			break;
		case 4:Modify(L);
			break;
		case 5:Insert(L);
			break;
		case 6:Statistics(L);
			break;
		case 7:
			Sort(L);
			break;
		case 8:
			Save(L);
			break;
		case 9:
			system("cls");
			Allemployeeinfo(L);
			break;
		default:
			Wrong();
			break;
		}
	}
}



