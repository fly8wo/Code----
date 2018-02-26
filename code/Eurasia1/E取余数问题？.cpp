#include <stdio.h>
int main() 
{
	int a,b,c;
		while(~scanf("%d %d",&a,&b))
		{
			c=a%b;
			printf("%d %% %d=%d",a,b,c); 
		}

	return 0;
}

/*3%10=£¿   3%2=£¿   100%10=£¿   100*9=?
	-2%10=?    3%10000=?    100%3=£¿ 


  */ 
