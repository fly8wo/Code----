#include<stdio.h>  
#include<math.h>  
int main()  
{  
    int  a,n;  
    scanf("%d %d",&a,&n);  
    if(-1000000 <= a <= 1000000 &&1 <= n <= 100001)  
    {  
        printf("%.0lf",pow(a,n));    
    }  
    return 0;  
}  
