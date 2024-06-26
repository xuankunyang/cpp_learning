#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <utility>

using namespace std;
#define x first
#define y second

int n11, m11,a11,b11;
const int N11 = 505;
int dist11[N11][N11];
int dx11[] = { 1,-1,0,0 };
int dy11[] = { 0,0,1,-1 };
queue<pair<int, int>>q11;

void bfs6()
{
	while (!q11.empty())
	{
		auto t = q11.front();
		q11.pop();
		for(int i=0;i<4;++i)
		{
			int nx = t.x + dx11[i], ny = t.y + dy11[i];
			if (nx<1 || ny<1 || nx>n11 || ny>m11 || dist11[nx][ny] != -1)continue;
			dist11[nx][ny] = dist11[t.x][t.y] + 1;
			q11.push({ nx,ny });
		}
	}
}

int main()
{
	ios::sync_with_stdio, cin.tie(0), cout.tie(0);
	memset(dist11, -1, sizeof dist11);
	cin >> n11 >> m11 >> a11 >> b11;
	for (int i = 1; i <= a11; ++i)
	{
		int x0, y0;
		cin >> x0 >> y0;
		q11.push({ x0,y0 });
		dist11[x0][y0] = 0;
	}
	bfs6();
	for (int i = 1; i <= b11; ++i)
	{
		int a, b;
		cin >> a >> b;
		cout << dist11[a][b] << endl;
	}


	return 0;
}