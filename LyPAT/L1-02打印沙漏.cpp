
#include <iostream>
using namespace std;
int main()
{
	int n,i=1,j,d,max,sum=1;
	char a;
	cin>>n>>a;
	while(1){
		i+=2;
		if(sum+i*2>n){
			max=i-2;
			d=n-sum;
			break;
		}
		sum+=i*2;
	}
	for(i=max;i>=1;i-=2){
		for(j=0;j<max;j++){
			if(j<(max-i)/2)
				cout<<" ";
				else if(j>=(max+i)/2)
					break;
					else
						cout<<a;
		}
		cout<<endl;
	}
	for(i=3;i<=max;i+=2)
	{
		for(j=0;j<max;j++)
		{
			if(j<(max-i)/2){
					cout<<" ";
			}else if(j>=(max+i)/2)
			break;
			else
				cout<<a;
		}
		cout<<endl;
	}
	cout<<d<<endl;
	
	return 0;
 } 
  
