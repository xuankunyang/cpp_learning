#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int m;
	ios::sync_with_stdio, cin.tie(0), cout.tie(0);
	cin >> m;
	vector<int>dp50(m + 1 , m);
	dp50[0] = 0;
	dp50[1] = 1;
	for (int i = 2; i <= m; ++i)
	{
		for (int j = 1; i - j * j * j * j >= 0; ++j)
		{
			dp50[i] = min(dp50[i], dp50[i - j * j * j * j] + 1);
		}
	}
	cout << dp50[m];





	return 0;
}