#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
using ll = long long;

const int N25 = 1e4 + 5;
int size25[N25];
vector<int>g25[N25];
int n25, m25, r25;
int fa25[N25];
int ans25[N25];

void dfs15(int x, int fa)
{
	size25[x] = 1;
	fa25[x] = fa;
	for (const auto& i : g25[x])
	{
		if (i == fa)continue;
		dfs15(i, x);
		size25[x] += size25[i];
	}
}

void lca2(int t)
{
	ll ans = size25[t] * 2 - 1;
	for (int i = 0; i < g25[t].size(); ++i)
	{
		if (g25[t][i] == fa25[t])continue;
		for (int j = 0; j < g25[t].size(); ++j)
		{
			if (i == j)continue;
			if (g25[t][j] == fa25[t])continue;
			ans += (size25[g25[t][i]] * size25[g25[t][j]]);
			
		}

	}
	ans25[t] = ans;
}


int main()
{
	queue<int>qst;
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	memset(g25, 0, sizeof g25);
	memset(ans25, 0, sizeof ans25);
	cin >> n25 >> r25 >> m25;
	int x, y;
	g25[r25].push_back(0);
	for (int i = 1; i < n25; ++i)
	{
		cin >> x >> y;
		g25[x].push_back(y);
		g25[y].push_back(x);
	}
	int t;
	for (int i = 1; i <= m25; ++i)
	{
		cin >> t;
		qst.push(t);
	}
	dfs15(r25, 0);
	while (qst.size())
	{
		auto q = qst.front();
		qst.pop();
		if(!ans25[q])
			lca2(q);
		cout << ans25[q] << endl;
	}


	return 0;
}