#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;
using ll = long long;
int main()
{
	ll n, p, s,ans;
	ios::sync_with_stdio, cin.tie(0), cout.tie(0);
	cin >> n >> p >> s;
	vector<ll> dp40(s+1);
	vector<pair<ll,ll>>file(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		cin >> file[i].first >> file[i].second;
	}
	sort(file.begin() + 1, file.end());
	for (int i = 1; i <= n; ++i)
	{
		for (int j = s; j >= file[i].first; --j)
		{
			dp40[j] = max(dp40[j], dp40[j - file[i].first] + file[i].second);
			if (dp40[j] >= p)
			{
				cout << file[i].first;
				return 0;
			}
		}
	}
	cout << "No Solution!";




	return 0;
}