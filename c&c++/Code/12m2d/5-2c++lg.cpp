#include <iostream>
#include <stdlib.h>
using namespace std;
int main()
{
	int *p =new int[1000];
	if(NULL == p)
	{
		system("pause");
		return 0;
	}
	p[0] = 10;
	p[1] = 20;
	cout << p[0]<<","<<p[1]<<endl;
//	int *p= new int(20);
	delete []p;
	p = NULL;
	system("pause");
	return 0;
}
