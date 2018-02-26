#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
int mian ()
{
	srand(time(NULL));
	printf("随机数字：%d\n",rand());
	int hp1=100,hp2=100;
	int att1,att2;
	int i=0;
	while(hp1>=0&&hp2>=0);
	{
		att1=rand()%11+5;
		att2=rand()%11+5;
		hp2-=att1;
		hp1-=att2;
		printf("************************************************\n");
		printf("第%d轮: \n",i+1);
		printf("玩家1的攻击力： %d,玩家2的剩余血量： %d\n",att1,hp2);
		printf("玩家2的攻击力： %d,玩家1的剩余血量： %d\n",att2,hp1);
		printf("************************************************\n");
		i++;
		Sleep(500);
	}
	printf("KO! Game Over~玩家1的血量： %d/t玩家2的血量：%d ",hp1,hp2);
return 0;
}
