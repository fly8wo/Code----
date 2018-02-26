#include<iostream>  
#include<cstring>  
#include<cctype>  
using namespace std;  
  
int main()  
{  
    string str("some string");  
    // range for 语句  
    for(auto &c : str)  
    {  
        c = toupper(c);  
    }  
    cout << str << endl;  
    return 0;  
}  