//(���)����������n��m����1��n��n�����У�ȡ��������ͬ������ʹ�������m�����ӣ����ж����ֲ�ͬ��ȡ���� 
#include <iostream>
using namespace std;
int main()
{	int n,m;
 int total = 0;
 cin >> n>>m;
 for(int i =1;i<n; ++i){
 	for(int j = i+1;j<=n;++j)
 		if(m%(i+j)==0)
 		 	++total;
 }
	cout <<total<<endl;
 	return 0;	
}
