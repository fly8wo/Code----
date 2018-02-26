#include<stdio.h>  
  
int main()  
{  
    int a,b,c;
	scanf("%d",&c);  
    while(scanf("%d%d",&a,&b)!=EOF)  
    {  
        printf("%d\n",a+b);  
        printf("\n");  
    }  
    return 0;  
}  
