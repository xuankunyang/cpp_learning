#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
	const int maxn = 1e8;
	int n, m;
	ios::sync_with_stdio, cin.tie(0), cout.tie(0);
	cin >> n >> m;
	vector<int>v(n + 1), w(n + 1), s(n + 1),q(maxn),dp25(m+1);
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i] >> w[i] >> s[i];
	}
	for (int i = 1; i <= n; ++i)
	{
		for (int r = 0; r < v[i]; ++r)
		{
			int head = 0, tail = -1;
			for (int j = r; j <= m; j += v[i])
			{
				while (head<=tail && j - q[head]>s[i] * v[i])head++;
				while (head <= tail && dp25[q[tail]] + (j - q[tail]) / v[i] * w[i] <= dp25[j])--tail;
				q[++tail] = j;
				dp25[j] = dp25[q[head]] + (j - q[head]) / v[i] * w[i];

			}
		}
	}
	cout << dp25[m];

	return 0;
}