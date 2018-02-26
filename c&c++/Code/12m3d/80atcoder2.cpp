#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
	int m;int sum=0;
	cin >> m ;
	//要判断m为几位数？
	while(m>=1)
	{	
		m=m/10;
		sum++;
	}
	 c=m/(sum*10)+m/(sum)
	a = m/100;
	b = m/10%10;
 	d = m % 10;
	c =d +a+b;
	if(m % c==0)
		printf("Yes");
	else
		printf("No");
	
	return 0;
}
