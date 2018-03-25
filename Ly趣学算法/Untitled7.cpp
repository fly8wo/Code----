#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,b,a,c;
    cin>>n;
    for(int i =0;i<n;i++)
    {
        scanf("%d%d:%d",&a,&b,&c);
        if(a==0)
                printf("%d %02d:%02d\n",a,b,c);
        else{
            if(a%2==1){
                c=((b%2)*60+c)/2;
                b=b/2;
            }
            else{
                b=b+24;
                c=((b%2)*60+c)/2;
                b=b/2;}
            printf("%d %02d:%02d\n",(a+1)/2,b,c);


        }
    }

    return 0;
}

