/*武汉科技大学ACM ：1003: 零起点学算法78——牛牛
Problem Description
牛牛是一种纸牌游戏，总共5张牌，规则如下： 
如果找不到3张牌的点数之和是10的倍数，则为没牛； 
如果其中3张牌的点数之和是10的倍数，则为有牛，剩下两张牌的点数和对10取余数，余数是几，就是牛几，特别的当余数是0的时候是牛牛； 
例如: 1 2 3 4 5, 1 + 4 + 5 = 0 (mod 10)，2 + 3 = 5(mod 10), 为牛5。 



Input
第一行输入一个整数T(T <= 100)，表示有几组数据。每组数据占一行，5 个数， 每个数的范围都是1到10。 

Output
见样例。 

Sample Input
3
1 1 1 1 1
1 2 3 4 5
1 9 10 10 10
Sample Output
Case #1: Mei Niu
Case #2: Niu 5
Case #3: Niu Niu */ 

#include <iostream>
#include <cmath> 
using namespace std;
int main()
{
		int a[5];
		int n,o;
		int sum1;
		while(scanf("%d",&n)!=EOF)
			{
				if(n<=100)
					{
						for(o=0;o<n;o++){
							int l,b;
							for(l=0;l<5;l++){
								scanf("%d",&b);
								a[l]=b;
							}
							int b1=0,b2=0;
							int i,j,k,i1;
							//start for
							for(i=0;i<=2;i++){
								for(j=i+1;j<=3;j++){
									for(k=j+1;k<=4;k++){
									if((a[i]+a[j]+a[k])%10==0){
										b1=1;
										sum1=0;
										for(i1=0;i1<=4;i1++){
											if(i1!=i && i1!=j && i1!=k){
												sum1+=a[i1];
											}
										}
										if(sum1%10==0){
											b2=1;
										}
									}	
									}
								}
							}//End for
							if(b1)//有牛
							{
								if(b2)//牛牛{
								{
								printf("Case #%d: Niu Niu\n",o+1);
							 	} 
							 else
							{
							 	printf("Case #%d: Niu %d\n",o+1,(sum1%10));
							} 
						}
						
						else//没牛
						{
							printf("Case #%d:Mei Niu\n",o+1);
						 } 
						}//End for o
					}//end for if
			}//END for while
	
	return 0;
 } 
