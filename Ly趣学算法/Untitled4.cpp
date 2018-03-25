#include <bits/stdc++.h>
using namespace std;
int main()
{
    int h,m;
    scanf("%d:%d",&h,&m);
    if(h>0&&h<=11)
            printf("Only %02d:%02d. Too early to Dang.",h,m);
    else if(h==12){
        if(m==0)
            printf("Only %02d:%02d. Too early to Dang.",h,m);
        else
            printf("Dang");
    }
    else {
        for(int i = 0;i<h%12;i++)
                printf("Dang");
        if(m!=0)
            printf("Dang");

    }
   return 0;
}


