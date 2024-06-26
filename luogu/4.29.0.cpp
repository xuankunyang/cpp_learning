#include <iostream>
#include <queue>
#include <utility>
#include <cstring>

using namespace std;
#define x first 
#define y second

int ans38 = 0;
int n38, m38;
bool vis38[105][105];
char map38[105][105];
queue <pair<int, int>>q38;
int nx38[] = { 1,1,1,0,0,-1,-1,-1 };
int ny38[] = {0, 1, -1, 1, -1, 0, 1, -1};

void bfs16(int x0,int y0)
{
	q38.push({ x0,y0 });
	while (q38.size())
	{
		auto t = q38.front();
		q38.pop();
		for (int i = 0; i < 8; ++i)
		{
			int nx = t.x + nx38[i], ny = t.y + ny38[i];
			if (nx < 0 || ny < 0 || nx >= n38 || ny >= m38)continue;
			if (map38[nx][ny] == '.')continue;
			if (vis38[nx][ny])continue;
			vis38[nx][ny] = 1;
			q38.push({ nx,ny });
		}
	}
	ans38++;
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	memset(vis38, 0, sizeof vis38);
	cin >> n38 >> m38;
	for (int i = 0; i < n38; ++i)
	{
		cin >> map38[i];
	}
	for (int i = 0; i < n38; ++i)
	{
		for (int j = 0; j < m38; ++j)
		{
			if (map38[i][j] == '.')continue;
			if (vis38[i][j])continue;
			bfs16(i, j);
		}
	}

	cout << ans38 << endl;

	return 0;
}
