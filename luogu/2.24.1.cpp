#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int m, n,t,v;
	ios::sync_with_stdio, cin.tie(0), cout.tie(0);
	cin >> m >> n;
	vector<int>dp27(m + 1);
	for (int i = 1; i <= n; ++i)
	{
		cin >> t >> v;
		for (int j = m; j >= t; --j)
		{
			dp27[j] = max(dp27[j],dp27[j - t] + v);
		}
	}
	cout << dp27[m];


	return 0;
}