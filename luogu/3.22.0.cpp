#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
using ll = long long;

int main()
{
	int n,v;
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n>>v;
	vector<int>a(n + 1), b(n + 1);
	int a2b = 0, b2a = 0;
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i] >> b[i];
	}
	ll flag = pow(2, n);
	int ans = 1e8;
	for (ll i = 0; i < flag; ++i)
	{
		ll k = i;
		for (int j = 1;j <= n; ++j)
		{
			if (k & 1)
			{
				a2b += a[j];
				b2a += b[j];
			}
			if (a2b+b2a>=v&&abs(b2a - a2b) == 0)
			{
				cout << 0;
				return 0;
			}
			k >>= 1;
		}
		if (a2b + b2a >= v)
		{
			ans = min(ans, abs(b2a - a2b));
		}
		a2b = 0;
		b2a = 0;
	}
	if (ans == 1e8)cout << -1;
	else cout << ans;
	

	return 0;
}