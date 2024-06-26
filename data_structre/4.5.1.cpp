#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

const int N4 = 1005;
int xx[N4], yy[N4];
int n4, r4, w4;
bool vis4[N4],isok[N4];
int nowx=0, nowy=0;

bool dfs2(int k)
{
	if (abs(w4 - nowy) <= r4)return 1;
	vis4[k] = 1;
	for (int i = 1; i <= n4; ++i)
	{
		if (vis4[i])continue;
		if (!isok[i])continue;
		if ((xx[k] - xx[i]) * (xx[k]-xx[i]) + (yy[k]-yy[i]) * (yy[k]-yy[i]) > 4 * r4 * r4 )continue;
		nowx = xx[i], nowy = yy[i];
		if (dfs2(i))return 1;
	}
	vis4[k] = 0;
	isok[k] = 0;
	return 0;
}


int main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	
	memset(vis4, 0, sizeof vis4);
	memset(isok, 1, sizeof isok);
	cin >> n4 >> r4 >> w4;
	for (int i = 1; i <= n4; ++i)
	{
		cin >> xx[i] >> yy[i];
	}
	for (int i = 1; i <= n4; ++i)
	{
		if(abs(yy[i])<=r4)
		{
			nowx = xx[i], nowy = yy[i];
			if (dfs2(i))
			{
				cout << 1;
				return 0;
			}
		}
	}
	cout << 0;



	return 0;
}