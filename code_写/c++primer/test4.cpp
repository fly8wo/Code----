#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<string>
#include<algorithm>
#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	if(a + b > c + d)	puts("Left");
	else if(a + b < c + d)	puts("Right");
	else puts("Balanced");
	return 0;
}
