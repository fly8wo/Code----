/*�人�Ƽ���ѧACM ��1003: �����ѧ�㷨78����ţţ
Problem Description
ţţ��һ��ֽ����Ϸ���ܹ�5���ƣ��������£� 
����Ҳ���3���Ƶĵ���֮����10�ı�������Ϊûţ�� 
�������3���Ƶĵ���֮����10�ı�������Ϊ��ţ��ʣ�������Ƶĵ����Ͷ�10ȡ�����������Ǽ�������ţ�����ر�ĵ�������0��ʱ����ţţ�� 
����: 1 2 3 4 5, 1 + 4 + 5 = 0 (mod 10)��2 + 3 = 5(mod 10), Ϊţ5�� 



Input
��һ������һ������T(T <= 100)����ʾ�м������ݡ�ÿ������ռһ�У�5 ������ ÿ�����ķ�Χ����1��10�� 

Output
�������� 

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
							if(b1)//��ţ
							{
								if(b2)//ţţ{
								{
								printf("Case #%d: Niu Niu\n",o+1);
							 	} 
							 else
							{
							 	printf("Case #%d: Niu %d\n",o+1,(sum1%10));
							} 
						}
						
						else//ûţ
						{
							printf("Case #%d:Mei Niu\n",o+1);
						 } 
						}//End for o
					}//end for if
			}//END for while
	
	return 0;
 } 
