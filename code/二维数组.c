#include <stdio.h>

int main()
{
 int i,j;
 double scores[4][3] = {
    {89,90,22},
    {23,42,54},
    {99,77,55},
    {78,44,65}
 };
 printf("语文\t英语\t数学\n");
 for(i = 0;i < 4; i++)
 {
    for(j = 0;j < 3;j++)
    {
        printf("%-8.2lf",scores[i][j]);
    }

printf("\n");




 }






    return 0;
}