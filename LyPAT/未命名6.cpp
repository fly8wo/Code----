#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t,p,s;
	cin>>t;
	while(t--){
		cin>>p;
		if(p==1)
			s=7;
		else if(p==2)
			s=27;
		else if(p>2&&p<=10)
			s=70;
		else if(p==11)
			s=270;
		else if(p>11&&p<=100)
			s=700;
			cout<<s<<endl;
		
	}
	
	
	return 0;
}
