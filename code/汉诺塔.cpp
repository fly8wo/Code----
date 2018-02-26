#include <iostream>
using namespace std;

void Move( char A, char C )
{
cout << A << ' --> ' << C << endl;
}

void Hanoi( int n, char A, char B, char C )
{
if( n == 1 )
{
Move( A, C );
}
else
{
Hanoi( n-1, A, C, B );
Move( A, C );
Hanoi( n-1, B, A, C );
}
}

int _tmain()
{
int disks;

cout << '请输入汉诺塔盘子的个数：' << endl;
cin >> disks;
Hanoi( disks, '1', '2', '3' );

return 0;
}

