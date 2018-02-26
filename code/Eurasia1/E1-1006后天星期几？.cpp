#include<stdio.h>
int main()
{
	int i;
	scanf("%d",&i);
	if(i>5 && i<8)
	{
		i=i+2-7;
		printf("%d\n",i);
	}
	else
		   {
		   i=i+2;
		   printf("%d",i); 
	       }
	return 0; 
}
