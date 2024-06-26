#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
	int n,sum=0,ans;
	ios::sync_with_stdio, cin.tie(0), cout.tie(0);
	cin >> n;
	vector<int>t(n + 1), w(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		cin >> t[i] >> w[i];
		sum += t[i];
	}
	vector<int>dp42(sum + 1, 1e5);
	dp42[0] = 0;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = sum; j >= t[i]; --j)
		{
			dp42[j] = min(dp42[j], dp42[j - t[i]] + w[i]);
		}
	}
	for (int i = sum; i >= 0; --i)
	{
		if (sum - i >= dp42[i])
		{
			ans = sum - i;
			break;
		}
	}

	cout << ans;



	return 0;
}