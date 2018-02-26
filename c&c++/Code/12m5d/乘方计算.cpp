#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int a,n;
	cin >> a >> n;
	int result = a;
	for(int i =0;i < n-1; ++i)
	       result *=a;
		   cout << result; 
	
	
	
	
	
	
	
	return 0;
}
