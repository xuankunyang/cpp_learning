#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
	int n, vv;
	ios::sync_with_stdio, cin.tie(0), cout.tie(0);
	cin >> n >> vv;
	vector<int>w(n + 1), v(n + 1), s(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		cin >> w[i] >> v[i] >> s[i];
	}
	vector<int>dp21(vv + 1);
	for (int i = 1; i <= n; ++i)
	{
		while(s[i]--)
		for (int j = vv; j >= w[i]; --j)
		{
			dp21[j] = max(dp21[j], dp21[j - w[i]] + v[i]);
		}
	}
	cout<<dp21[vv];




	return 0;
}