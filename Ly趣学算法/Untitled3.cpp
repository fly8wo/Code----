#include<iostream>
#include<string>
using namespace std;
/*
函数名称：获得对应数字出现的次数
输入：
    in_number:  输入样例中的数字
    number:     需要查找的数字0-9
输出：
    number在in_number中出现的次数
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
    int number_times[10];//0-9十个数每个数的计数次数
    //获得0-9在input_number中出现的次数
    for (int i = 0; i < 10; i++)
    {
        number_times[i] = get_number_times(input_number, i);
    }
    //打印
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
