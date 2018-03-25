#include <bits/stdc++.h>

using namespace std;

char s[1010];

int main()
{
	int t = 0;
	int n,m;
	
	scanf("%d",&n);
	getchar();
	gets(s);
	
	int len = strlen(s);
	
	m=len/n;
	if(len>m*n)
		m++;
	for(int j=0;j<n;j++)
	{
		for(int i =m-1;i>=0;i--){
			if(i*n+j>=len)
				printf(" ");
			else
				{
					printf("%c",s[i*n+j]);
				}
		}
		printf("\n");
	}
	
	return 0;
}
