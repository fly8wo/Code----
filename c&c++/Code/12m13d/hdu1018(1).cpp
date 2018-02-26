#include<stdio.h>
#include<math.h>

int main()
{
	int T;
	int i,j;
	int n;
	double result;
	scanf("%d",&T);

	for(i=1;i<=T;i++)
	{
		result=0;
		scanf("%d",&n);
		for(j=1;j<=n;j++)
		{
			result+=(log10(j));
		}

		printf("%d\n",(int)result+1);
	}
	return 1;
}
