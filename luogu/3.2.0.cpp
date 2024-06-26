#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <utility>
#include <cmath>

using namespace std;
#define x first
#define y second

int n10, m10;
char p10[183][183];
int dist10[183][183];
int dx10[] = { 1,-1,0,0 };
int dy10[] = { 0,0,1,-1 };
queue<pair<int, int>>q10;

void bfs5()
{
	while (!q10.empty())
	{
		auto t = q10.front();
		q10.pop();
		for (int i = 0; i < 4; ++i)
		{
			int nx = t.x + dx10[i], ny = t.y + dy10[i];
			if (nx<1 || ny<1 || nx>n10 || ny>m10||dist10[nx][ny]!=-1)continue;
			dist10[nx][ny] = dist10[t.x][t.y] + 1;
			q10.push({ nx,ny });
		}
	}
}



int main()
{
	ios::sync_with_stdio, cin.tie(0), cout.tie(0);
	cin >> n10 >> m10;
	memset(dist10, -1, sizeof dist10);
	for (int i = 1; i <= n10; ++i)
	{
		for (int j = 1; j <= m10; ++j)
		{
			cin >> p10[i][j];
			if (p10[i][j] == '1')
			{
				q10.push({ i,j });
				dist10[i][j] = 0;
			}
		}
	}
	
	bfs5();

	for (int i = 1; i <= n10; ++i)
	{
		for (int j = 1; j <= m10; ++j)
		{
			cout << dist10[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}