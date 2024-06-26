#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
#include <vector>
#include <cstring>

using namespace std;
#define x first
#define y second

int m20, n20, xx, yy;
vector<pair<int,int>>move20;
int a20[] = { 1,-1,1,-1 };
int b20[] = { 1,1,-1,-1 };
int dist20[35][35];
char map20[35][35];
queue<pair<int, int>>q20;

int bfs12()
{
	while (!q20.empty())
	{
		auto t = q20.front();
		q20.pop();
		for (int i = 0; i < 8; ++i)
		{
			int nx = t.x + move20[i].x, ny = t.y + move20[i].y;
			if (nx < 1 || ny < 1 || nx > m20 || ny > n20 || dist20[nx][ny] != -1||map20[nx][ny]=='0'||map20[nx][ny]=='2')continue;
			dist20[nx][ny] = dist20[t.x][t.y] + 1;
			if (map20[nx][ny] == '4')return dist20[nx][ny];
			q20.push({ nx,ny });
		}
	}



}


int main()
{
	ios::sync_with_stdio, cin.tie(0), cout.tie(0);
	cin >> m20 >> n20 >> xx >> yy;
	for (int i = 0; i < 4; ++i)
	{
		move20.push_back({ xx * a20[i],yy * b20[i] });
		move20.push_back({ yy * a20[i],xx * b20[i] });
	}
	memset(dist20, -1, sizeof dist20);
	for (int i = 1; i <= m20; ++i)
	{
		for (int j = 1; j <= n20; ++j)
		{
			cin >> map20[i][j];
			if (map20[i][j] == '3')
			{
				q20.push({ i,j });
				dist20[i][j] = 0;
			}
		}
	}
	cout << bfs12();

	return 0;
}