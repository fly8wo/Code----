#include <iostream>
#include <algorithm>
const int N = 100005;
using namespace std;
double w[N];//�Ŷ�����������
int main()
{
	double c;
	int n;
	cout<<"������������c�Լ��Ŷ��ĸ���n: "<<endl;
	cin>>c>>n;
	cout<<"������ÿ���Ŷ����������ÿո�ֿ���"<<endl;
	for(int i = 0;i<n;i++){
		cin >> w[i];//����ÿ����Ʒ������
	}
	sort(w,w+n);//���Ŷ���������
	double tmp = 0.0;
	int ans = 0;//tmpΪ��װ�ص����ϵĹŶ�������ansΪ��װ�صĹŶ�������
	for(int i = 0; i<n;i++){
		tmp+=w[i];
		if(tmp<=c)
			ans ++;
			else
			break;
	}
	cout<<"������ĹŶ��������ΪAns=";
	cout<<ans<<endl;
	return 0;
}
