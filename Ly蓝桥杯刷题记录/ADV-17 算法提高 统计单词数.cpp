�㷨��� ͳ�Ƶ�����
��������
����ͳ������Ӣ�����¶����в�ͬ���ʣ������д�Сд֮��,������ͳ��ʱ���Դ�Сд��
���Գ��ֵĴ����� ����������������ʵ�����������100������ʵĳ��Ȳ�����20����ĸ.
�����ʽ
����һ���������ɾ��ӵĶ���, ÿ������������Ӣ�ĵ������. ���ո�,�������ź;����, ��Щ����ľ����в�����������ĸ�ַ�,
����, ���ź;�Ž�������ǰ���Ӣ�ĵ��ʺ���, �м�û�пո�. �������һ���ַ��ǻس���,������ʾ�������.
�����ʽ
�����������й���M����ͬ��Ӣ�ĵ��ʣ��������ڶ����г��ֵ��Ⱥ�˳�����M�У����еĸ�ʽΪ:��
��������������ĸ���ô�д��ʽ�������ĵ��ʶ����������ǰ��û�ж���Ŀո�;�������൥�������Ҷ��룩+ð��+N��*��+�õ����ڶ����еĳ��ִ���N
��������
This is a test. This test is easy. This is a test. This test is easy.

�������
THIS:****4
IS:****4
A:**2
TEST:****4
EASY:**2
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
typedef pair<string, int> p;
int main(){
	string str;
	vector<p> v;
	getline(cin, str);
	string s;
	int flag2 = 0;
	int maxlen = 0;
	for(int i =0;i<str.length();i++){
		if(flag2 == 1 && str[i] == ' ')
			continue;
		if(str[i]=='.'||str[i]==' '||str[i]==','){
			flag2=1;
			int len = s.length();
			maxlen = maxlen > len ? maxlen : len;
			for(int j =0;j<len;j++){
				if(s[j]>='a'&&s[j]<='z'){
					s[j]=s[j]-32;
				}
			}
			int flag = 0;
			for(int i = 0;i < v.size();i++){
				if(v[i].first == s){
					v[i].second++;
					flag=1;
				}
			}
			if(flag==0){
				p temp = make_pair(s,1);
				v.push_back(temp);
			}
			s= "";
		}else {
			flag2=0;
			s += str[i];
		}

	}
	for(int i = 0;i<v.size();i++){
		string temp = v[i].first;
		int len = maxlen-temp.length();
		for(int k =0;k < len;k++){
			cout<<" ";
		}
		cout << v[i].first <<":";
		for(int j = 0; j < v[i].second;j++){
			cout<<"*";
		}
		cout<<v[i].second<<endl;
	}
return 0;
}
