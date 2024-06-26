#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>

using namespace std;
#define x first 
#define y second 

struct pos17
{
	int xx, yy, h;
};

int n17, m17;
int map17[705][705];
bool vis17[705][705];
int dx17[] = { 1,-1,0,0,1,-1,1,-1 };
int dy17[] = { 0,0,1,-1,1,1,-1,-1 };
queue<pair<int, int>>q17;
vector<pos17>a17;

void bfs10()
{
	while (!q17.empty())
	{
		auto t = q17.front();
		q17.pop();
		if (t.x == 0)return;
		for (int i = 0; i < 8; ++i)
		{
			int nx = t.x + dx17[i], ny = t.y + dy17[i];
			if (nx<1 || ny<1 || nx>n17 || ny>m17 || vis17[nx][ny])continue;
			if (map17[nx][ny] <= map17[t.x][t.y])
			{
				vis17[nx][ny] = 1;
				q17.push({ nx,ny });
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio, cin.tie(0), cout.tie(0);
	int ans = 0;
	cin >> n17 >> m17;
	for (int i = 1; i <= n17; ++i)
	{
		for (int j = 1; j <= m17; ++j)
		{
			cin >> map17[i][j];
			a17.push_back({ i,j,map17[i][j] });
		}
	}
	sort(a17.begin(), a17.end(), [](pos17 a, pos17 b)
		{
			return a.h > b.h;
		});
	for (auto& i : a17)
	{
		if (vis17[i.xx][i.yy])continue;
		q17.push({ i.xx,i.yy });
		bfs10();
		ans++;
	}


	cout << ans;

	return 0;
}