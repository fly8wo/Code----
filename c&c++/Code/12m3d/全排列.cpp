#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
using namespace std;

char str[10];
int len;
bool mark[10];
char prt[10];


void print()
{
    for(int i=0;i<len;i++)
    printf("%c",prt[i]);
     printf("\n");
}

void dfs(int s)
{
   if(s==len) 
     {
                print();
 }
        for(int i=0;i<len;i++)
    {
                if(mark[i]==0)
           {
                        mark[i]=1;
                       prt[s]=str[i];
                   dfs(s+1);
                        mark[i]=0;
               }
        }
}

int main()
{
    scanf("%s",str);
 len=strlen(str);
 dfs(0);
  return 0;
}
