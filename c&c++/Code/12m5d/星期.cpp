#include <iostream>
#include <string>
using namespace std;
int main()
{
	string weekdays[]={ "Monday","Tuesday","wednesday","Thursday","Friday","saturday","sunday" 	};
	int n;
	cin >> n;
	if(n>7||n<1)
		cout<<"erro";
		else
		 	cout<<weekdays[n-1];
	
	
	
	
	
	
	
	
	return 0;
}
