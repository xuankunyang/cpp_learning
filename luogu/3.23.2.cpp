#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
const int N29 = 1e5 + 5;
int n29, q29;
vector<int>edge29[N29];
int c29[N29], in29[N29], out29[N29], inpoint29[N29];
bool  cnt29[105][N29];
vector<int>ans29;
int aa29 = 0;
void dfs18(int x, int fa)
{
	static int cnt = 0;
	in29[x] = ++cnt;
	inpoint29[cnt] = x;
	for (const int& i : edge29[x])
	{
		if (i == fa)continue;
		dfs18(i, x);
	}
	out29[x] = cnt;
}

void solve29(int x)
{
	int ans = 0;
	for (int i = in29[x]; i <= out29[x]; ++i)
	{
		if (!cnt29[c29[inpoint29[i]]][aa29])
		{
			ans++;
			cnt29[c29[inpoint29[i]]][aa29] = 1;
		}
	}
	ans29.push_back(ans);
	aa29++;
}

int main()
{
	ios::sync_with_stdio, cin.tie(0), cout.tie(0);
	memset(cnt29, 0, sizeof cnt29);
	cin >> n29 >> q29;
	for (int i = 1; i <= n29; ++i)
	{
		cin >> c29[i];
	}
	int x, y;
	for (int i = 1; i < n29; ++i)
	{
		cin >> x >> y;
		edge29[x].push_back(y);
		edge29[y].push_back(x);
	}
	dfs18(1, 0);
	for (int i = 1; i <= q29; ++i)
	{
		cin >> x;
		solve29(x);
	}
	for (const int& i : ans29)
	{
		cout << i << endl;
	}

	return  0;
}