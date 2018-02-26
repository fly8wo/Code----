#include <iostream>
#include <cstdio>
using namespace std;
int func(n)
{
	int r;
	if(n==0 || n==1)
	r=1;
	else 
		r=n*func(n-1)

}
int main()
{
	while(scanf("%d",&t)!=EOF)
	{
		func()
		
	}
	
	
	
	
	
	
	return 0;
 } 
