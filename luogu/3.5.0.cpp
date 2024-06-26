#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;
#define x first 
#define y second 

int n16, m16;
char map16[105][105];
int dx16[] = {1,-1,0,0,1,-1,1,-1 };
int dy16[] = {0,0,1,-1,1,1,-1,-1 };
queue<pair<int, int>>q16;
queue<int>ans16;

void bfs9(int x0, int y0)
{
	q16.push({ x0,y0 });
	map16[x0][y0] = '*';
	while (q16.size())
	{
		auto t = q16.front();
		q16.pop();
		for (int i = 0; i < 8; ++i)
		{
			int nx = t.x + dx16[i], ny = t.y + dy16[i];
			if (nx<1 || ny<1 || nx>m16 || ny>n16 || map16[nx][ny] == '*')continue;
			map16[nx][ny] = '*';
			q16.push({ nx,ny });
		}
	}
}

int main()
{
	ios::sync_with_stdio, cin.tie(0), cout.tie(0);
	cin >> m16 >> n16;
	while (m16)
	{
		int ans = 0;
		for (int i = 1; i <= m16; ++i)
		{
			for (int j = 1; j <= n16; ++j)
			{
				cin >> map16[i][j];
			}
		}
		for (int i = 1; i <= m16; ++i)
		{
			for (int j = 1; j <= n16; ++j)
			{
				if (map16[i][j] == '@')
				{
					bfs9(i, j);
					ans++;
				}
			}
		}
		ans16.push(ans);
		cin >> m16 >> n16;
	}
	while (ans16.size())
	{
		auto t = ans16.front();
		cout << t << endl;
		ans16.pop();
	}
	return 0;
}