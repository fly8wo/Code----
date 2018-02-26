#include <stdio.h>
int main()
{
	int sum,i,n;
	sum = 0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)  //主要思路 
	sum+=i;//sum=sum+i
	printf("%d",sum);
	
	
	return 0;
}

