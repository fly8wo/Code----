#include <iostream>
using namespace std;
double EPS=0.001;
int main()
{
	double a;
	cin >>a;
	if(a>=0){
		double x =a/2, lastx=x+1+EPS;//ȷ�����ٽ���һ�ε���
			while(x-lastx>EPS || lastx - x >EPS){
				lastx=x;
				x=(x+a/x)/2;
				
			} 
		
		cout<<x;
		
	}
		else
		
		cout<<"It can't be nagitive";
	return 0;
}
