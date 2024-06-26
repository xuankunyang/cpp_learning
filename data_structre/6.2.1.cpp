#include <iostream>
#include <cstring>
using namespace std;

int ans8 = 1000000;
int map8[6][6];
bool vis8[6][6] = { 0 };
int edx, edy;
int nx8[] = { 0,1,0,-1 };
int ny8[] = { 1,0,-1,0 };
int state = 1;
void dfs8(int x, int y,int addup,int state)
{
	if (x == edx && y == edy)
	{
		ans8 = ans8 < addup ? ans8 : addup;
		return;
	}
	vis8[x][y] = 1;
	for (int i = 0; i < 4; ++i)
	{
		int nx = x + nx8[i], ny = y + ny8[i];
		if (nx < 0 || ny < 0 || nx>5 || ny>5)continue;
		if (vis8[nx][ny])continue;
		int cost = map8[nx][ny] * state;
		int new_state = (cost % 4) + 1;
		dfs8(nx, ny, addup + cost, new_state);
	}
	vis8[x][y] = 0;

}

int solve8()
{
	
	int stx, sty;
	for (int i = 0; i < 6; ++i)
	{
		for (int j = 0; j < 6; ++j)
		{
			cin >> map8[i][j];
		}
	}
	cin >> stx >> sty >> edx >> edy;
	vis8[stx][sty] = 1;
	dfs8(stx, sty,0,1);
	int tmp = ans8;
	ans8 = 1000000;
	memset(vis8, 0, sizeof vis8);
	state = 1;
	vis8[stx][sty] = 0;
	return tmp;
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	int* a = new int[t];
	for (int i = 0; i < t; ++i)
	{
		a[i]=solve8();
	}
	for (int i = 0; i < t; ++i)
	{
		cout << a[i] << endl;
	}





	return 0;
}