#include <stdio.h>
#include <iomanip> 
#include <cmath>
#include <iostream>
using namespace std;
int main()
{
	int a,i,temp;double ave,sum =0;
	cin>>a;
	for(i=0;i<a;i++)
	{
		cin>>temp;
		sum+=temp;
	}
	ave=sum/a;
	
	cout << (int)sum << " " << fixed << setprecision(5) << ave << endl;  
	return 0;
}
