//使用一个函数找到一个整型数组中的最大值或最小值
#include <iostream>
using namespace std;

namespace CompA{
	int getMaxOrMin(int *arr,int count,bool isMax)
{
	int temp = arr[0];
	for(int i =1; i< count;i++)
	{
		if(temp<arr[i])
		{
			temp =arr[i];
		}
		if(temp > arr[i])
		{
			temp = arr[i];
		}
	}
	return temp;

 }
}
 int main(void)
 {
 	int arr1[4] = {3,5,1,7};
 	bool isMax = false;
 	cin >> isMax;
 	cout << CompA::getMaxOrMin(arr1,4,isMax) <<endl;	
 	return 0;
  } 
