#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int saveflag=0	 ;            /* 单链表内容有无发生改变，是否需要存盘的标志变量 */
struct employee
{
	char num[10];          /* 工号 */
	char name[15];         /* 姓名 */
	char sex[7];           /* 性别 */
	int age;               /* 年龄 */
	char education[15];    /* 学历 */
	int salary;            /* 工资 */
	char phone[20];        /* 电话号码 */
	char address[30];      /* 住址 */
};

typedef struct Node 
{ 
	struct employee data; 
	struct Node *next; 
}ListNode,*LinkList;

void InitList(LinkList *head)   /*将单链表初始化为空。动态生成一个头结点，并将头结点的指针域置为空*/
{
	if((*head=(LinkList)malloc(sizeof(ListNode)))==NULL)   /*为头结点分配一个存储空间*/
		printf("系统分配存储空间失败！\n");
	exit(-1);
	(*head)->next=NULL;   /*将头结点的指针域置为空*/
}

ListNode *Locatenum(LinkList head,char find[])     //通过职工工号查找，返回定位指针。
{
	LinkList p;
	p=head->next;
	if(!p)       //如果职工信息记录为空，返回NULL。
		return NULL;
	while(p)
	{
		if(strcmp(p->data.num,find)==0)
			return p;
		p=p->next;
	}
	return NULL;
}

ListNode *Locatename(LinkList head,char find[])     //通过职工姓名查找，返回定位指针。
{
	LinkList p;
	p=head->next;
	if(!p)       //如果职工信息记录为空，返回NULL。
		return NULL;
	while(p)
	{
		if(strcmp(p->data.name,find)==0)
			return p;
		p=p->next;
	}
	return NULL;
}
//算法思想，设置职工工资查询记录功能，返回定位指针。 
ListNode *Locatesalary(LinkList head,int salary)    //通过职工工资查找，返回定位指针。
{
	LinkList p;
	p=head->next;
	if(!p)       //如果职工信息记录为空，返回NULL。    
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
	printf("\n***提示***：没有找到该职工！\n");
}

