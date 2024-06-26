#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main()
{
	ll vv, n, c,v,e;
	ios::sync_with_stdio, cin.tie(0), cout.tie(0);
	cin >> vv >> n >> c;
	vector<ll>dp30(c + 1, 0);//这里的dp使用逆向思维 表示使用i的体力能搬运的最大木石总体积
	for (int i = 1; i <= n; ++i)
	{
		cin >> v >> e;
		for (int j = c; j>=e; --j)
		{
			dp30[j] = max(dp30[j], dp30[j - e]+v);
		}

	}
	for (int i = 1; i <= c; ++i)
	{
		if (dp30[i] >=vv)
		{
			cout << c - i << endl;
			return 0;
		}
	}
	cout << "Impossiple" << endl;
	return 0;
}