#include <cstdio>    
#include <iostream>    
#include <cmath>    
int main() {    
    double a,b,c,d;    
    double x1,x2;    
    double m,n;     
    double esp=pow(10,-7);    
    scanf("%lf%lf%lf",&a,&b,&c);    
    d=b*b-4*a*c;    
    if(d==0||d>0)    
           {    
               if(d==0)    
               {    
                   x1=x2=(-b+sqrt(d))/(2*a);    
                   printf("x1=x2=%.5lf\n",x1,x2);    
               }    
               else    
               {    
                   x1=(-b+sqrt(d))/(2*a);    
                   x2=(-b-sqrt(d))/(2*a);    
                   printf("x1=%.5lf;x2=%.5lf\n",x1,x2);        
               }    
           }    
           else    
           {    
               m=-b/(2*a)+esp;    
               n=sqrt(-d)/(2*a);    
               printf("x1=%.5lf+%.5lfi;x2=%.5lf-%.5lfi\n",m,n,m,n);            
           }       
           return 0;    
  }    