void Modify(LinkList L)    //修改功能。
{
	   ListNode *p; 
	   char find[20]; 
	   if(!L->next) 
	   { 
		   printf("\n***提示***:没有资料可以修改!\n"); 
		   return; 
	   } 
	   
	   printf("请你输入要修改的职工工号："); 
	   scanf("%s",find); 
	   p=Locatenum(L,find); 
	   
	   if(p) 
	   { 
		   printf("请你输入新的工号(原来是%s):",p->data.num); 
		   scanf("%s",p->data.num); 
		   getchar();
		   printf("\n");
		   
		   printf("请你输入新的姓名(原来是%s):",p->data.name); 
		   scanf("%s",p->data.name); 
		   getchar(); 
		   printf("\n");
		   
		   printf("请你输入新的性别(原来是%s):",p->data.sex); 
		   scanf("%s",p->data.sex); 
		   getchar(); 
		   printf("\n");
		   
		   printf("请你输入新的年龄(原来是%d):",p->data.age); 
		   scanf("%d",&p->data.age);
		   printf("\n");
		   
		   printf("请你输入新的学历(原来是%s):",p->data.education); 
		   scanf("%s",p->data.education); 
		   getchar(); 
		   printf("\n");
		   
		   printf("请你输入新的工资(原来是%d):",p->data.salary); 
		   scanf("%d",&p->data.salary); 
		   printf("\n");

		   printf("请你输入新的电话(原来是%s):",p->data.phone); 
		   scanf("%s",p->data.phone); 
		   getchar(); 
		   printf("\n");

		   printf("请你输入新的住址(原来是%s):",p->data.address); 
		   scanf("%s",p->data.address); 
		   getchar(); 
		   printf("\n");
		   printf("\n***提示***:资料修改成功!\n");
		   saveflag=1;
	   } 
	   else 
		   Nofind(); //if(p)结束
}  //void Modify(LinkList L)    //修改功能结束
//核心算法思想。链表内容的插入 
void Add(LinkList head)   /* 录入职工信息 */
{
	system("cls");
	ListNode *p,*r,*s;    /* 实现添加操作的临时的结构体指针变量 */
	int sign;             /* 标记重复工号的变量 */
	char num[10];
	r=head;
	s=head->next;         /* 链表没有节点时，s=NULL;链表有节点时，指向第一个职工节点 */
	while(r->next!=NULL)  /* 如果存在后继结点时，r指针后移一个 */
		r=r->next;        /* 将指针移至于链表最末尾，准备添加记录 */
	printf("输入'#'将退出职工信息录入，退回至主菜单！\n\n");
	while(1)
	{
		printf("（PS:职工号为'#'即退出录入功能）\n\n");
		printf("请输入职工号：");
		fflush(stdin);          //清除缓冲区。
		gets(num);
		if(strcmp(num,"#")==0)  /* 输入'0',跳出while(1),即跳出Add()函数 */
			break;
		s=head->next;           /* 每次从第一个节点开始找，看num是否重复。*/
			while(s)
			{
				if(strcmp(s->data.num,num)==0)
				{
					printf("***提示***\n工号为：'%s'的职工信息已经存在！\n",num);
					printf("若要修改请按'4'，放弃请按'0'！\n");
					scanf("%d",&sign);
					if(sign==4)
						Modify(head);
					else
						return;
				}
				s=s->next; 
			}//while(s)
			if((p=(LinkList)malloc(sizeof(ListNode)))==NULL)  //生成没赋值的新节点 p。
			{
				printf("系统分配存储空间失败！\n");
				printf("退出程序！\n");
				exit(-1);
			}
			strcpy(p->data.num,num);
			printf("\n");
			printf("请输入该职工姓名：");
			scanf("%s",p->data.name);
			getchar();
			printf("\n");
			printf("请输入该职工的性别：（注：男性：male；女性：female）");
			scanf("%s",p->data.sex);
			getchar();
			printf("\n");
			printf("请输入该职工的年龄：");
			scanf("%d",&p->data.age);
			printf("\n");
			printf("请输入该职工的学历：");
			scanf("%s",p->data.education);
			getchar();
			printf("\n");
			printf("请输入该职工的工资：");
			scanf("%d",&p->data.salary);
			printf("\n");
			printf("请输入该职工的电话号码：");
			scanf("%s",p->data.phone);
			getchar();
			printf("\n");
			printf("请输入该职工的住址：");
			gets(p->data.address);
			printf("\n");
			p->next=NULL;   /* 表明这是链表的尾部结点 */
			r->next=p;      /* 将新建的结点加入链表尾部中 */
			r=p;
			saveflag=1;
			printf("\n");
	}//while(1)程序为真，一直执行语句。 
}//void Add函数结束。
//int main()主函数 
//dasdaw主函数测试是否生效。 
void printline()      //打印横线。
{
	printf("--------------------------------------------------------------------------------\n");
}

void printsubject()   //打印各分类标题。
{
	printf(" 工 号\t 姓 名   性 别  年 龄  学 历     工 资    电 话\t\t  住 址\n");
}

void printLinkList(LinkList p)   //打印p结点各个数据成员的值。
{
	printf("  %s   %s  %s   %d  %s  %d   %s   %s\n",p->data.num,p->data.name,p->data.sex,p->data.age,p->data.education,p->data.salary,p->data.phone,p->data.address);
}

void Allemployeeinfo(LinkList head)  //显示所有职工信息。
{
	int count=0;
	ListNode *p;
	p=head->next;
	if(!p)
	{
		printf("***提示***：目前没有存储任何职工记录！\n");
		printf("返回主菜单，请重新选择功能！\n");
		return;
	}
	printf("\t\t\t\t显示结果\n");
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
	printf("已经存储了%d条职工信息！\n",count);
}

void Wrong()
{
	printf("\n***提示***:输入错误！\n");
}

void menu()   //主菜单。
{
	printf("\n");
	printf("\t###################################################################\n");
	printf("\t*      -_-                                              -_-       *\n");
	printf("\t*                                                                 *\n");
	printf("\t*                 < 职工信息管理系统_单链表实现 >                 *\n");
	printf("\t*                                                                 *\n");
	printf("\t*       [1]    录入职工信息            [2]    删除职工信息        *\n");
	printf("\t*       [3]    查询职工信息            [4]    修改职工信息        *\n");
	printf("\t*       [5]    插入职工记录            [6]    统计职工信息        *\n");
	printf("\t*       [7]    排序                    [8]    保存职工信息        *\n");
	printf("\t*       [9]    显示所有职工记录        [0]    退出系统            *\n");
	printf("\t*      -_-                                               -_-      *\n");
	printf("\t*                                                                 *\n");
	printf("\t*                                                 张垚，刘洋      *\n");
	printf("\t*                                                 网络工程1601    *\n");
	printf("\t*                                                                 *\n");
	printf("\t###################################################################\n");
} //void menu菜单结束。

