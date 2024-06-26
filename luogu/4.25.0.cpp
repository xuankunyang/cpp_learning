#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <utility>

using namespace std;

int dis33[405][405];
int n33, m33,stx,sty;
#define x first 
#define y second
int nx33[] = { 2,2,-2,-2,1,1,-1,-1 };
int ny33[] = { 1,-1,1,-1,2,-2,2,-2 };


queue<pair<int, int>>q33;

void bfs15()
{
	while (q33.size())
	{
		auto t = q33.front();
		q33.pop();
		for (int i = 0; i < 8; ++i)
		{
			int nx = t.x + nx33[i], ny = t.y + ny33[i];
			if (nx<1 || ny<1 || nx>n33 || ny>m33 || dis33[nx][ny] != -1)continue;
			dis33[nx][ny] = dis33[t.x][t.y] + 1;
			q33.push({ nx,ny });
		}
	}
	for (int i = 1; i <= n33; ++i)
	{
		for (int j = 1; j <= m33; ++j)
		{
			cout << dis33[i][j] << "	";
		}
		cout << endl;
	}
	
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	memset(dis33, -1, sizeof dis33);
	cin >> n33 >> m33 >> stx >> sty;
	q33.push({ stx,sty });
	dis33[stx][sty] = 0;
	bfs15();
	
	


	return 0;
}