#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <utility>

using namespace std;
#define x first
#define y second

int dist19[30][30];
int dx19[] = {1,1,-1,-1,2,2,-2,-2,2,2,-2,-2};
int dy19[] = {2,-2,2,-2,1,-1,1,-1,2,-2,2,-2};
queue<pair<int, int>>q19;

void  bfs11(int x0, int y0)
{
	q19.push({ x0,y0 });
	dist19[x0][y0] = 0;
	while (!q19.empty())
	{
		auto t = q19.front();
		q19.pop();
		for (int i = 0; i < 12; ++i)
		{
			int nx = t.x + dx19[i], ny = t.y + dy19[i];
			if (nx < 1 || ny < 1||nx>=30||ny>=30 || dist19[nx][ny] != -1)continue;
			dist19[nx][ny] = dist19[t.x][t.y] + 1;
			q19.push({ nx,ny });
			if (dist19[1][1]!=-1)
			{
				cout << dist19[1][1] << endl;
				return;
			}
		}
	}
}


int main()
{
	int x1, y1, x2, y2;
	ios::sync_with_stdio, cin.tie(0), cout.tie(0);
	cin >> x1 >> y1 >> x2 >> y2;
	memset(dist19, -1, sizeof dist19);
	bfs11(x1, y1);
	while (!q19.empty())
		q19.pop();
	memset(dist19, -1, sizeof dist19);
	bfs11(x2, y2);
	


	return 0;
}