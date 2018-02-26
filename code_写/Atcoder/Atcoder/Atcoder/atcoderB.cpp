#include <iostream>
using namespace std;
int main()
{
	int n, a, b, i, p, h = 0;
	long long t = 0;
	cin >> n >> a >> b;
	for (i = 1; i <= n; i++)
	{
		p = i;
		do
		{
			h += p % 10;
			p /= 10;
		} while (p != 0);
		if (h >= a&&h <= b) t += i;
		h = 0;
	}
	cout << t << endl;
	return 0;
}