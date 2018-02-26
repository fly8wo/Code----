//hud1018
#include<stdio.h>
#include<math.h>
int main()
{
	int t,a,i;
	double sum;
	scanf("%d",&t);/*n的位数计算公式[lg(n)]+1;
	               n的阶乘等于n(n-1)(n-2)...1;
				   所以位数为[lg(n(n-1)(n-2)..1)]+1;
				   即lgn+lg(n-1)+lg(n-2)+....+lg(1)+1;必须double型*/ 
	while(t--)
	{
		sum=0;
		scanf("%d",&a);
		for(i=1;i<=a;i++)
		sum+=log10((double)i);
		printf("%d\n",(int)sum+1);
	}
	return 0;
}
