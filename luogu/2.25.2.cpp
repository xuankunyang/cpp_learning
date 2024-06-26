#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int c, h, v;
	ios::sync_with_stdio, cin.tie(0), cout.tie(0);
	cin >> c >> h;
	vector<int>dp32(c + 1);
	for (int i = 1; i <= h; ++i)
	{
		cin >> v;
		for (int j = c; j >= v; --j)
		{
			dp32[j] = max(dp32[j], dp32[j - v] + v);
		}
	}
	cout << dp32[c];


	return 0;
}