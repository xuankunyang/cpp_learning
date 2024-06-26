#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <utility>

using namespace std;
#define x first 
#define y second 

int n40;
int map40[35][35];
bool vis40[35][35];
int nx40[] = { 1,-1,0,0 };
int ny40[] = { 0,0,1,-1 };

void bfs18(int x0, int y0)
{
	queue<pair<int, int>>q;
	q.push({ x0,y0 });
	while (q.size())
	{
		auto t = q.front();
		q.pop();
		for (int i = 0; i < 4; ++i)
		{
			int nx = t.x + nx40[i], ny = t.y + ny40[i];
			if (nx < 1 || ny < 1 || nx>n40 || ny>n40)continue;
			if (map40[nx][ny] == 1)continue;
			if (vis40[nx][ny])continue;
			vis40[nx][ny] = 1;
			q.push({ nx,ny });
		}
	}
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	memset(vis40, 0, sizeof vis40);
	cin >> n40;
	for (int i = 1; i <= n40; ++i)
	{
		for (int j = 1; j <= n40; ++j)
		{
			cin >> map40[i][j];
		}
	}
	for (int i = 1; i <= n40; ++i)
	{
		if (map40[1][i] == 0&&!vis40[1][i])bfs18(1, i);
		if (map40[n40][i] == 0&&!vis40[n40][i])bfs18(n40, i);
	}
	for (int i = 2; i < n40; ++i)
	{
		if (map40[i][1] == 0&&!vis40[i][1])bfs18(i, 1);
		if (map40[i][n40] == 0&&!vis40[i][n40])bfs18(i, n40);
	}

	for (int i = 1; i <= n40; ++i)
	{
		for (int j = 1; j <= n40; ++j)
		{
			if (map40[i][j] || vis40[i][j])cout << map40[i][j]<<" ";
			else cout <<2<<" ";
		}
		cout << endl;
	}


	return 0;
}

