   //������к�����
//�㷨1
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






/*�㷨2*/
int MaxSubseqSum2( int A[],int N )
{
    int ThisSum, MaxSum=0;
    int i,j;
    for( i=0;i<N; i++){/*i���������λ��*/
        ThisSum = 0; /*ThisSum�Ǵ�A[i]��A[j]�����к� */
            for( j=i;j<N;j++){/*j�������Ҷ˵�λ��*/
               ThisSum += A[j];
            /*������ͬ��i,��ͬ��j,ֻҪ��j-1��ѭ���Ļ������ۼ�1���*/
                if( ThisSum > MaxSum )
                    MaxSum = ThisSum;
            }/*jѭ������*/
    }/*iѭ������*/
    return MaxSum;
}
//�㷨3���ֶ���֮��
