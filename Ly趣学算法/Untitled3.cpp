#include<iostream>
#include<string>
using namespace std;
/*
�������ƣ���ö�Ӧ���ֳ��ֵĴ���
���룺
    in_number:  ���������е�����
    number:     ��Ҫ���ҵ�����0-9
�����
    number��in_number�г��ֵĴ���
*/
int get_number_times(string& in_number, int number)
{
    int count = 0;
    for (int i = 0; i < in_number.length(); i++)
    {
        if (in_number[i] == (char)(number + 48))
        {
            count++;
        }
    }
    return count;
}

int main()
{
    string input_number;
    cin >> input_number;
    int number_times[10];//0-9ʮ����ÿ�����ļ�������
    //���0-9��input_number�г��ֵĴ���
    for (int i = 0; i < 10; i++)
    {
        number_times[i] = get_number_times(input_number, i);
    }
    //��ӡ
    for (int i = 0; i < 10; i++)
    {
        if (number_times[i]!=0)
        {
            cout << i << ":" << number_times[i] << endl;
        }
    }
    //system("pause");
    return 0;
}
