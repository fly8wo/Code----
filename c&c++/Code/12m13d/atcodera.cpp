#include <iostream>
using namespace std;
int main()
{
	int a,b;
	float c;
	cin>>a>>b;
	c=(a+b)/2.0;
	if(c-int(c)>=0.5)
				c=c+1;
	printf("%d",int(c));
	

	
	return 0;
 } 
