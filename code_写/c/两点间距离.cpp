#include <stdio.h>
#include <math.h>
int main()
{
    int x1,x2,y1,y2;
    float t;
    while (scanf("%d %d %d %d",&x1,&y1,&x2,&y2)!=EOF)
{


        t=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));

        printf("%.2f",t);
}
return 0;
}
