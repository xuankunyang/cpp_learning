#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int n4, m4;
const int N4 = 105;
char map4[N4][N4];
int dx4[] = { 1,-1,2,-2,0,0,0,0,1,1,-1,-1};
int dy4[] = { 0,0,0,0,1,-1,2,-2,1,-1,1,-1 };

void dfs4(int x, int y)
{
	if (x<1 || y<1 || y>m4 || x>n4 || map4[x][y - 1] == '-')return;
	map4[x][y - 1] = '-';
	for (int i = 0; i < 12; ++i)
	{
		int nx = x + dx4[i], ny = y + dy4[i];
		dfs4(nx, ny);
	}
}
int main()
{
	ios::sync_with_stdio, cin.tie(0), cout.tie(0);
	cin >> n4 >> m4;
	
	for (int i = 1; i <= n4; i++)
		cin >> map4[i];
	int ans = 0;
	for (int i = 1; i <= n4; ++i)
	{
		for (int j = 0; j < m4; ++j)
		{
			if (map4[i][j] == '#')
			{
				dfs4(i, j+1);
				ans++;
			}
		}
	}


	cout << ans;

	return 0;
}