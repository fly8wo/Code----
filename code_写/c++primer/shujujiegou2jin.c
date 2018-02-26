#include<stdio.h>
int main()
{
    int a,s[20],i=0,rem;
    printf("请输入整数:\n");
    scanf("%d",&a);
    while(a){
        rem=a%2;
        a=a/2;
        s[i++]=rem;
    }
    printf("输出的二进制：");
    while(i>0)
        printf("%d",s[--i]);
    printf("\n");
    return 0;
}
