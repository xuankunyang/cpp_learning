#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
const int N27 = 1e5 + 5;
int in27[N27], out27[N27],inpoint27[N27];
vector<int>edge27[N27];
int n27, m27;
int a27[N27];

void dfs16(int x,int fa)
{
	static int cnt = 0;
	in27[x] = ++cnt;
	inpoint27[cnt] = x;
	for (const int& t : edge27[x])
	{
		if (t == fa)continue;
		dfs16(t, x);
	}
	out27[x] = cnt;
}

void solve27(int x)
{
	int ans = a27[x];
	for (int i = in27[x]+1; i <= out27[x]; ++i)
	{
		ans ^= a27[inpoint27[i]];
	}
	cout << ans << endl;
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n27 >> m27;
	for (int i = 1; i <= n27; ++i)
	{
		cin >> a27[i];
	}
	int x, y;
	for (int i = 1; i < n27; ++i)
	{
		cin >> x >> y;
		edge27[x].push_back(y);
		edge27[y].push_back(x);
	}
	dfs16(1, 0);
	int z;
	for (int i = 1; i <= m27; ++i)
	{
		cin >> z;
		if (z == 1)
		{
			cin >> x >> y;
			a27[x] = y;
		}
		else
		{
			cin >> x;
			solve27(x);
		}
	}
	
	

	return 0;
}
