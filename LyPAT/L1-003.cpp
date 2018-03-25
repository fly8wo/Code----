#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
double  c,n,a,b;


int main(){
    cin>>n;
    while(n--){
        cin>>a>>b;
        c = (a-100.0)*1.8;

        if((abs(b-c)<(c*0.1))){
            printf("You are wan mei!\n");

        }
         if((abs(b-c)>=(c*0.1))&&b<c){
            printf("You are tai shou le!\n");

        }
        if((abs(b-c)>=(c*0.1))&&b>c){
            printf("You are tai pang le!\n");
        }
    }

    return 0;
}

