//�������ɸ���������������е����ֵ����Сֵ���Լ��������ĺͣ���������һ����0����־��������� 

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
