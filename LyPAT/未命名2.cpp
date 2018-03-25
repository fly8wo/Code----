#include <stdio.h>
#include <stdlib.h>

int main()
{
    int c,b,a,x;

    scanf("%d",&x);
    c =x%10;
    b=(x/10)%10;
    a =x/100;
	int i; 
       for(i=0;i<a;i++)
       {
          printf("B");
       }
    for(i=0;i<b;i++)
        {
            printf("s");
        }
    for(i=1;i<=c;i++)
        {
            printf("%d",i);
        }
        printf("\n");


    return 0;
}
