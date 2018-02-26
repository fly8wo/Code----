//输入若干整数 输出最大值 
#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	freopen("c:\\tmp\\test.txt","r",stdin);       
	int n,mx;
	cin >> mx;
	while(cin >> n){
	
	if(mx<n) 
		mx=n;
	}
	cout<<mx<<endl;

	return 0;
 } 
