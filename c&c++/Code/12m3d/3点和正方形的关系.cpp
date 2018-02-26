/*#include <stdio.h>
int main()
{
	float x,y;
	scanf("%f %f",&x,&y);
	if(x>=-1.0&&x<=1.0&&y>=-1.0&&y<=1.0)
		printf("yes");
		else
		 printf("no");
	
	return 0;
 } */
 
#include<stdio.h>
#include<math.h>
int main()
{
  float x,y;
  scanf("%f,%f",&x,&y);
  if(fabs(x)<=1.0&&fabs(y)<=1.0)
       printf("yes");
  else
       printf("no");
  return 0;
}
