#include<stdio.h>  
void fun();  
int main()  
{  
    fun();  
    return 0;  
}  
void fun()  
{  
    int i = 3;  
    printf("%d,%d,%d,%d\n",i++,i++,++i,i+5);  
    printf("%d\n",i);  
}  
