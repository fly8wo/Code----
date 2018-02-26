#include<stdio.h>  
#include<malloc.h>  
#define ERROR 0  
#define OK 1  
#define STACK_INT_SIZE 10  
#define STACKINCREMENT 5  
typedef  int ElemType;   
typedef struct{  
    ElemType *base;  
    ElemType *top;  
    int stacksize;       
}SqStack;  
  
   
int push(SqStack *S,ElemType e);   
int Pop(SqStack *S,ElemType *e);  
void PrintStack(SqStack *S);   
  
  
int Push(SqStack *S,ElemType e){  
    if(S->top-S->base==STACK_INT_SIZE)  
        return 0;  
    *(++S->top)=e;  
    return 1;  
} 
  
int Pop(SqStack *S,ElemType *e){  
    if(S->top==S->base)  
        return 0;  
    *e=*S->top;  
    S->top--;  
    return 1;  
}
  
void Conversion(SqStack *S,ElemType e)  
{  
    while(e/2)  
    {  
        Push(S,e%2);  
        e/=2;  
    }  
    Push(S,e);  
  
}  
  
void PrintStack(SqStack *S){  
    ElemType e;  
    while(Pop(S,&e))  
        printf("%d",e);  
    printf("\n");  
}
  
int main(){  
    int num;  
    SqStack *S;  
    S=(SqStack *)malloc(sizeof(SqStack));  
    S->base=(ElemType *)malloc(STACK_INT_SIZE *sizeof(ElemType));  
    if(!S->base) return ERROR;  
    S->top=S->base;  
    S->stacksize=STACK_INT_SIZE;  
  
    printf("请输入要转换的十进制数字：\n");  
    scanf("%d",&num);  
    Conversion(S,num);  
    PrintStack(S);  
    return 0;  
}       
