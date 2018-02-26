#include<stdio.h>/*实现顺序循环队列的初始化、清空队列、求队长、取队头元素值，取队尾元素值、入队、出队。*/
#include<stdlib.h>
#include <malloc.h>
#define MAXSIZE 50
#define FALSE 0
#define TRUE 1
typedef int QueueElemType;
typedef struct Node
{
 QueueElemType *base;
 int front;
 int rear;
}SqQueue;
int InitSqQueue(SqQueue *Q)
{
 Q->base=(QueueElemType *)malloc(MAXSIZE*sizeof(QueueElemType));
 if(!Q->base)
  return FALSE;
 else
 {
  Q->front=Q->rear=0;
  return TRUE;
 }
}
int ClearQueue(SqQueue *Q)
{
 Q->front=Q->rear=0;
 Q->base=0;
 return TRUE;
}
int EnQueue(SqQueue *Q,QueueElemType e)
{

 if((Q->rear+1)%MAXSIZE==Q->front) return FALSE;
 Q->base[Q->rear]=e;
 Q->rear=(Q->rear+1)%MAXSIZE;
 return TRUE;
}
int ReQueue(SqQueue *Q,QueueElemType e)
{
 if(Q->front==Q->rear) return FALSE;
 e=Q->base[Q->rear-1];
 Q->rear=(Q->rear+1)%MAXSIZE-2;
 return e;
}
int DeQueue(SqQueue *Q,QueueElemType e)
{
 if(Q->front==Q->rear) return FALSE;
 e=Q->base[Q->front];
 Q->front=(Q->front+1)%MAXSIZE;
 return e;
}
void print(SqQueue *Q)
{
 int i;
 if(Q->front==Q->rear)
  printf("\n队列为空 !");

 i=Q->front;
 for(;i<Q->rear;i++)
  printf("%d ",Q->base[i]);
}
int DestroyQueue(SqQueue *Q)//销毁队列
{
 free(Q->base);
 return TRUE;
}
int main()
{
 int max,i,value,x,m;
  SqQueue QU;
 InitSqQueue(&QU);//初始化队列QU
  printf("\n输入队列长度:");
 scanf("%d",&max);
 printf("\n输入入队的值:\n");
  for(i=0;i<max;i++){
  scanf("%d",&value);
  EnQueue(&QU,value);//入队
 }
 printf("\n队列的值为 :");
 print(&QU);

 m=DeQueue(&QU,x);//取队头
 printf("\n队列头的值为: ");
 printf("%d",m);

 m=ReQueue(&QU,x);//取队尾
 printf("\n队尾的值为: ");
 printf("%d",m);


// if(DestroyQueue(&QU))
 if (ClearQueue(&QU))
 {
  printf("\n");
 }
  printf("\n");

}