void Del(LinkList L)  //删除职工信息。
{
	int select;       //删除方式选择记录变量。
	ListNode *p,*r;
	char find[20];
	if(!L->next)      //当list无后继结点时，提示和结束Del()函数。
	{
		printf("\n***提示***：没有记录可以删除！\n"); 
		return; 
	} 
	printf("\n按工号删除，请按'1'\n按姓名删除，请按'2'\n");
	printf("\n=====>功能选择：");
	scanf("%d",&select);
	if(select==1)
	{
		printf("请输入要删除的职工工号：");
		scanf("%s",find);
		getchar();
		p=Locatenum(L,find);
		if(p)
		{
			r=L;
			while(r->next!=p)
				r=r->next;  //从第一个结点找起，直到发现r->next=p, 是待删除结点,跳出循环。
			r->next=p->next;
			free(p);
			printf("\n***提示***：该职工信息已成功删除！\n");
			saveflag=1;
		}
		else
			Nofind();
	}//if(select==1).
	else if(select==2)
	{
		printf("请输入要删除的职工姓名：");
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
			printf("\n***提示***：该职工信息已成功删除！\n");
			saveflag=1;
		}
		else
			Nofind();
	}//if(select==2).
	else
		Wrong();    //显示输入错误的话
}//void Del()删除函数结束。

