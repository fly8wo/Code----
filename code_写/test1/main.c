/*数组是一种容器（放东西的东西），特点是：
其中所有的元素具有相同的数据类型。
一旦创建，不能改变大小。
每个单元就是一个int类型的变量
可以出现在赋值的左边或右边：
    ·a[2]= a[1]+6;
    ~在赋值左边的叫做左值。
    ~数组的每个单元就是数组类型的一个变量
    ~使用数组时放在[]中的数字叫做下标或索引，小标从0开始计数：
    grades[0] grades[99] average[5]
因为C语言影响大，数组从0开始数数  有效的下标范围（segmentation fault）数组越界、指针出错、



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
