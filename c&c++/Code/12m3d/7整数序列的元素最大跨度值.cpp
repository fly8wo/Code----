#include<stdio.h>
int main()
{
	int a[10000];
	int i=1,j=1,max,min,t;
	scanf("%d",&a[0]);
//	while(getchar()!='\n')
	{
		scanf("%d",&a[i]);
		i++;
		j++;
	}
	i=1;
	max=a[0];
	while(i<j)
	{
		if(max<a[i])
		{
			t=a[i];
			max=t;
		}
		i++;
	}
	min=a[0];
	i=1;
	while(i<j)
	{
		if(min>a[i])
		{
			t=a[i];
			min=t;
		}
		i++;
	}
	printf("%d\n",j);
	printf("%d\n",max-min);
	return(0);
}

