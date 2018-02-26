//输入若干个正整数，输出其中的最大值，最小值，以及所有数的和，输入最后的一个数0，标志输入结束。 

#include <iostream>
using namespace std;
int main()
{
	int sum = 0,maxN=0,minN=101,n;
	cin >> n;
	while(n){
		if(n>maxN) maxN=n;
		if(n<minN) minN=n;
		sum+=n;
		cin >> n; 
	} 
	cout << maxN<<" "<<minN<<" "<<sum;

	
	return 0;
}