void Search(LinkList L)      //查询职工信息。
{
	int select;
	int salary;
	int sign=0;
	char find[20];
	ListNode *p;             //实现查询操作的临时结构体指针变量。
	if(!L->next)
	{
		printf("\n***提示***：没有职工信息资料可以查询！\n");
		printf("返回主菜单，请重新选择功能！\n");
		return;
	}
	printf("\n按工号查找，请按'1'\n按工资查找，请按'2'\n按姓名查找，请按'3'\n");
	printf("\n=====>功能选择：");
	scanf("%d",&select);
	printf("\n");
	if(select==1)             //工号。
	{
		printf("请输入要查找的工号：");
		scanf("%s",find);
		getchar();
		p=Locatenum(L,find);
		if(p)
		{
			printf("\t\t\t\t   查找结果\n");
			printline();        //打印横线。
			printsubject();     //打印各分类标题。
			printLinkList(p);   //打印p结点各个数据成员的值。
			printline();        //打印横线。
		}
		else
			Nofind();
	}
	else if(select==2)          //工资。
	{
		printf("请输入要查找的工资：");
		scanf("%d",&salary);
		p=Locatesalary(L,salary);
		if(p)
		{
			printf("\t\t\t\t查找结果\n");
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
			printf("\t\t\t\t查找结果\n");
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
	else if(select==3)         //姓名。
	{
		printf("请输入要查找的姓名：");
		scanf("%s",find);
		getchar();
		p=Locatename(L,find);
		if(p)
		{
			printf("\t\t\t\t查找结果\n");
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
}//void Search()查询函数结束。

 void Save(LinkList L)                            //信息保存到文件中。
{
	FILE *fp;
	ListNode *p;
	int count=0;
	int flag=1;
	fp=fopen("Employeeinfo.txt","wb");
	if(fp==NULL)
	{
		printf("\n***提示***：打开文件时发生错误！\n");
		return;
	}
	p=L->next;
	while(p)
	{
		if(fwrite(p,sizeof(ListNode),1,fp)==1)    //将第一个记录结点值写入文件。 
		   { 
			   p=p->next;                         //依次写入下一个结点的值。
			   count++;                           //文件的记录数+1。
		   } 
		   else 
		   { 
			   flag=0; 
			   printf("写入文件过程发生错误！\n");
			   break; 
		   } 
	}//while(p).
	if(count>0)
	{
		printf("\n***提示***：文件保存成功。(有%d条记录已经保存。)\n",count); 
		saveflag=0; 
	}
	else
	{
		system("cls");//清屏。
		printf("文件保存失败！'0'条记录被保存。\n");
	}
	fclose(fp);
}//void Save()函数结束。

void Sort(LinkList L)        //排序功能函数。
{
	ListNode *p,*m,*n;
	int i,j,count=0;
	p=L->next;
	if(!p)
	{
		system("cls");       //清屏。
		printf("无任何职工信息！\n");
		printf("返回主菜单！\n");
		return;
	}
	system("cls");           //清屏。
	printf("按工资从低到高排序：\n");
	printf("***以下为排序前的所有职工记录***\n");
	Allemployeeinfo(L);
	while(p)
	{
		count++;            //不包含头结点的职工信息结点的总个数。
		p=p->next;
	}
	for(i=0;i<count-1;i++)  //单链表的冒泡排序。
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
		printf("***以下为排序后的所有职工记录***\n");
		Allemployeeinfo(L);
		saveflag=1;
		printf("排序成功！\n");
}

void Statistics(LinkList L) //统计职工中的最高工资和最低工资。
{
	ListNode *Max,*Min;
	int i;
	ListNode *t=L->next;
	if(!t)
	{
		system("cls");      //清屏。
		printf("没有储存任何职工记录！\n");
		printf("返回主菜单，请先录入职工信息！\n");
		return;
	}
	system("cls");
	Max=Min=t;
	t=t->next;
	while(t)
	{
		if(Max->data.salary<t->data.salary)
			Max=t;          //Max指针指向最高工资的职工结点。
		if(Min->data.salary>t->data.salary)
			Min=t;          //Min指针指向最低工资的职工结点。
		t=t->next;
	}
	printf("最高工资为：%d\n",Max->data.salary);
	printf("最低工资为：%d\n",Min->data.salary);
	printf("若要查看最低，最高工资的相关职工信息，\n");
	printf("请按'1'，然后按照提示进行相关操作，\n");
	printf("否则，请按'1'除外的任何数字键以退出统计功能，返回主菜单。\n");
	printf("\n=====>功能选择：");
	scanf("%d",&i);
	if(i==1)
		Search(L);          //显示符合要求的职工信息。
	else
		return;
}

void Insert(LinkList L)     //插入新的职工信息。
{
	printf("本功能可以通过姓名和工号查找到符合要求的\n");  //功能介绍。
	printf("相关职工信息，然后将您希望添加进去的新的\n");
	printf("职工信息插入到该职工信息记录的后面。\n");
	ListNode *p,*s;
	char find[20];          //存放工号和姓名的变量。
	int i;
	printf("通过姓名查找，请按'1'。\n");
	printf("通过工号查找，请按'2'。\n");
	printf("返回主菜单，请按'3'。\n");
	printf("\n=====>功能选择：");
	scanf("%d",&i);
	printf("\n");
	if(i==3)
	{
		system("cls");      //退出插入功能，返回主菜单。
		return;
	}
	else if(i==1)
	{
		printf("请输入已在存储记录中的职工姓名：");
		scanf("%s",find);
		getchar();
		p=Locatename(L,find); //定位。
		if(!p)
		{
			printf("您输入的该职工姓名不在信息记录中，请重新核审！\n");
			printf("返回主菜单。\n");
			return;
		}
		s=(LinkList)malloc(sizeof(ListNode));
		if(!s)
		{
			printf("系统分配存储空间失败！\n");
			system("cls");
			return;
		}
		printf("请输入新职工工号：");
		gets(s->data.num);
		printf("\n");
		printf("请输入新职工姓名：");
		scanf("%s",s->data.name);
		getchar();
		printf("\n");
		printf("请输入新职工的性别：（注：男性：male；女性：female）");
		scanf("%s",s->data.sex);
		getchar();
		printf("\n");
		printf("请输入新职工的年龄：");
		scanf("%d",&s->data.age);
		printf("\n");
		printf("请输入新职工的学历：");
		scanf("%s",s->data.education);
		getchar();
		printf("\n");
		printf("请输入新职工的工资：");
		scanf("%d",&s->data.salary);
		printf("\n");
		printf("请输入新职工的电话号码：");
		scanf("%s",s->data.phone);
		getchar();
		printf("\n");
		printf("请输入新职工的住址：");
		scanf("%s",s->data.address);
		getchar();
		printf("\n");
		s->next=p->next;
		p->next=s;
		printf("姓名为：%s的新职工信息已成功插到姓名为：%s的职工信息记录后面。\n",s->data.name,p->data.name);
		saveflag=1;          //资料已改动的存储变量。
	}
	else if(i==2)
	{
		printf("请输入已在存储记录中的职工工号：");
		scanf("%s",find);
		getchar();
		p=Locatenum(L,find); //定位。
		if(!p)
		{
			printf("您输入的该职工工号不在信息记录中，请重新核审！\n");
			printf("返回主菜单。\n");
			return;
		}
		s=(LinkList)malloc(sizeof(ListNode));
		if(!s)
		{
			printf("系统分配存储空间失败！\n");
			system("cls");
			return;
		}
		printf("请输入新职工工号：");
		gets(s->data.num);
		printf("\n");
		printf("请输入新职工姓名：");
		scanf("%s",s->data.name);
		getchar();
		printf("\n");
		printf("请输入新职工的性别：（注：男性：male；女性：female）");
		scanf("%s",s->data.sex);
		getchar();
		printf("\n");
		printf("请输入新职工的年龄：");
		scanf("%d",&s->data.age);
		printf("\n");
		printf("请输入新职工的学历：");
		scanf("%s",s->data.education);
		getchar();
		printf("\n");
		printf("请输入新职工的工资：");
		scanf("%d",&s->data.salary);
		printf("\n");
		printf("请输入新职工的电话号码：");
		scanf("%s",s->data.phone);
		getchar();
		printf("\n");
		printf("请输入新职工的住址：");
		scanf("%s",s->data.address);
		getchar();
		printf("\n");
		s->next=p->next;
		p->next=s;
		printf("姓名为：%s的新职工信息已成功插到姓名为：%s的职工信息记录后面。\n",s->data.name,p->data.name);
		saveflag=1;
	}
	else
	{
		printf("功能选择有误！返回主菜单。\n");
		return;
	}
}

int main()
{
	   LinkList L; /*定义链表*/ // struct Node *list;
	   FILE *fp;  /* 文件指针 */ 
	   int choose; /*保存选择结果变量*/
	   char ch;     /*保存(y,Y,n,N)*/
	   int count=0; /*保存文件中的记录条数（或结点个数）*/
	   struct Node *p,*r;   /*定义记录指针变量*/
	   printf("\t\t\t\t职工信息管理系统\n\t\t\t\t\n"); 
	   L=(struct Node*)malloc(sizeof(struct Node)); 
	   if(!L)
	   {
		   printf("\n系统分配存储空间失败！\n"); /*如没有申请到，打印提示信息*/
		   return 0;             /*返回菜单*/
	   }
	   L->next=NULL; 
	   r=L; 
	   fp=fopen("Employeeinfo.txt","rb"); 
	   if(fp==NULL) 
	   { 
		   printf("\n***提示***：存储职工信息的文件还不存在，是否创建？(y/n)\n"); 
		   scanf("%c",&ch); 
		   if(ch=='y'||ch=='Y') 
		   {
			   fp=fopen("Employeeinfo.txt","ab+"); 
			   printf("文件创建成功！\n");
		   }
		   else 
		   {
			   printf("文件没有创建，无法写入职工信息！\n\n");
			   printf("<-----退 出 职 工 信 息 管 理 系 统----->\n");
			   exit(0); 
		   }
	   } //	if(fp==NULL) 
	   
	   printf("\n=====>提示:文件已经打开,正在导入记录......\n"); 
	   
	   while(!feof(fp)) //没有到文件尾时，循环
	   { 
		   p=(struct Node*)malloc(sizeof(struct Node)); 
		   if(!p)
		   {
			   printf(" memory malloc failure!\n");    /*没有申请成功*/
			   exit(0);       /*退出*/
		   }
		   
		   if(fread(p,sizeof(struct Node),1,fp)) /* 读文件的已有内容放入结点中 */ 
		   { 
			   p->next=NULL; 
			   r->next=p; 
			   r=p; /* 将该结点挂入链表中, r指向最后的节点 */ 
			   count++; 
		   } 
	   } //while(!feof(fp)) 
	   
	   fclose(fp); /* 关闭文件 */ 
	   printf("\n=====>提示:记录导入完毕,共导入%d条记录。\n",count); 
	   while(1) 
	   { 
		   menu(); 
		   printf("\t\t====>请选择：");
		   scanf("%d",&choose);
		   if(choose==0) 
		   { 
			   if(saveflag==1) 
			   { 
				   getchar(); 
				   printf("\n=====>提示:资料已经改动,是否将改动保存到文件中(y/n)?\n"); 
				   scanf("%c",&ch); 
				   if(ch=='y'||ch=='Y') 
					   Save(L); 
			   } 
			   printf("\n***提示***：您已经退出系统,欢迎再次使用！~\n"); 
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



