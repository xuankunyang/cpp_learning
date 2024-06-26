#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int n3, m3;
const int N3 = 1e4 + 5;
bool vis3[N3][N3];
char p3[N3][N3];
int dp46[N3][N3];
int dy3[] = { 0,0,1,-1 }, dx3[] = { 1,-1,0,0 };
int x3, y3;
void dfs3(int x, int y)
{
	if (x <= 0 || x > n3 || y <= 0 || y > m3)return;
	if (vis3[x][y])return;
	vis3[x][y] = 1;
	for (int i = 0; i < 4; ++i)
	{
		int nx = x + dx3[i], ny = y + dy3[i];
		if(p3[x][y-1]=='1')
		{
			dp46[x3][y3] = min(dp46[x3][y3], abs(x - x3) + abs(y - y3));
		}
		dfs3(nx, ny);
	}
	vis3[x][y] = 0;
}
int main()
{
	ios::sync_with_stdio, cin.tie(0), cout.tie(0);
	cin >> n3 >> m3;
	for (int i = 1; i <= n3; ++i)
	{
		cin >> p3[i];
	}
	for (int i = 1; i <= n3; ++i)
	{
		for (int j = 1; j <= m3; ++j)
		{
			dp46[i][j] = 1e8;
		}
	}
	for (int i = 1; i <= n3; ++i)
	{
		for (int j = 1; j <= m3; ++j)
		{
			if (p3[i][j - 1]=='0')
			{
				x3 = i;
				y3 = j;
				dfs3(i, j);
			}
		}
	}
	for (int i = 1; i <= n3; ++i)
	{
		for (int j = 1; j <= m3; ++j)
		{
			if (p3[i][j - 1] == '1')
				dp46[i][j] = 0;
			cout << dp46[i][j]<<" ";
		}
		cout << endl;
	}


	return 0;
}