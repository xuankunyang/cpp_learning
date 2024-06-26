#include <iostream>
#include <queue>
#include <cstring>
#include <utility>
using namespace std;
#define x first
#define y second
int w7, h7,ans7=0;
const int N7 = 25;
char map7[N7][N7];
bool vis7[N7][N7];
int dx7[] = { 1,-1,0,0 };
int dy7[] = { 0,0,1,-1 };
queue<pair<int,int>> q7;


void bfs2()
{
	int x0, y0;
	for ( x0 = 1; x0 <= h7; ++x0)
	{
		for ( y0 = 1; y0 <= w7; ++y0)
		{
			if (map7[x0][y0-1] == '@')
				goto FLAG;
		}
	}
FLAG:
	q7.push({ x0,y0 });
	while (q7.size())
	{
		auto t = q7.front();
		q7.pop();
		for (int i = 0; i < 4; ++i)
		{
			int nx = t.x + dx7[i], ny = t.y + dy7[i];
			if (nx<1 || ny<1 || nx>h7 || ny>w7 || map7[nx][ny - 1] == '#'||map7[nx][ny-1]=='@')continue;
			map7[nx][ny - 1] = '@';
			q7.push({ nx,ny });
		}
	}
}

int main()
{
	ios::sync_with_stdio, cin.tie(0), cout.tie(0);
	cin >> w7 >> h7;
	for (int i = 1; i <=h7; ++i)
	{
		cin >> map7[i];
	}
	bfs2();
	for (int i = 1; i <= h7; ++i)
	{
		for (int j = 0; j < w7; ++j)
		{
			if (map7[i][j] == '@')ans7++;
		}
	}
	cout << ans7;

	return 0;
}