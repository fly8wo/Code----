#include<stdio.h>
#include<string.h>
#include<set>
#include<iostream>
#include<string>
using namespace std;
int main()
{
	char s[1000];
	set<string>S;
	while(gets(s)!=NULL&&s[0]!='#')
	{
		int j,k,count=0;
		int  m=strlen(s);
		string b[100];
		char *p;
		p=strtok(s," ") ;
		for( k=0;p!=NULL;k++)
		{
		     b[k]=p;
		     //cout<<b[k]<<endl; 
			 p=strtok(NULL," ") ;
		}
		    for(int i=0;i<k;i++)
			{
			if(S.count(b[i])==0)
			{
			S.insert(b[i]);
		   }
		}
		int ans=S.size();
		printf("%d\n",ans);
		S.clear();
		
	}
	return 0;
}
