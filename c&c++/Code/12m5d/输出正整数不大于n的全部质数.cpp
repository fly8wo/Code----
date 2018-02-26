#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	for(int i =2;i<=n;++i)
						{
							int k;
							for(k=2;k<i;++k){
								if(i%k==0)
								break;								
							}
						if( k == i)
						cout << i <<endl;
							}	
	
	return 0;
	
}
