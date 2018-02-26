#include <stdio.h>
int main()
{
	int a,b,c,d,e,f;
	double ave; 
	scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
	ave=(a+b+c+d+e+f)/6.0;
	printf("%.1f",ave);

	return 0;
 } 
 
 
 //double 和 float 的区别是double精度高，
// 有效数字16位，float精度7位。但double消耗内存是float的两倍，double的运算速度比float慢得多 
