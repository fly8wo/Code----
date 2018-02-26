   //最大子列和问题
//算法1
int MaxSubseqSum1( int A[],int N )
{
    int ThisSum,MaxSum = 0;
    int i,j,k;
    for( i=0; i<N; i++){
        for(j=0;j<N;j++){
            ThisSum = 0;
            for( k=i;k <=j;k++)
                ThisSum += A[k];
            if( ThisSum > MaxSum)
                MaxSum = ThisSum;

        }
    }
    return MaxSum;
}






/*算法2*/
int MaxSubseqSum2( int A[],int N )
{
    int ThisSum, MaxSum=0;
    int i,j;
    for( i=0;i<N; i++){/*i是子列左端位置*/
        ThisSum = 0; /*ThisSum是从A[i]到A[j]的子列和 */
            for( j=i;j<N;j++){/*j是子列右端的位置*/
               ThisSum += A[j];
            /*对于相同的i,不同的j,只要在j-1次循环的基础上累加1项即可*/
                if( ThisSum > MaxSum )
                    MaxSum = ThisSum;
            }/*j循环结束*/
    }/*i循环结束*/
    return MaxSum;
}
//算法3（分而治之）
