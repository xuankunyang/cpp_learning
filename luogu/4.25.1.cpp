#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
#include <cstring>

using namespace std;
#define x first
#define y second

int t34[302][302];
//典型错误：int a[10]={1} 只能将第一个元素赋值为1！！！
queue<pair<int, int>>q34;
int tt34[302][302];
bool vis34[302][302];
int m34;
int nx34[] = { 1,-1,0,0 };
int ny34[] = { 0,0,1,-1 };

int bfs16()
{
	q34.push({ 0,0 });
	tt34[0][0] = 0;
	vis34[0][0] = 1;
	while (q34.size())
	{
		auto head = q34.front();
		q34.pop();
		for (int i = 0; i < 4; ++i)
		{
			int nx = head.x + nx34[i];
			int ny = head.y + ny34[i];
			if (nx < 0 || ny < 0 )continue;
			if (vis34[nx][ny])continue;
			tt34[nx][ny] = tt34[head.x][head.y] + 1;
			if (t34[nx][ny] == -1)return tt34[nx][ny];
			if (tt34[nx][ny] >= t34[nx][ny])continue;
			q34.push({ nx,ny });
			vis34[nx][ny] = 1;
		}
	}
	return -1;
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	memset(tt34, -1 , sizeof tt34);//靠memset给int赋值只能赋为0或-1
	memset(t34, -1, sizeof t34);
	memset(vis34, 0, sizeof vis34);
	cin >> m34;
	int xx, yy,t;
	for (int i = 1; i <= m34; ++i)
	{
		cin >> xx >> yy >> t;
		if (t34[xx][yy] == -1)t34[xx][yy] = t;
		else t34[xx][yy] = min(t, t34[xx][yy]);
		for (int j = 0; j < 4; ++j)
		{
			int nx = xx + nx34[j];
			int ny = yy + ny34[j];
			if (nx < 0 || ny < 0)continue;
			if (t34[nx][ny] == -1)t34[nx][ny] = t;
			else t34[nx][ny] = min(t, t34[nx][ny]);
		}
		
	}
	if (t34[0][0] == -1)
	{
		cout << 0 << endl;
		return 0;
	}
	cout << bfs16() << endl;


	return 0;
}