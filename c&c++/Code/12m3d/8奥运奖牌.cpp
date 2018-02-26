#include <stdio.h>
#include <stdlib.h>
int main()
{
	int n,i,a,b,c,a_sum=0,b_sum=0,c_sum=0,sum;
	
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
	   scanf("%d%d%d",&a,&b,&c);
	   a_sum+=a;
	   b_sum+=b;
	   c_sum+=c;
	}
	sum=a_sum+b_sum+c_sum;
	printf("%d %d %d %d\n",a_sum,b_sum,c_sum,sum);

	

	return 0;
}
