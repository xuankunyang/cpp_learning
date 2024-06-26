#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int m, n,s,t;
	ios::sync_with_stdio, cin.tie(0), cout.tie(0);
	cin >> m >> n;
	vector<int>dp52(m + 1,0);
	for (int i = 1; i <= n; ++i)
	{
		cin >> s >> t;
		for (int j = t; j <= m; ++j)
		{
			dp52[j] = max(dp52[j], dp52[j - t] + s);
		}
	}
	cout << dp52[m];

	return 0;
}