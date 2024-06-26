#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
int main()
{
	int n, vv,v,w,s;
	ios::sync_with_stdio, cin.tie(0), cout.tie(0);
	cin >> n >> vv;
	vector<ll>dp23(vv + 1);
	for (int i = 1; i <= n; ++i)
	{
		cin >> v >> w >> s;
		for (int k = 1; s > k; s -= k, k += k)
		{
			for (int j = vv; j >= k*v; --j)
			{
				dp23[j] = max(dp23[j], dp23[j - k*v] + k*w);
			}
		}
		for (int j = vv; j >= s*v; --j)
		{
			dp23[j] = max(dp23[j], dp23[j - s * v] + s * w);
		}
	}
	cout << dp23[vv];


	return 0;
}