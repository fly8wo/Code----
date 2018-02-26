//求解阶乘的和
#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int sum =0 ;
	int fac=1;
	for (int i=1;i<=n;++i){
	//	int fac=1;
	//	for(int j = 1 ; j <=i;++j)
			fac *=i ;
		sum +=fac;
		
	}
	cout<<sum; 
	return 0;
 } 
