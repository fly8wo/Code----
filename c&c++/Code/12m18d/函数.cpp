#include <iostream>
using namespace std;
#define EPS 0.01
double Sqrt(double a)
{
	double x =a/2,lastX=x+1+EPS;
	while(x-lastX>EPS || lastX -x > EPS){
	
			lastX=x;
			x=(x+a/x)/2;
		}
		return x;
}
double Distance(double x1,double y1,double x2,double y2)
{//求两点（x1,y1）,(x2 ,y2)的距离
	return Sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)); 
	
	
}
int main()
{
	int x1,y1,x2,y2,x3,y3;
	cin>>x1>>y1>>x2>>y2 >>x3>>y3;
	cout<<Distance(x1,y1,x2,y2) <<endl;
	//输出（x1,y1）到（x2,y2）的距离
	cout<<Distance(x1,y1,x3,y3)<<endl;
	cout<<Distance(x3,y3,x2,y2)<<endl; 
	
	
	return 0;
	}	
	
	
	
	
	
	
	
