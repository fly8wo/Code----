#include <stdio.h>
int main()
{
    int n,i;
    double s,x,p,max,min;
    while(scanf("%d",&n)!=EOF)
    {
        scanf("%lf",&x);
        s=max=min=x;
        for(i=1;i<n;++i)
        {
            scanf("%lf",&x);
            s+=x;
            max=(x>max)?x:max;
            min=(x<min)?x:min;
        }
            p=(s-max-min)/(n-2);
        printf("%.2lf\n",p);
    }
    return 0;
}
