#include <Windows.h>  
#include <stdio.h>  
#include <iostream>  
using namespace std;  
int main()  
{  
  printf("    ��MoreWindows�����ʼ�1�� C/C++ ������ַ� printf + %ls or wcout\n");      
  printf(" - http://blog.csdn.net/morewindows/article/details/16358175 -\n");      
  printf(" -- By MoreWindows( http://blog.csdn.net/MoreWindows ) --\n\n");    
  
  char text[] = "MoreWindows";  
  WCHAR w_text[] = L"http://blog.csdn.net/MoreWindows";  
  
  printf("%s %ls\n", text, w_text);  
  
  cout<<text<<" ";  
  wcout<<w_text<<endl;  
  return 0;  
}  
