#include <stdio.h>  
int main()  
{  
int N,i,sum,M,temp;  
scanf("%d",&N);  
while(N)  
{  
  scanf("%d",&M);  
  sum=0;  
  
     for(i=0;i<M;i++)  
{  
   scanf("%d",&temp);  
   sum+=temp;  
}  
         if(N!=1)  
    printf("%d\n\n",sum);  
         else  
  
    printf("%d\n",sum);  
    N--;  
  
}  
  
  return 0;  
}  
