#include "stdio.h"
int main()
{
	int n,i,b,c,s=0	;
	int a[1010];
	scanf("%d",&n);
	for(i=n;i>0;i--)
	{
		scanf("%d%d",&b,&c);
		for(i=1;i<b+1;i++)
		scanf("%d",&a[i]);	
		
       for(i=1;i<b+1;i++)
		{if(a[i]-a[c]>0)
		s++;
		}
		printf("%d\n",s);
		s=0;
	}
return 0;
}	
