#include<stdio.h>
int main()
{
    int a,s[20],i=0,rem;
    printf("����������:\n");
    scanf("%d",&a);
    while(a){
        rem=a%2;
        a=a/2;
        s[i++]=rem;
    }
    printf("����Ķ����ƣ�");
    while(i>0)
        printf("%d",s[--i]);
    printf("\n");
    return 0;
}
