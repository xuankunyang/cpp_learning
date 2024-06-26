#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
	int n, vv,w,v;
	ios::sync_with_stdio, cin.tie(0), cout.tie(0);
	cin >> n >> vv;
	vector<int>dp13(vv + 1);
	for (int i = 1; i <= n; ++i)
	{
		cin >> w >> v;
		for (int j = vv; j >= w; --j)
		{
			dp13[j] = max(dp13[j], dp13[j - w] + v);
		}
	}
	cout << dp13[vv];





	return 0;
}