#include<cstdio>  
#include<cmath>  
#include <iostream>
using namespace std;  
int n,a,b,c;  
  
int main(){  
    scanf("%d",&n);  
    while(n--){  
        scanf("%d%d",&a,&b);  
        c = (a-100)*1.8;//标准体重   
          
        if(abs(b -c)<(c*0.1)){  
            printf("You are wan mei!\n");  
            cout<<c;
        }  
        if((abs(b-c)>=(c*0.1))&&b<c){  
            printf("You are tai shou le!\n");  
        	cout<<c;
		}  
        if((abs(b-c)>=(c*0.1))&&b>c){  
            printf("You are tai pang le!\n");  
        }  
    }     
      
    return 0;  
}  
