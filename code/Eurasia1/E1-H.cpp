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
 
 
 //double �� float ��������double���ȸߣ�
// ��Ч����16λ��float����7λ����double�����ڴ���float��������double�������ٶȱ�float���ö� 
