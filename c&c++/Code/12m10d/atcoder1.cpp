#include <iostream>
using namespace std;
int main()
{
	int a;
	cin>>a;
		//读入一个三位数，求出它当中有几个1.
	if(a==111){
		cout<<"3"<<endl;
	}	if(a==101||a==110)
			{
			cout<<"2"<<endl;
			}
			if(a==11)
				cout<<"2"<<endl;
			if(a==10)
				cout<<"1"<<endl;
				if(a==1)
					cout<<"1"<<endl;
			if(a==010||a==100)
				{
				cout<<"1"<<endl;
				}if(a==000)
					{
					cout<<"0"<<endl;
						}
	
	return 0;
	 } 
