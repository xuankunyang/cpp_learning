#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
int main()
{
	int n, m;
	ios::sync_with_stdio, cin.tie(0), cout.tie(0);
	cin >> n >> m;
	vector<ll>a(n + 1), b(m + 1);
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}
	for (int i = 1; i <= m; ++i)
	{
		cin >> b[i];
	}
	vector<vector<ll>>dp12(n + 1, vector<ll>(m + 1, 0));
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			if (a[i] == b[j]) dp12[i][j] = dp12[i - 1][j - 1] + 1;
			else dp12[i][j] = max(dp12[i - 1][j], dp12[i][j - 1]);
		}
	}
	cout << dp12[n][m];



	return 0;
}