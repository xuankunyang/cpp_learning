#include<iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
	int h, n, s;
	ios::sync_with_stdio, cin.tie(0), cout.tie(0);
	cin >> h >> n;
	vector<int>dp31(h + 1);
	for (int i = 1; i <= n; ++i)
	{
		cin >> s;
		for (int j = h; j >= s; --j)
		{
			dp31[j] = max(dp31[j], dp31[j - s] + s);
		}
	}
	cout << dp31[h];



	return 0;
}