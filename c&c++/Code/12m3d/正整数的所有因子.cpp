//写入一个程序，输入一个正整数N,从小到大输出它的所有的因子。 


#include <iostream>
using namespace std;
int main()
{
	int m;
	cin >> m;
	for(int i =m ;i >= 1; --i)
				if(m%i==0)
					cout << i <<endl;
	
	
	return 0;
}
