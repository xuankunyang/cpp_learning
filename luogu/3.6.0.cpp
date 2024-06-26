#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using  namespace std;

int dp46[310][310];
int prefix18[310];
int a18[310];
int main()
{
	int n;
	ios::sync_with_stdio, cin.tie(0), cout.tie(0);
	cin >> n;
	memset(dp46, 0x3f, sizeof dp46);
	prefix18[0] = 0;
	for (int i = 1; i <= n; ++i)
	{
		cin >> a18[i];
		dp46[i][i] = 0;
		prefix18[i] = prefix18[i - 1] + a18[i];
	}
	for (int len = 2; len <= n; ++len)
	{
		for (int lh = 1; lh <=n-len+1; ++lh)
		{
			int rh = lh + len-1;
			for (int cut = lh; cut < rh; ++cut)
			{
				dp46[lh][rh] = min(dp46[lh][rh], dp46[lh][cut] + dp46[cut + 1][rh] + prefix18[rh] - prefix18[lh - 1]);
			}
		}
	}
	cout << dp46[1][n];





	return 0;
}