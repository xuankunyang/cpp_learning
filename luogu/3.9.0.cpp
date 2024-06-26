#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int n, m, x,a,b,c;
	ios::sync_with_stdio, cin.tie(0), cout.tie(0);
	cin >> n >> m >> x;
	vector<vector<int>>dp48(m + 1, vector<int>(x + 1, 0));
	for (int i = 1; i <= n; ++i)
	{
		cin >> a >> b >> c;
		for (int j = m; j >= b; --j)
		{
			for (int k = x; k >= c; --k)
			{
				dp48[j][k] = max(dp48[j - b][k - c] + a, dp48[j][k]);
			}
		}
	}
	cout << dp48[m][x];


	return 0;
}