#include <stdio.h>  
#include <stdlib.h>  
  
typedef struct list  
{  
    char data;  
    struct list *next;  
}linklist;  
  
linklist *CreateLinklist_End();                 //尾插法创建链表  
linklist *Linklist_FindPos(linklist *h, int pos);       //通过位置查找节点  
linklist *Linklist_FindDat(linklist *h, char dat, int *i);  //按值查找节点  
int Linklist_Insert(linklist *h, int pos, char dat);        //按位置插入节点  
int Linklist_Delete(linklist *h,  int pos);         //按位置删除节点  
void ShowLinklist(linklist *h);                 //输出显示链表  
  
int main(void)  
{  
    linklist *head, *p;  
    int choice, pos, ans;  
    char dat;  
  
    printf("单链表的相关操作练习\n");  
    printf("尾插法创建一个链表，请依次输入节点字符数据，空格隔开('#'表示输入结束)：\n");  
  
    head = CreateLinklist_End();  
    while(1)  
    {  
        printf("  选择将要进行的操作\n");  
        printf("1.按位置查找节点\n");  
        printf("2,按值查找节点\n");  
        printf("3.按位置插入节点\n");  
        printf("4.按位置删除节点\n");  
        printf("5.输出显示链表\n");  
        printf("6.退出程序\n");  
        printf("做出选择：");  
        scanf("%d", &choice);  
        getchar();          //消除回车键对后面输入带来的影响.  
        switch(choice)  
        {  
        case 1:  
            printf("输入想要查找节点的位置:");  
            scanf("%d", &pos);  
            p = Linklist_FindPos(head, pos);  
            if(p)  
                printf("第%d个节点数据为:%c\n", pos, p->data);  
            else  
                printf("查找的节点不存在\n");  
            break;  
        case 2:  
            printf("输入想要查找的节点的字符数据：");  
            scanf("%c", &dat);  
            p = Linklist_FindDat(head, dat, &pos);  
            if(p)  
            {  
                printf("你查找的节点所在数据为：%c\n", p->data);  
                printf("节点所在的位置为:%d\n", pos);  
            }  
            else  
            {  
                printf("你查找的节点不存在！\n");  
            }  
            break;  
        case 3:  
            printf("请输入你想插入的节点字符数据及位置(空格隔开):");  
            scanf("%c %d", &dat, &pos);  
            ans = Linklist_Insert(head, pos, dat);  
            if(ans)  
                printf("插入节点成功!\n");  
            else  
                printf("插入节点失败\n");  
            break;  
        case 4:  
            printf("请输入你想删除节点所在的位置：");  
            scanf("%d", &pos);  
            ans = Linklist_Delete(head, pos);  
            if(ans)  
                printf("删除节点成功!\n");  
            else  
                printf("删除节点失败！\n");  
            break;  
        case 5:  
            printf("节点数据依次为:");  
            ShowLinklist(head);  
            break;  
        case 6:  
            return 0;  
            break;  
        default:  
            printf("输入的选择无效!\n");  
            break;  
  
        }  
    }  
      
}  
  
//尾插法创建链表  
linklist *CreateLinklist_End()  
{  
    linklist *head, *p, *e;  
    char ch;  
      
    head = (linklist*)malloc(sizeof(linklist));  
    e = head;  
  
    ch = getchar();  
    getchar();          //消除空格带来的影响  
    while(ch != '#')  
    {  
        p = (linklist*)malloc(sizeof(linklist));  
        p->data = ch;  
        e->next = p;  
        e = p;  
        ch = getchar();  
        getchar();      //消除空格带来的影响  
    }  
    e->next = NULL;  
  
    return head;  
}  
  
//通过位置查找节点  
linklist *Linklist_FindPos(linklist *h, int pos)  
{  
    linklist *p;  
    int i = 1;  
  
    p = h->next;  
      
    while(i<pos && p != NULL)  
    {  
        p = p->next;  
        i++;  
    }  
    if(i == pos)            //找到指定位置  
        return p;  
    else  
        return NULL;  
}  
  
//通过数据查找节点  
linklist *Linklist_FindDat(linklist *h, char dat, int *i)  
{  
    linklist *p;  
  
    p = h->next;  
    *i = 1;  
  
    while(p != NULL)  
    {  
        if(p->data != dat)  
        {  
            *i = *i + 1;  
            p = p->next;  
        }  
        else  
            break;          //找到数据则跳出  
    }  
    return p;  
}  
  
//在指定位置插入节点  
int Linklist_Insert(linklist *h, int pos, char dat)  
{  
    linklist *p, *l;  
    int i=0;  
  
    p = h;  
  
    while(i<pos-1 && p->next != NULL)     //找到位置前一个节点  
    {  
        i++;  
        p = p->next;  
    }  
  
    if(i == pos-1)          //找到指定位置  
    {  
        l = (linklist*)malloc(sizeof(linklist));  
        l->data = dat;  
        l->next = p->next;  
        p->next = l;  
    }  
    else  
        return 0;   
    return 1;  
}  
  
//删除指定位置节点  
int Linklist_Delete(linklist *h, int pos)  
{  
    linklist *p, *s;  
    int i = 0;  
  
    p = h;  
  
    while(i<pos-1 && p->next != NULL) //搜索指定位置前一个节点  
    {  
        i++;  
        p = p->next;  
    }  
    if(i != pos-1 || p->next == NULL)    //查找位置非法  
        return 0;  
    s = p->next;  
    p->next = s->next;  
    free(s);  
  
    return 1;  
}  
  
//输出显示节点  
void ShowLinklist(linklist *h)  
{  
    linklist *p;  
  
    p = h->next;  
    while(p != NULL)  
    {  
        printf("%c ", p->data);  
        p = p->next;  
    }  
    printf("\n");  
} 
