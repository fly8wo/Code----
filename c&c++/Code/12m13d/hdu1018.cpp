//hud1018
#include<stdio.h>
#include<math.h>
int main()
{
	int t,a,i;
	double sum;
	scanf("%d",&t);/*n��λ�����㹫ʽ[lg(n)]+1;
	               n�Ľ׳˵���n(n-1)(n-2)...1;
				   ����λ��Ϊ[lg(n(n-1)(n-2)..1)]+1;
				   ��lgn+lg(n-1)+lg(n-2)+....+lg(1)+1;����double��*/ 
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
