#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
int mian ()
{
	srand(time(NULL));
	printf("������֣�%d\n",rand());
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
		printf("��%d��: \n",i+1);
		printf("���1�Ĺ������� %d,���2��ʣ��Ѫ���� %d\n",att1,hp2);
		printf("���2�Ĺ������� %d,���1��ʣ��Ѫ���� %d\n",att2,hp1);
		printf("************************************************\n");
		i++;
		Sleep(500);
	}
	printf("KO! Game Over~���1��Ѫ���� %d/t���2��Ѫ����%d ",hp1,hp2);
return 0;
}
