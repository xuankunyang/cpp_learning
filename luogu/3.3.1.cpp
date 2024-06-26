#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
#include <cstring>

using namespace std;
using ll = long long;
#define x first
#define y second

int n12, m12;
char map12[15][15];
int cnt12[18];
queue<pair<int, int>>q12;
int dx12[] = { 1,-1,0,0,-1,1,-1,1 };
int dy12[] = { 0,0,1,-1,-1,-1,1,1 };

int bfs7(int x0, int y0)
{
	ll res = 1;
	q12.push({ x0,y0 });
	map12[x0][y0 - 1] = '.';
	while (q12.size())
	{
		auto t = q12.front();
		q12.pop();
		for (int i = 0; i < 8; ++i)
		{
			int nx = t.x + dx12[i], ny = t.y + dy12[i];
			if (nx<1 || ny<1 || nx>n12 || ny>m12 || map12[nx][ny - 1] == '.')continue;
			map12[nx][ny - 1] = '.';
			res++;
			q12.push({ nx,ny });
		}
	}
	return res;
}


int main()
{
	ll ans1 = 0, ans2 = 0;
	memset(cnt12, 0, sizeof cnt12);
	ios::sync_with_stdio, cin.tie(0), cout.tie(0);
	cin >> n12 >> m12;
	for (int i = 1; i <= n12; ++i)
	{
		cin >> map12[i];
	}
	for (int i = 1; i <= n12; ++i)
	{
		for (int j = 1; j <= m12; ++j)
		{
			if (map12[i][j - 1] == '*')
			{
				int k = bfs7(i, j);
				cnt12[k]++;
			}
		}
	}
	for (int i = 1; i <= n12 * m12 ; ++i)
	{
		if (cnt12[i])ans1++;
		else continue;
		ans2 = max(ans2, (ll)cnt12[i] * i);
	}
	cout << ans1 << " " << ans2;

	return 0;
}