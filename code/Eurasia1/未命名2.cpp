#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define STACK_INT_SIZE 10
#define STACKINCREMENT 5

typedef int ElemType;


typedef struct SqStack
{
    int *base;
    int *top;
    int stacksize;
}SqStack;


int push(SqStack *s,ElemType e);
int Pop(SqStack *s,ElemType *e);
void PrintStack(SqStack *s);
void DesttroyStack(SqStack *s);
int StackEmpty(SqStack *s);
int GetTop(SqStack *s,ElemType *e);
void conversion(SqStack *s,ElemType);
/*SqStack *InitStack()
{
    SqStack *s;
    s=(SqStack *)malloc(sizeof(SqStack));
    s->top=-1;
    return s;
}*/

void DesttroyStack(SqStack *s)
{
    free(s);
}

int StackEmpty(SqStack *s)
{
    return(s->top==-1);
}

int push(SqStack *s,ElemType e)
{
    if(s->top-s->base==STACK_INT_SIZE)
       return 0;
    *(++s->top)=e;
    return 1;
}
int Pop(SqStack *s,ElemType *e)
{
    if(s->top==-1)
        return 0;
    *e=s->top;
    s->top--;
    return 1;
}

/*int GetTop(SqStack *s,ElemType *e)
{
    if(s->top==-1)
        return 0;
    *e=s->data[s->top];
    return 1;

}
*/
void conversion(SqStack *s,ElemType e)
{
    while(e/2)
    {
        push(s,e%2);
        e/=2;
    }
        push(s,e);
}

void PrintStack(SqStack *s){
    ElemType e;
    while(Pop(s,&e))
        printf("%d",e);
    printf("\n");

}
int main()
{
    int num;
    SqStack *s;

    s=(SqStack *)malloc(sizeof(SqStack));

    s->base=(ElemType *)malloc(STACK_INT_SIZE *sizeof(ElemType));
    if(!s->base) return 0;
    s->top=s->base;
    s->stacksize=STACK_INT_SIZE;

    printf("输入一个十进制数：\n");
    scanf("%d",&num);
    conversion(s,num);
    PrintStack(s);

    return 0;
}

