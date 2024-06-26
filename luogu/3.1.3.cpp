#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;
#define x first
#define y second

int n8;
pair<int, int> st, ed;
const int N8 = 1e3 + 5;
char map8[N8][N8];
int dist8[N8][N8];
int dx8[] = { 1,-1,0,0 };
int dy8[] = { 0,0,1,-1 };
queue<pair<int, int>>q8;

int bfs3(const int& x0,const int& y0)
{
	memset(dist8, -1, sizeof dist8);
	q8.push({ x0,y0 });
	dist8[x0][y0] = 0;
	while (!q8.empty())
	{
		auto t = q8.front();
		if (t.x == ed.x && t.y == ed.y)
			return dist8[t.x][t.y];
		q8.pop();
		for (int i = 0; i < 4; ++i)
		{
			int nx = t.x + dx8[i], ny = t.y + dy8[i];
			if (nx<1 || ny<1 || nx>n8 || ny>n8 || map8[nx][ny - 1] == '1'||dist8[nx][ny]!=-1)continue;
			q8.push({ nx,ny });
			dist8[nx][ny] = dist8[t.x][t.y] + 1;
		}
	}
}

int main()
{
	ios::sync_with_stdio, cin.tie(0), cout.tie(0);
	cin >> n8;
	for (int i = 1; i <= n8; ++i)
	{
		cin >> map8[i];
	}
	cin >> st.x >> st.y >> ed.x >> ed.y;
	cout << bfs3(st.x, st.y);

	return 0;
}