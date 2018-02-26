#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void GetNext(char *t,int next[])
{
   int i,j;
   j=0;
   i=-1;
   next[0]=-1;
   int n=strlen(t)-1;
   while(j<n)
   {
      if(i==-1||t[j]==t[i])
   {
         j++;
   i++;
   next[j]=i;
   }
   else
   {
         i=next[i];
   }
   }
}

void KMP(char *s, char *t)//s为目标串 t为模式串
{
   int next[30];
   int i=0, j=0;
   GetNext(t,next);
   int m=strlen(s);
   int n=strlen(t);
   while(i<m&&j<n)
   {
       if(j==-1||s[i]==t[j])
    {
          i++;
    j++;
    }
    else
    {
          j=next[j]; //i不变 j后退
    }
   }
   
   if(j>=n)
   {
       printf("在目标串第%d个起始位置成功匹配模式串:\n%s\n", i-j, t);
   }
   else
   {
      printf("目标串与模式串匹配失败\n");
   }
}

int main()
{
    char  String1[]="1234567df1liuyang";
 char  String2[]="liuyang";
 KMP(String1, String2);
 return 0;
}

