#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
	int a,b;
  	cin>>a>>b;

  	printf("%d/",a);
	if(b>=0){
  	printf("%d=",b);
	}else
		printf("(%d)=",b);
	if(b==0){
    	printf("Error");
			}
	else
			printf("%.2f",a*1.0/b);


	return 0;
}
