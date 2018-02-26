#include <iostream>
#include <cstdio>
using namespace std; 
int main()
{
	
	int n,s,x,y;
	cin >> n >> x >> y;
	
	if(y%x==0)
		s=n-y/x;
	 if(y%x!=0)
	      s=n-y/x-1;
		  if(s>0){
			cout<<s<<endl;
				}
 	else 
		   cout<<"0"<<endl;
	
	
	return 0;
}
