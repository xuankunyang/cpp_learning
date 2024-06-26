#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int n, m, t, x, y;
	ios::sync_with_stdio, cin.tie(0), cout.tie(0);
	cin >> n >> m >> t;
	vector<vector<int>>dp49(m + 1, vector<int>(t + 1,0));
	for (int i = 1; i <= n; ++i)
	{
		cin >> x >> y;
		for (int j = m; j >= x; --j)
		{
			for (int k = t; k >= y; --k)
			{
				dp49[j][k] = max(dp49[j][k], dp49[j - x][k - y]+1);
			}
		}
	}
	cout << dp49[m][t];

	return 0;
}