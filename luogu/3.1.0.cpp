#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int n5,ans5=0,t5=3;
const int N5 = 15;
bool vis5[N5][N5];
int a5[N5];

void dfs5(int dep)
{
	if (dep > n5)
	{
		ans5++;
		if (t5)
		{
			for (int i = 1; i <= n5; ++i)
				cout << a5[i]<<" ";
			cout << endl;
			t5--;
		}
		return;
	}
	for (int i = 1; i <= n5; ++i)
	{
		bool flag = 1;
		for (int j = 1; j < min(i,dep); ++j)
		{
			if (vis5[dep - j][i - j])
			{
				flag = 0;
				break;
			}
		}
		if (!flag)
			continue;
		for (int j = 1; j<dep&&i+j<=n5; ++j)
		{
			if (vis5[dep - j][i + j])
			{
				flag = 0;
				break;
			}
		}
		if (!flag)
			continue;
		for (int j = 1; j <dep; ++j)
		{
			if (vis5[dep - j][i])
			{
				flag = 0;
				break;
			}
		}
		if (!flag)
			continue;
		vis5[dep][i] = 1;
		a5[dep] = i;
		dfs5(dep + 1);
		vis5[dep][i] = 0;
	}
}




int main()
{
	ios::sync_with_stdio, cin.tie(0), cout.tie(0);
	cin >> n5;
	dfs5(1);
	cout << ans5;


	return 0;
}