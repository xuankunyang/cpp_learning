#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
int main()
{
	int n;
	ios::sync_with_stdio, cin.tie(0), cout.tie(0);
	cin >> n;
	int sum = n * (n + 1) / 2;
	if (sum & 1)
	{
		cout << 0;
		return 0;
	}
	vector<ll>dp39(sum/2+1, 0);
	dp39[0] = 1;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = sum/2; j >=i; --j)
		{
			dp39[j]+=dp39[j - i];
		}
	}
	cout << dp39[sum / 2]/2;







	return 0;
}