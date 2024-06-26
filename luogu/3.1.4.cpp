#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <utility>
#include <cstring>

using namespace std;
#define x first
#define y second

int n9,ans9=0;
char map9[550][505];
int dx9[] = { 1,-1,0,0 };
int dy9[] = { 0,0,1,-1 };
queue<pair<int, int>>q9;

void bfs4(int x0, int y0)
{
	map9[x0][y0 - 1] = '.';
	q9.push({ x0,y0 });
	while (q9.size())
	{
		auto t = q9.front();
		q9.pop();
		for (int i = 0; i < 4; ++i)
		{
			int nx = t.x + dx9[i], ny = t.y + dy9[i];
			if (nx<1 || ny<1 || nx>n9 || ny>strlen(map9[nx]) || map9[nx][ny - 1] == '*' || map9[nx][ny - 1] == '.' || map9[nx][ny - 1] == ' ')continue;
			map9[nx][ny - 1] = '.';
			q9.push({ nx,ny });
		}
	}
}


int main()
{
	ios::sync_with_stdio, cin.tie(0), cout.tie(0);
	cin >> n9;
	cin.get();
	for (int i = 1; i <= n9; ++i)
	{
		cin.getline( map9[i],200);
		
	}
	for (int i = 1; i <= n9; ++i)
	{
		for (int j = 0; j < strlen(map9[i]); ++j)
		{
			if (map9[i][j] >= 'a' && map9[i][j] <= 'z')
			{
				bfs4(i, j + 1);
				ans9++;
			}
		}
	}

	cout << ans9;


	return 0;
}