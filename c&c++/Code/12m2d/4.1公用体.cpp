#include <stdio.h>
union data{
	int a;
	char b;
	int c;
	
};//ֻ�ܴ洢һ�� ��ռ�ڴ�����ֽ� ��� ���Ϊ4���ֽڡ���ṹ�岻ͬ��struct ��ռ�õĿռ��С�漰�ֽڶ��롣��С��ʽ 



int main()
{
	union data data_1;
	data_1.b = 'C';
	data_1.a = 10;
	printf("%p\n,%p\n,%p\n",&data_1.a,&data_1.b,&data_1.c);
	
	return 0;
}
