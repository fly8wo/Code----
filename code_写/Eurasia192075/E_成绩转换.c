#include<stdio.h>/*ʵ��˳��ѭ�����еĳ�ʼ������ն��С���ӳ���ȡ��ͷԪ��ֵ��ȡ��βԪ��ֵ����ӡ����ӡ�*/
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
  printf("\n����Ϊ�� !");

 i=Q->front;
 for(;i<Q->rear;i++)
  printf("%d ",Q->base[i]);
}
int DestroyQueue(SqQueue *Q)//���ٶ���
{
 free(Q->base);
 return TRUE;
}
int main()
{
 int max,i,value,x,m;
  SqQueue QU;
 InitSqQueue(&QU);//��ʼ������QU
  printf("\n������г���:");
 scanf("%d",&max);
 printf("\n������ӵ�ֵ:\n");
  for(i=0;i<max;i++){
  scanf("%d",&value);
  EnQueue(&QU,value);//���
 }
 printf("\n���е�ֵΪ :");
 print(&QU);

 m=DeQueue(&QU,x);//ȡ��ͷ
 printf("\n����ͷ��ֵΪ: ");
 printf("%d",m);

 m=ReQueue(&QU,x);//ȡ��β
 printf("\n��β��ֵΪ: ");
 printf("%d",m);


// if(DestroyQueue(&QU))
 if (ClearQueue(&QU))
 {
  printf("\n");
 }
  printf("\n");

}
