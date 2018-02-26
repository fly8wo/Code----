//ì³²¨ÄÉÆõÊıÁĞ
#include <iostream>
using namespace std;
int main()
{
	int a1=1,a2=1;int k;
	cin >> k;
	if( k == 1 || k==2)
		cout<<1<<endl;
	else {
		int sum;
		for(int i=0;i<k-2;++i){
			sum = a1+a2;
			a1=a2;
			a2=sum;
		}
		cout<<a2<<endl;
	}	
	
	return 0;
 } 
