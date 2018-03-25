#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int main()
{
  int h,m;
  scanf("%d:%d",&h,&m);//%d:%d"
  if((h==12&&m>0)||(h>12&&h<24)){
    h-=12;
    int i;
    if(m>0)
      h+=1;
      for(i=0;i<h;i++)
        printf("Dang");
        printf("\n");
  }else if(h==24)
    h=0;
  else 
      printf("Only %02d:%02d.  Too early to Dang.\n",h,m);
  
  return 0;
}

