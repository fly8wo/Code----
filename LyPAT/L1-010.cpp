#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
	int a,b,c;
	cin>>a>>b>>c;
	if(b<a){
		a+=b;
		b = a-b;
		a = a-b;
	}if(c<b){
		b+=c;
		c=b-c;
		b=b-c;
	}if(b<a){
		a+=b;
		b = a-b;
		a= a-b;
	}
	cout<<a<<"->"<<b<<"->"<<c;


	return 0;
}
