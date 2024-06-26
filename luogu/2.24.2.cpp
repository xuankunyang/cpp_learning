#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
	int v, n,vv;
	ios::sync_with_stdio, cin.tie(0), cout.tie(0);
	cin >> v >> n;
	vector<int>dp28(v+1, v);
	for (int i = 1; i <= n; ++i)
	{
		cin >> vv;
		for (int j = v; j >= vv; --j)
		{
			dp28[j] = min(dp28[j], dp28[j - vv] - vv);
		}
	}
	cout << dp28[v];

	return 0;
}