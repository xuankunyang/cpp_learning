#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
int main()
{
	int n;
	ll ans = 0;
	ios::sync_with_stdio, cin.tie(0), cout.tie(0);
	cin >> n;
	if (n * (n + 1) / 2 & 1)
	{
		cout << 0;
		return 0;
	}
	int s = n * (n + 1) / 4;
	vector<ll>cnt(n*(n+1)/2+1, 0);
	for (int i = 0; i < (1 << n / 2); ++i)
	{
		int sum = 0;
		for (int j = 1; (i>>(j-1))>0; ++j)
		{
			if((i>>(j-1)&1))sum+=j;
		}
		cnt[sum]++;
	}
	int k = n & 1 ? n / 2 + 1 : n / 2;
	for (int i = 0; i < (1 << k); ++i)
	{
		int sum = 0;
		for (int j = 1; (i >> (j - 1)) > 0; ++j)
		{
			if ((i >> (j-1) & 1))sum += (n/2+j);
		}
		if (s >= sum)ans += cnt[s - sum];
	}
	
	
	cout << ans/2;

	return 0;
}