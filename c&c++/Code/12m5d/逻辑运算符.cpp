#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int a= 0,b=1;
	bool n =(a++ )  && (b++);
	cout<< a <<" , " << b << endl;
	n = a ++ && b++;
	cout << a << " , "<<b <<endl;
	n =  a++ || b++;
	cout << a << " , "<<b <<endl;
	 
	
	
	
	
	
	
	
	return 0;
}
