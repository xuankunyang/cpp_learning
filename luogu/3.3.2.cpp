#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;
#define x first
#define y second

int n13, m13;
char map13[2001][2001];
int dx13[] = { 1,-1,0,0 };
int dy13[] = { 0,0,1,-1 };
int dist13[2001][2001];
queue<pair<int, int>>q13;

int bfs8()
{
	while (!q13.empty())
	{
		auto t = q13.front();
		q13.pop();
		for (int i = 0; i < 4; ++i)
		{
			int nx = t.x + dx13[i], ny = t.y + dy13[i];
			if (nx<1 || ny<1 || nx>n13 || ny>m13 || map13[nx][ny] == '#')continue;
			dist13[nx][ny] = dist13[t.x][t.y] + 1;
			if (map13[nx][ny] == 'd')return dist13[nx][ny];
			q13.push({ nx,ny });
		}
	}
	return -1;
}



int main()
{
	ios::sync_with_stdio, cin.tie(0), cout.tie(0);
	cin >> n13 >> m13;
	for (int i = 1; i <= n13; ++i)
	{
		for (int j = 1; j <= m13; ++j)
		{
			cin >> map13[i][j];
			if (map13[i][j] == 'm')
			{
				q13.push({ i,j });
				dist13[i][j] = 0;
			}
		}
	}

	int k = bfs8();
	if (k != -1)cout << k;
	else cout << "No Way!";



	return 0;
}