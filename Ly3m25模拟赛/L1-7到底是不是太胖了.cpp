#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdio>
using namespace std;
int main()
{
	double c,n,a,b; 
	cin>>n;
	while(n--){
		cin>>a>>b;
		c=(a-100.0)*1.8;
		
		if((abs(b-c)<(c*0.1))){
			printf("You are wan mei!\n");
		}
		if((abs(b-c)>=(c*0.1))&&b<c){
			printf("You are tai shou le!\n");
		}
		if((abs(b-c)>=(c*0.1))&&b>c){
			printf("You are tai pang le!\n");
		}
	}
	
	return 0;
 } 
