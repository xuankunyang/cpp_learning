#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int total = 0;

int main()
{
	int n;
	ios::sync_with_stdio, cin.tie(0), cout.tie(0);
	cin >> n;
	vector<int>a(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		total += a[i];
	}
	if (total & 1)
	{
		cout << "no" << endl;
		return 0;
	}
	int m = total / 2;
	vector<int>dp15(m + 1);
	for (int i = 1; i <= n; ++i)
	{
		for (int j = m; j >= a[i]; --j)
		{
			dp15[j] = max(dp15[j], dp15[j - a[i]] + a[i]);
		}
	}
	if (dp15[m] == m)cout << "yes" << endl;
	else cout << "no" << endl;


	return 0;
}