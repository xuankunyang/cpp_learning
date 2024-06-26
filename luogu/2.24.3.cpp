#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
	int n, m,v,w;
	ios::sync_with_stdio, cin.tie(0), cout.tie(0);
	cin >> n >> m;
	vector<int>dp29(n+1);
	for (int i = 1; i <= m; ++i)
	{
		cin >> v >> w;
		for (int j = n; j >= v ; --j)
		{
			dp29[j] = max(dp29[j], dp29[j - v] + v * w);
		}
	}
	cout << dp29[n];
	return 0;
}