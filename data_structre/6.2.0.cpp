#include <iostream>
#include <cstring>
#include "seqList.h"
using namespace std;

seqList<int>edge[500005];
seqList<int>ask1,ask2;
int n7, m7, s7;
int fa7[500005][21];
int dep7[500005];

void swap(int& x, int& y)
{
	int tmp = x;
	x = y;
	y = tmp;
}
void dfs7(int x, int fa)
{
	dep7[x] = dep7[fa] + 1;
	fa7[x][0] = fa;
	for (int i = 1; i <30; ++i)
	{
		if (dep7[x] - (1 << i) <= 0)break;
		fa7[x][i] = fa7[fa7[x][i - 1]][i - 1];
	}
	for (int i = 1; i <= edge[x].size(); ++i)
	{
		int y = edge[x][i];
		if (fa == y)continue;
		dfs7(y, x);
	}
}

int lca7(int x, int y)
{
	if (dep7[x] < dep7[y])swap(x, y);
	for (int i = 20; i >= 0; --i)
	{
		if (fa7[x][i] == 0)continue;
		if (dep7[fa7[x][i]] < dep7[y])continue;
		x = fa7[x][i];
	}
	if (x == y)return y;
	for (int i = 20; i >= 0; --i)
	{
		if (fa7[x][i] == 0)continue;
		if (fa7[x][i] == fa7[y][i])continue;
		x = fa7[x][i];
		y = fa7[y][i];
	}
	return fa7[x][0];
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	memset(fa7, 0, sizeof fa7);
	memset(dep7, 0, sizeof dep7);
	cin >> n7 >> m7 >> s7;
	int x, y;
	for (int i = 1; i < n7; ++i)
	{
		cin >> x >> y;
		edge[x].push_back(y);
		edge[y].push_back(x);
	}
	for (int i = 1; i <= m7; ++i)
	{
		cin >> x >> y;
		ask1.push_back(x);
		ask2.push_back(y);
	}
	dfs7(s7,0);
	for (int i = 1; i <= m7; ++i)
	{
		int x = ask1[i];
		int y = ask2[i];
		cout << lca7(x, y) << endl;
	}

	
	


	return 0;
}