/*������һ���������Ŷ����Ķ��������ص��ǣ�
�������е�Ԫ�ؾ�����ͬ���������͡�
һ�����������ܸı��С��
ÿ����Ԫ����һ��int���͵ı���
���Գ����ڸ�ֵ����߻��ұߣ�
    ��a[2]= a[1]+6;
    ~�ڸ�ֵ��ߵĽ�����ֵ��
    ~�����ÿ����Ԫ�����������͵�һ������
    ~ʹ������ʱ����[]�е����ֽ����±��������С���0��ʼ������
    grades[0] grades[99] average[5]
��ΪC����Ӱ��������0��ʼ����  ��Ч���±귶Χ��segmentation fault������Խ�硢ָ�����



*/
#include <stdio.h>
#include <stdlib.h>


/*
void f();

int main()
{
    f();

    printf("Hello world!\n");
    return 0;
}
void f()
{

    int a[10];
    a[10] = 0;

}*/
int x;
double sum = 0;
int cnt = 0;
int number[100];
scanf("%d",&x);
while ( x!= -1){
    number [cnt] = x;
    sum += x;
    cnt ++;
    scanf("%d",&x);
}

if ( cnt > 0)
{
    int i;
    double avereage = sum;
    for( i=0; i< cnt ; i++){
        if( number[i] > average ){
            printf("%d ", number[i]);
           }
        }





}
