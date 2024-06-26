#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>

using namespace std;

const int N42 = 105;
int n42;
vector<int>edge42[N42];
int dep42[N42];
int fa42[N42][21];

void dfs19(int x, int fa)
{
	dep42[x] = dep42[fa] + 1;
	fa42[x][0] = fa;
	for (int i = 1; i <= 20; ++i)
	{
		if (dep42[x] - pow(2, i) < 1)break;
		fa42[x][i] = fa42[fa42[x][i - 1]][i - 1];
	}
	for (const int& y : edge42[x])
	{
		if (fa == y)continue;
		dfs19(y, x);
	}
}

int lca3(int x, int y)
{
	if (dep42[x] < dep42[y])swap(x, y);
	for (int i = 20; i >= 0; --i)
	{
		if (fa42[x][i] == 0)continue;
		if (dep42[fa42[x][i]] < dep42[y])continue;
		x = fa42[x][i];
	}
	if (x == y)return x;
	for (int i = 20; i >= 0; --i)
	{
		if (fa42[x][i] == 0)continue;
		if (fa42[x][i] == fa42[y][i])continue;
		x = fa42[x][i];
		y = fa42[y][i];
	}
	return fa42[x][0];
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	memset(dep42, 0, sizeof dep42);
	cin >> n42;
	int x, y;
	for (int i = 1; i < n42; ++i)
	{
		cin >> x >> y;
		edge42[x].push_back(y);
		edge42[y].push_back(x);
	}
	cin >> x >> y;
	dfs19(1, 0);
	int lca = lca3(x, y);
	int dis = 2*(dep42[x]-dep42[lca])+dep42[y]-dep42[lca];
	int dep = *max_element(dep42 + 1, dep42 + n42 + 1);
	vector<int>a(n42 + 1, 0);
	for (int i = 1; i <= n42; ++i)
	{
		a[dep42[i]]++;
	}
	int wid = *max_element(a.begin(), a.end());
	cout << dep << endl << wid << endl<< dis << endl;

	return 0;
}
