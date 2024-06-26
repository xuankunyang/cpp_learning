#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int n, vv,v,w,s;
	ios::sync_with_stdio, cin.tie(0), cout.tie(0);
	cin >> n >> vv;
	vector<int>dp22(vv + 1);
	for (int i = 1; i <= n; ++i)
	{
		cin >> v >> w >> s;
		while (s--)
		{
			for (int j = vv; j >= v; --j)
			{
				dp22[j] = max(dp22[j], dp22[j - v] + w);
			}
		}
	}
	cout << dp22[vv];

	return 0;
}