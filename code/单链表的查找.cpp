#include <stdio.h>  
#include <stdlib.h>  
  
typedef struct list  
{  
    char data;  
    struct list *next;  
}linklist;  
  
linklist *CreateLinklist_End();                 //β�巨��������  
linklist *Linklist_FindPos(linklist *h, int pos);       //ͨ��λ�ò��ҽڵ�  
linklist *Linklist_FindDat(linklist *h, char dat, int *i);  //��ֵ���ҽڵ�  
int Linklist_Insert(linklist *h, int pos, char dat);        //��λ�ò���ڵ�  
int Linklist_Delete(linklist *h,  int pos);         //��λ��ɾ���ڵ�  
void ShowLinklist(linklist *h);                 //�����ʾ����  
  
int main(void)  
{  
    linklist *head, *p;  
    int choice, pos, ans;  
    char dat;  
  
    printf("���������ز�����ϰ\n");  
    printf("β�巨����һ����������������ڵ��ַ����ݣ��ո����('#'��ʾ�������)��\n");  
  
    head = CreateLinklist_End();  
    while(1)  
    {  
        printf("  ѡ��Ҫ���еĲ���\n");  
        printf("1.��λ�ò��ҽڵ�\n");  
        printf("2,��ֵ���ҽڵ�\n");  
        printf("3.��λ�ò���ڵ�\n");  
        printf("4.��λ��ɾ���ڵ�\n");  
        printf("5.�����ʾ����\n");  
        printf("6.�˳�����\n");  
        printf("����ѡ��");  
        scanf("%d", &choice);  
        getchar();          //�����س����Ժ������������Ӱ��.  
        switch(choice)  
        {  
        case 1:  
            printf("������Ҫ���ҽڵ��λ��:");  
            scanf("%d", &pos);  
            p = Linklist_FindPos(head, pos);  
            if(p)  
                printf("��%d���ڵ�����Ϊ:%c\n", pos, p->data);  
            else  
                printf("���ҵĽڵ㲻����\n");  
            break;  
        case 2:  
            printf("������Ҫ���ҵĽڵ���ַ����ݣ�");  
            scanf("%c", &dat);  
            p = Linklist_FindDat(head, dat, &pos);  
            if(p)  
            {  
                printf("����ҵĽڵ���������Ϊ��%c\n", p->data);  
                printf("�ڵ����ڵ�λ��Ϊ:%d\n", pos);  
            }  
            else  
            {  
                printf("����ҵĽڵ㲻���ڣ�\n");  
            }  
            break;  
        case 3:  
            printf("�������������Ľڵ��ַ����ݼ�λ��(�ո����):");  
            scanf("%c %d", &dat, &pos);  
            ans = Linklist_Insert(head, pos, dat);  
            if(ans)  
                printf("����ڵ�ɹ�!\n");  
            else  
                printf("����ڵ�ʧ��\n");  
            break;  
        case 4:  
            printf("����������ɾ���ڵ����ڵ�λ�ã�");  
            scanf("%d", &pos);  
            ans = Linklist_Delete(head, pos);  
            if(ans)  
                printf("ɾ���ڵ�ɹ�!\n");  
            else  
                printf("ɾ���ڵ�ʧ�ܣ�\n");  
            break;  
        case 5:  
            printf("�ڵ���������Ϊ:");  
            ShowLinklist(head);  
            break;  
        case 6:  
            return 0;  
            break;  
        default:  
            printf("�����ѡ����Ч!\n");  
            break;  
  
        }  
    }  
      
}  
  
//β�巨��������  
linklist *CreateLinklist_End()  
{  
    linklist *head, *p, *e;  
    char ch;  
      
    head = (linklist*)malloc(sizeof(linklist));  
    e = head;  
  
    ch = getchar();  
    getchar();          //�����ո������Ӱ��  
    while(ch != '#')  
    {  
        p = (linklist*)malloc(sizeof(linklist));  
        p->data = ch;  
        e->next = p;  
        e = p;  
        ch = getchar();  
        getchar();      //�����ո������Ӱ��  
    }  
    e->next = NULL;  
  
    return head;  
}  
  
//ͨ��λ�ò��ҽڵ�  
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
    if(i == pos)            //�ҵ�ָ��λ��  
        return p;  
    else  
        return NULL;  
}  
  
//ͨ�����ݲ��ҽڵ�  
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
            break;          //�ҵ�����������  
    }  
    return p;  
}  
  
//��ָ��λ�ò���ڵ�  
int Linklist_Insert(linklist *h, int pos, char dat)  
{  
    linklist *p, *l;  
    int i=0;  
  
    p = h;  
  
    while(i<pos-1 && p->next != NULL)     //�ҵ�λ��ǰһ���ڵ�  
    {  
        i++;  
        p = p->next;  
    }  
  
    if(i == pos-1)          //�ҵ�ָ��λ��  
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
  
//ɾ��ָ��λ�ýڵ�  
int Linklist_Delete(linklist *h, int pos)  
{  
    linklist *p, *s;  
    int i = 0;  
  
    p = h;  
  
    while(i<pos-1 && p->next != NULL) //����ָ��λ��ǰһ���ڵ�  
    {  
        i++;  
        p = p->next;  
    }  
    if(i != pos-1 || p->next == NULL)    //����λ�÷Ƿ�  
        return 0;  
    s = p->next;  
    p->next = s->next;  
    free(s);  
  
    return 1;  
}  
  
//�����ʾ�ڵ�  
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
