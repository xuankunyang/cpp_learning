#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
int main()
{
	ll t, n,v,w;
	ios::sync_with_stdio, cin.tie(0), cout.tie(0);
	cin >> t >> n;
	vector<ll>dp44(t + 1);
	for (int i = 1; i <= n; ++i)
	{
		cin >> v >> w;
		for (int j = v; j <= t; ++j)
		{
			dp44[j] = max(dp44[j], dp44[j - v] + w);
		}
	}
	cout << dp44[t];

	return 0;
}