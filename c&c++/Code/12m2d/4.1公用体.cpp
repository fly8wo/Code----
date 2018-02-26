#include <stdio.h>
union data{
	int a;
	char b;
	int c;
	
};//只能存储一个 所占内存最长的字节 因此 这个为4个字节。与结构体不同。struct 所占用的空间大小涉及字节对齐。大小公式 



int main()
{
	union data data_1;
	data_1.b = 'C';
	data_1.a = 10;
	printf("%p\n,%p\n,%p\n",&data_1.a,&data_1.b,&data_1.c);
	
	return 0;
}
