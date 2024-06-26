#include <iostream>
#include <cstring>
using namespace std;

const int N5 = 1e5 + 5;
int edge5[N5][1005];
int cnt5[N5];
int n5, m5;
bool vis5[N5];

int dfs3(int root)
{
	int res = 1;
	vis5[root] = 1;
	for (int i = 1; i<=cnt5[root]; ++i)
	{
		if (vis5[edge5[root][i]])continue;
		res += dfs3(edge5[root][i]);
	}
	return res;
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	memset(cnt5, 0, sizeof cnt5);
	memset(vis5, 0, sizeof vis5);
	cin >> n5 >> m5;
	int x, y;
	for (int i = 1; i <= m5; ++i)
	{
		cin >> x >> y;
		edge5[x][++cnt5[x]] = y;
		edge5[y][++cnt5[y]] = x;
	}
	if (m5 == n5 - 1)
	{
		cout << n5;
		return 0;
	}
	else if (m5 == 0)
	{
		cout << 1;
		return 0;
	}
	else if (m5 == 1)
	{
		cout << 2;
		return 0;
	}
	int ans = 0;
	for (int i = 1; i <= n5; ++i)
	{
		if (!vis5[i])
		{
			int k = dfs3(i);
			ans = ans > k ? ans : k;
		}
	}
	cout << ans;




	return 0;
}