#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;
const int N24 = 5e5 + 5;
vector<int>g24[N24];
vector<int>ans24;
int fa24[N24][21];
int dep24[N24];
int n24, m24, s24;

void dfs14(int x, int fa)
{
	dep24[x] = dep24[fa] + 1;
	fa24[x][0] = fa;
	for (int i = 1; i <= 20; ++i)
	{
		if (dep24[x] - pow(2, i) < 1)break;
		fa24[x][i] = fa24[fa24[x][i - 1]][i - 1];
	}
	for(const auto& y:g24[x])
	{
		if (y == fa)continue;
		dfs14(y, x);
	}
}

void lca1(int x, int y)
{
	if (dep24[x] < dep24[y])swap(x, y);
	for (int i = 20; i >= 0; --i)
	{
		if (!fa24[x][i])continue;
		if (dep24[fa24[x][i]] < dep24[y])continue;
		x = fa24[x][i];
	}
	if (x == y)
	{
		ans24.push_back(y);
		return;
	}
	for (int i = 20; i >= 0; --i)
	{
		if (!fa24[x][i])continue;
		if (fa24[x][i]==fa24[y][i])continue;
		x = fa24[x][i];
		y = fa24[y][i];
	}
	ans24.push_back(fa24[x][0]);
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	memset(fa24, 0, sizeof fa24);
	cin >> n24 >> m24 >> s24;
	int a, b;
	for (int i = 1; i <= n24 - 1; ++i)
	{
		cin >> a >> b;
		g24[a].push_back(b);
		g24[b].push_back(a);
	}
	dep24[0] = 0;
	dfs14(s24, 0);
	for (int i = 1; i <= m24; ++i)
	{
		cin >> a >> b;
		lca1(a, b);
	}

	for (const auto& i : ans24)
		cout << i << endl;


	return 0;
}



