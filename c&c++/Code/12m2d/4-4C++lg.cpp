/*
ʹ�ú�����������ɷ������ֵ�ķ�����

������һ�����飬����һ������getMax()�����ú��������أ��ֱ�ʵ�֣�

1������ȡ�������е�����Ԫ�أ���������getMax()�У����Է��ؽϴ��һ��Ԫ�ء�

2�����������鴫������getMax()�У����Է�������������һ��Ԫ�ء�

*/
#include <iostream>
using namespace std;
/**
  *�������ܣ�����a��b�����ֵ
  *a��b����������
  */
int getMax(int a, int b)
{
    return a > b ? a : b;
}

/**
  * �������ܣ����������е����ֵ
  * arr����������
  * count�����鳤��
  * �ú����Ƕ����溯��������
  */
int getMax(int *arr,int count)
{
    //����һ����������ȡ����ĵ�һ��Ԫ��
    int maxNum = arr[0];
	for(int i = 1; i < count; i++)
	{
        //�Ƚϱ�������һ��Ԫ�صĴ�С
		if(maxNum < arr[i])
		{
            //��������е�Ԫ�ر�maxNum�����ȡ�����е�ֵ
			maxNum = arr[i];
		}	
	}
	return maxNum;
}

int main(void)
{
    //����int���鲢��ʼ��
	int numArr[3] = {3, 8, 6};
    
    //�Զ�����int getMax(int a, int b)
	cout << getMax(numArr, 3) << endl;
    
    //�Զ����÷������������ֵ�ĺ������������е����ֵ
	cout << getMax(numArr[0],numArr[2]) << endl;
	return 0;
}
