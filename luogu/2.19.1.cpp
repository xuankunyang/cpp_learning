#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
int main()
{
	ll n, m,a,b,c,d,e;
	ios::sync_with_stdio, cin.tie(0), cout.tie(0);
	cin >> n >> m;
	vector<ll>dp14(m + 1);
	for (int i = 1; i <= n; ++i)
	{
		
		cin >> a >> b >> c >> d >> e;
		for (int j = m; j >= 0; --j)
		{
			dp14[j] = dp14[j] + e;
			if(j>=a)
			{
				dp14[j] = max(dp14[j], dp14[j - a] + b);
				if (j >= c)
				{
					dp14[j] = max(dp14[j], dp14[j - c] + d);
				}
			}
		}
	}

	cout << *max_element(dp14.begin() + 1, dp14.end());



	return 0;
}