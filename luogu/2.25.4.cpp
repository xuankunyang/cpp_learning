#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
int main()
{
	int n, m,l,w,u;
	ios::sync_with_stdio, cin.tie(0), cout.tie(0);
	cin >> n >> m;
	vector<ll>dp35(m + 1);
	for (int i = 1; i <= n; ++i)
	{
		cin >> l >> w >> u;
		for (int j = m; j >= 0; --j)
		{
			if (j >= u)
			{
				dp35[j] = max(dp35[j] + l, dp35[j - u] + w);
			}
			else dp35[j] = dp35[j] + l;//这里是一个细节 没打败也可以有经验
		}
	}
	cout << dp35[m]*5;



	return 0;
}