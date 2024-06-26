#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int h, t, n, hh, tt, kk;
	ios::sync_with_stdio, cin.tie(0), cout.tie(0);
	cin >> h >> t>>n;
	vector<vector<int>>dp43(h + 1, vector<int>(t + 1));
	for (int i = 1; i <= n; ++i)
	{
		cin >> hh >> tt >> kk;
		for (int j = h; j >= hh; --j)
		{
			for (int k = t; k >= tt; --k)
			{
				dp43[j][k] = max(dp43[j - hh][k - tt] + kk, dp43[j][k]);
			}
		}
	}
	cout << dp43[h][t];
	return 0;
}