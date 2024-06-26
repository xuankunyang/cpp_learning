#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
using ll = long long;
const int N32 = 1e7 + 5;
int n32;
int size32[N32],head32[N32];
ll ans32 = 0;
struct edge
{
	int to, last;
	ll w;
}e32[N32*2];

void push32(int x, int y,ll z)
{
	static int cnt = 0;
	e32[++cnt].to = y;
	e32[cnt].last = head32[x];
	e32[cnt].w = z;
	head32[x] = cnt;
}

void dfs34(int x,int fa)
{
	size32[x] = 1;
	for (int i = head32[x]; i; i = e32[i].last)
	{
		if (e32[i].to == fa)continue;
		dfs34(e32[i].to, x);
		size32[x] += size32[e32[i].to];
		ans32 += e32[i].w * abs(n32 - 2 * size32[e32[i].to]);
	}
}


int main()
{
	ios::sync_with_stdio, cin.tie(0), cout.tie(0);
	cin >> n32;
	int x, y;
	ll z;
	for (int i = 1; i < n32; ++i)
	{
		cin >> x >> y >> z;
		push32(x, y, z);
		push32(y, x, z);
	}
	dfs34(1, 0);
	cout << ans32;




	return 0;
}