#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	double h, s, v, l, k;
	long  n,num=0;
	cin >> h >> s >> v >> l >> k >> n;
	double t = sqrt((h - k) / 5);
	double head = s - v * t;
	for (int i = 0; i < n; ++i)
	{
		if (i >= head - 0.0001 && i <= head + l + 0.0001)
			num++;
	}
	cout << num;

	return 0;
}
