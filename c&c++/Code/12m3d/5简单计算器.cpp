#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int m,n,q;
	char s;
	scanf("%d %d %c",&m,&n,&s);
	
	switch(s){
	
	case '+' :
		q = m+n;
		cout <<q;
		break;
	case '-' :
		q = m-n;
		cout<<q;
		break;
		
	case '*' :
		q = m*n;
		cout<<q;
		break;
	case '/' :
		if(n == 0){	
			printf("Divided by zero!");
	}
		else{
			q = m / n;
			cout<<q;
	}
		break;
		default : 
		printf ("Invalid operator!");
		break;
	 		
} 

 } 
