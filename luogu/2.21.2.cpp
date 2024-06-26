#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;

int main()
{
	int n, m, k;
	ios::sync_with_stdio, cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
	vector<int>a(n + 1), b(m + 1), c(m + 1);
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}
	for (int i = 1; i <= m; ++i)
	{
		cin >> b[i];
	}
	for (int i = 1; i <= m; ++i)
	{
		cin >> c[i];
	}
	int t = k * 100;//这里考虑能提升力量值的极限情况
	vector<int>dp20(t + 1, 1e9);//这里的dp[i]表示一个士兵提升i点力量值至少需要的精力
	dp20[0] = 0;
	for (int i = 1; i <= m; ++i)
	{
		for (int j = 0; j <= t; ++j)
		{
			dp20[j] = min(dp20[j], dp20[max(j-b[i],0)] + c[i]);
		}
	}
	int lh = 0, rh = t+1;//二分答案
	while (lh + 1 != rh)
	{
		int mid = (lh + rh) / 2;
		ll ans = 0;
		for (int i = 1; i <= n; ++i)
		{
			if (a[i] < mid)
				ans += dp20[mid - a[i]];//每个士兵提升至mid及以上至少还要消耗多少精力
		}
		if (ans > k)rh = mid;
		else lh = mid;
	}
	cout << lh;




	return 0;
}