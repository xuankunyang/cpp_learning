#include <iostream>
#include <cstring>
using namespace std;

int n3, m3,a3;
const int N3 = 1e5 + 5;

struct edge
{
	int to, last;
}e[N3];
int head1[N3];
bool vis3[N3];

void push(int x, int y)
{
	static int cnt = 0;
	e[++cnt].to = y;
	e[cnt].last = head1[x];
	head1[x] = cnt;
}

void dfs1(int x)
{
	vis3[x] = 1;
	a3++;
	for (int i = head1[x]; i; i = e[i].last)
	{
		if(!vis3[e[i].to])
			dfs1(e[i].to);
	}
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	memset(head1, 0, sizeof head1);
	memset(vis3, 0, sizeof vis3);
	cin >> n3 >> m3;
	int x, y;
	for (int i = 1; i <= m3; ++i)
	{
		cin >> x >> y;
		push(x, y);
		push(y, x);
	}
	if (m3 == n3 - 1)
	{
		cout << n3;
		return 0;
	}
	else if (m3 == 0)
	{
		cout << 1;
		return 0;
	}
	else if (m3 == 1)
	{
		cout << 2;
		return 0;
	}
	int ans = 0;
	for (int i = 1; i <= n3; ++i)
	{
		if (!vis3[i])
		{
			a3 = 0;
			dfs1(i);
			ans = a3 > ans ? a3 : ans;
		}
	}
	cout << ans;


	return 0;
}