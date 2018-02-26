#include <stdio.h>
int main()
{
    double n;
    double i;
   while( scanf("%lf",&n)!=EOF)
        {
        if(n>=0)
              {

                printf("%.2lf\n",n);}
            else{
                i= -(n);
                    printf("%.2lf\n",i);}
        }
    return 0;
}
