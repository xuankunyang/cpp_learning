#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <utility>

using namespace std;
using ll = long long;
#define xx first
#define yy second

vector<pair<int, int>>v15;
bool vis15[1050][1050];


int main()
{
	ios::sync_with_stdio, cin.tie(0), cout.tie(0);
	int n,x,y;
	memset(vis15, false, sizeof vis15);
	ll ans = 0;
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> x >> y;
		x = (x + 51) << 1;
		y = (y + 51) << 1;
		v15.push_back({ x,y });
		vis15[x][y] = 1;
	}
	for (int i = 0; i < n-1; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			int midx = (v15[i].xx + v15[j].xx) / 2, midy = (v15[i].yy + v15[j].yy) / 2;
			int x1 = midx - (midy - v15[i].yy), y1 = midy + (midx - v15[i].xx);
			int x2 = midx + (midy - v15[i].yy), y2 = midy - (midx - v15[i].xx);
			if (x1 < 1 || x2 < 1 || y1 < 1 || y2 < 1)continue;
			if (vis15[x1][y1] && vis15[x2][y2])ans++;
		}
	}


	cout << ans/2;

	return 0;
}
