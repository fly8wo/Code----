#include <iostream>
using namespace std;
int main()
{
	int n1=1378;
	short n2;
	char c = 'a';
	double d1= 7.890;
	double d2;
	n2 = c+1;
	printf("c=%c,n2=%d\n",c,n2);
	c = n1;
	printf("c=%c,n1=%d\n",c,n1);
	n1 = d1;
	printf("n1=%d\n",n1);
	d2 = n1;
	printf("d2=%f\n",d2);

	return 0;
 } 
