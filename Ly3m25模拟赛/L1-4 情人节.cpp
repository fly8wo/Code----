#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
	int i;
	char name[17][17];
	for(i=1;i<15;i++)
	{
		scanf("%s",name[i]);
		if(name[i][0] == '.')
				break;
	}
	if(i-1<2)
		cout<<"Momo... No one is for you ..."<<endl;
	else if(i-1<14)
		printf("%s is the only one for you...",name[2]);
	else
		printf("%s and %s are inviting you to dinner...",name[2],name[14]);
	
	
	return 0;
}
