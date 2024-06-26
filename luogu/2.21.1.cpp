#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int n, vv;
	ios::sync_with_stdio, cin.tie(0), cout.tie(0);
	cin >> n >> vv;
	vector<int>w(n + 1), v(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		cin >> w[i] >> v[i];
	}
	vector<int>dp19(vv + 1);
	for (int i = 1; i <= n; ++i)
	{
		for (int j = w[i]; j <= vv; ++j)
		{
			dp19[j] = max(dp19[j], dp19[j - w[i]] + v[i]);
		}
	}
	cout << dp19[vv];





	return 0;
}