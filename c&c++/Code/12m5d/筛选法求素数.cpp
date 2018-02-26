#include <iostream>//筛选法求素数 
using namespace std;
#define MAX_NUM 100
char isPrime[MAX_NUM + 10];
int main()
{
	for( int i=2;i<=MAX_NUM;++i)
			isPrime[i] = 1;
		for(int i =2;i<=MAX_NUM;++i){
			if( isPrime[i])//只标记素数倍数 
				for( int j = 2*i ; j<=MAX_NUM; j += i)
							isPrime[j] = 0;
				}	
	for(int i = 2;i <=MAX_NUM;++i)
	  			if( isPrime[i])
	  			 	 cout<< i<<endl;
	
	return 0;
 } 
