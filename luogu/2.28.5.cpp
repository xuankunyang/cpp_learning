#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int n, m, v, w, s;
	ios::sync_with_stdio, cin.tie(0), cout.tie(0);
	cin >> n >> m;
	vector<int>dp45(m + 1);
	for(int i=1;i<=n;++i)
	{ 
		cin >> v >> w >> s;
		for (int k = 1; k <= s; s -= k, k += k)
		{
			for (int j = m; j >= k * w; --j)
			{
				dp45[j] = max(dp45[j], dp45[j - k * w] + k * v);
			}
		}
		for (int j = m; j >= s * w; --j)
		{
			dp45[j] = max(dp45[j], dp45[j - s * w] + s * v);
		}
	}
	cout << dp45[m];

	return 0;
}