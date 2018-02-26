#include <iostream>
#include <cstdio>
using namespace std;
int main() 
{
	int n,i,cnt=0,ck;
	cin>>n;
	int a[n];
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	while(1){
		ck=0;
		for(i=0;i<n;i++){
			if(a[i]%2==0){
				ck++;		
		}else{
			break;			
			}	
		}
		if(ck==n)
		{
			for(i=0;i<n;i++)
			{
				a[1]=a[i]/2;
			}
			cnt++;
		}
		else{
			break;
		}
	}
	cout << cnt <<endl;	
	
	return 0;
}
