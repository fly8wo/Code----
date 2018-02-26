#include <stdio.h>
int main()
{
	int a=9;       //1001
	int b=5;       //0101
	              // 1100
	int c= a^b;
		printf("c=%d\n",c);
	a=a^b;
	b=b^a;
	a=a^b;
	printf("a=%d\n,b=%d\n",a,b);
	
	return 0;
 } 
