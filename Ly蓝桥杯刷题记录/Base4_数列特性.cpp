
��������

����n�������ҳ���n���������ֵ����Сֵ���͡�
�����ʽ

��һ��Ϊ����n����ʾ���ĸ�����

�ڶ�����n������Ϊ������n������ÿ�����ľ���ֵ��С��10000��
�����ʽ
������У�ÿ��һ����������һ�б�ʾ��Щ���е����ֵ���ڶ��б�ʾ��Щ���е���Сֵ�������б�ʾ��Щ���ĺ͡�
��������
5
1 3 -2 4 5
�������
5
-2
11
���ݹ�ģ��Լ��
1 <= n <= 10000��


#include <iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i =0;i<n;i++)
		cin>>a[i];
	int min = a[0];
	int max = a[0];
	int sum = a [0];
	for(int i=1;i<n;i++){
		if(a[i]<min)
			min=a[i];
		if(a[i]>max)
			max=a[i];
		sum+=a[i];
	}
	cout<<max<<endl;
	cout<<min<<endl;
	cout<<sum<<endl;


	return 0;
}
