#include<iostream>
#include <algorithm>
#include <utility>
#include <queue>
#include <cstring>

using namespace std;
#define x first 
#define y second

int n23, m23;
char map23[305][305];
int dist23[2][305][305];
queue<pair<int, int>>q23[2];
int dx23[] = { 1,-1,0,0 };
int dy23[] = { 0,0,1,-1 };
short vis23[2][305][305];

void fd23(int& nx, int& ny)
{
	for (int i = 1; i <= n23; ++i)
	{
		for (int j = 1; j <= m23; ++j)
		{
			if (map23[i][j] == map23[nx][ny] && (nx != i || ny != j))
			{
				nx = i;
				ny = j;
				return;
			}
		}
	}
}

int expand23(int pos)
{
	auto t = q23[pos].front();
	q23[pos].pop();
	for (int i = 0; i < 4; ++i)
	{
		int nx = t.x + dx23[i], ny = t.y + dy23[i];
		if (nx<1 || ny<1 || nx>n23 || ny>m23 || map23[nx][ny] == '#' || vis23[pos][nx][ny])continue;
		if (map23[nx][ny] >= 'A' && map23[nx][ny] <= 'Z')
		{
			vis23[pos][nx][ny]++;
			dist23[pos][nx][ny] = dist23[pos][t.x][t.y] + 1;
			fd23(nx, ny);
		}
		else vis23[pos][nx][ny] = 1;
		q23[pos].push({ nx,ny });
		dist23[pos][nx][ny] = dist23[pos][t.x][t.y] + 1;
		if (vis23[1 - pos][nx][ny])
		{
			if (map23[nx][ny] >= 'A' && map23[nx][ny] <= 'Z')
			{
				if (vis23[pos][nx][ny] == 2 || vis23[1 - pos][nx][ny] == 2)
					return dist23[pos][nx][ny] + dist23[1 - pos][nx][ny];
			}
			else return dist23[pos][nx][ny] + dist23[1 - pos][nx][ny];
		}
	}

	return 0;

}


int bfs13()
{
	int ans;
	while (!q23[0].empty() && !q23[1].empty())
	{
		if (q23[0].size() < q23[1].size())ans= expand23(0);
		else ans =expand23(1);
		if (ans)return ans;
	}
}

int main()
{
	ios::sync_with_stdio, cin.tie(0), cout.tie(0);
	cin >> n23 >> m23;
	memset(dist23, 0, sizeof dist23);
	memset(vis23, 0, sizeof vis23);
	for (int i = 1; i <= n23; ++i)
	{
		for (int j = 1; j <= m23; ++j)
		{
			cin >> map23[i][j];
			if (map23[i][j] == '@')
			{
				q23[0].push({i,j});
				dist23[0][i][j] = 0;
				vis23[0][i][j] = 1;
			}
			else if (map23[i][j] == '=')
			{
				q23[1].push({ i,j });
				dist23[1][i][j] = 0;
				vis23[1][i][j] = 1;
			}
			
		}
	}
	cout << bfs13();
	
	return 0;
}