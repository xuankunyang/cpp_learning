#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int n37, m37, t37,sx37,sy37,fx37,fy37;
bool vis37[6][6];
int nx37[] = { 0,0,1,-1 };
int ny37[] = { 1,-1,0,0 };
int ans37 = 0;

void dfs17(int x,int y)
{
	if (x == fx37 && y == fy37)
	{
		ans37++;
		return;
	}
	vis37[x][y] = 1;
	for (int i = 0; i < 4; ++i)
	{
		int nx = x + nx37[i], ny = y + ny37[i];
		if (nx<=0 || ny<=0 || nx>n37 || ny>m37)continue;
		if (vis37[nx][ny])continue;
		dfs17(nx, ny);
	}
	vis37[x][y] = 0;
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	memset(vis37, 0, sizeof vis37);
	cin >> n37 >> m37 >> t37;
	cin >> sx37 >> sy37 >> fx37 >> fy37;
	int x, y;
	for (int i = 0; i < t37; ++i)
	{
		cin >> x >> y;
		vis37[x][y] = 1;
	}
	dfs17(sx37, sy37);
	cout << ans37 << endl;

	return 0;
}