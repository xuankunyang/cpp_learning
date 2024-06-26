#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
	int n, m, v, w, s;
	ios::sync_with_stdio, cin.tie(0), cout.tie(0);
	cin >> n >> m;
	vector<int>dp24(m + 1);
	for (int i = 1; i <= n; ++i)
	{
		cin >> v >> w >> s;
		for (int k = 1; s > k; s -= k, k += k)
		{
			for (int j = m; j >= k*v; --j)
			{
				dp24[j] = max(dp24[j], dp24[j - k * v] + k * w);
			}
		}
		for (int j = m; j >= s * v; --j)
		{
			dp24[j] = max(dp24[j], dp24[j - s * v] + s * w);
		}
	}
	cout << dp24[m];

	return 0;
}