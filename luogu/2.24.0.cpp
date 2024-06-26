#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int n, v, m,vv,mm,ww;
	ios::sync_with_stdio, cin.tie(0), cout.tie(0);
	cin >> n >> v >> m;
	vector<vector<int>>dp26(v + 1, vector<int>(m + 1));
	for (int i = 1; i <= n; ++i)
	{
		cin >> vv >> mm >> ww;
		for (int j = v; j >= vv; --j)
		{
			for (int k = m; k >= mm; --k)
			{
				dp26[j][k] = max(dp26[j][k], dp26[j - vv][k - mm] + ww);
			}
		}
	}
	cout << dp26[v][m];
	return 0;
}