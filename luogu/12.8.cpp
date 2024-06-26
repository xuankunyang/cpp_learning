#include <iostream>
using namespace std;
long long int f(int* a, long long int x)
{
	if (x < 10)return x;
	return a[0] * f(a, x - 1) + a[1] * f(a, x - 2) + a[2] * f(a, x - 3) + a[3] * f(a, x - 4) + a[4] * f(a, x - 5) + a[5] * f(a, x - 6) + a[6] * f(a, x - 7) + a[7] * f(a, x - 8) + a[8] * f(a, x - 9) + a[9] * f(a, x - 10);
}
int main()
{
	long long int k, m;
	int a[10];
	cin >> k >> m;
	for (int  i = 0; i < 10; ++i)
		cin >> a[i];
	cout << f(a, k) % m;
	return 0;
}