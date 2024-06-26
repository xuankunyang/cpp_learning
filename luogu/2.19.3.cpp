#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
struct lqyk
{
	int t, ddl, value;
};
int main()
{
	int n;
	ios::sync_with_stdio, cin.tie(0), cout.tie(0);
	cin >> n;
	vector<lqyk>kc(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		cin >> kc[i].t >> kc[i].ddl >> kc[i].value;
	}
	sort(kc.begin() + 1, kc.end(), [](lqyk a, lqyk b)
		{
			return a.ddl < b.ddl;
		});
	vector<ll>dp16(kc[n].ddl + 1);
	for (int i = 1; i <= n; ++i)
	{
		for (int j = kc[i].ddl; j >= kc[i].t; --j)
		{
			dp16[j] = max(dp16[j], dp16[j - kc[i].t] + kc[i].value);
		}
	}
		cout << *max_element(dp16.begin() + 1, dp16.end()) << endl;



	return 0;
}
