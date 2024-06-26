#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n, vv;
	ios::sync_with_stdio, cin.tie(0), cout.tie(0);
	cin >> vv>> n;
	vector<int>v(n + 1),dp18(vv+1,vv);//此处的dp表示使用j大的空间尽可能装东西剩余的最小空间
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i];
	}
	for (int i = 1; i <= n; ++i)
	{
		for (int j = vv; j >= v[i]; --j)
		{
			dp18[j] = min(dp18[j], dp18[j - v[i]] - v[i]);
		}
	}
	cout << *min_element(dp18.begin() + 1, dp18.end());





	return 0;
}