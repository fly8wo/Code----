#include <stdio.h>
int main()
{
	int i,j,k;
	while(scanf("%d",&k)!=EOF)
	for(i=0;i<=k;i++)
	{
	
 	  for(j=1;j<=i;j++)
 	  {
 	  	printf("%d * %d=%d    ",j,i,i*j);
 	  	
 	  	
	   }
	   printf("\n");
	   }
	
	return 0;
}
