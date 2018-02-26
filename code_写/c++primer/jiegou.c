
#include<stdio.h>
#include<malloc.h>
#include<math.h>
#include<string.h>
#include "process.h"
#define SIZE 100
#define STACKINCREMENT 10
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;
typedef struct
{
  int a;
} SElemType;
typedef struct
{
  SElemType *base;
  SElemType *top;
  int stacksize;
} SqStack;
SqStack S; //定义全局变量
Status InitStack(SqStack *S)
{
  S->base=(SElemType *)malloc(SIZE*sizeof(SElemType));
  if(!S->base) exit(OVERFLOW);
  S->top=S->base;
  S->stacksize=SIZE;
  return OK;
}
Status Push(SqStack *S,SElemType e)
{
  if(S->top-S->base>=S->stacksize)
  {
    S->base=(SElemType *)malloc((S->stacksize+STACKINCREMENT)*sizeof(SElemType));
    if(!S->base) exit(OVERFLOW);
    S->top=S->base+S->stacksize;
    S->stacksize+=STACKINCREMENT;
  }
  *S->top++=e;
  //printf("%dwww\n",*--S->top);
  return OK;
}
Status Stackempty(SqStack *S)
{
  if(S->top==S->base)
    return TRUE;
  else
    return FALSE;
}
Status Pop(SqStack *S,SElemType *e)
{
  if(S->top==S->base) return ERROR;
  *e=*--S->top;
  return OK;
}
Status DtoBTrans(int N,SqStack *S)
{
  SElemType e;
  while(N)
  {
    e.a=N%2;
    Push(S,e);
    N=N/2;
  }
  while(!Stackempty(S))
  {
    Pop(S,&e);
    printf("%d",e);
  }
  return OK;
}
int main()
{
  int x;
  InitStack(&S);
  printf("请输入十进制数：");
  scanf("%d",&x);
  DtoBTrans(x,&S);
}
