#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n2,sum2=0;
int t2[105], w2[105];
bool check1(int x)
{
	vector<int>dp41(x + 1,sum2);
	for (int i = 1; i <= n2; ++i)
	{
		for (int j = x; j >= t2[i]; --j)
		{
			dp41[j] = min(dp41[j], dp41[j - t2[i]] - w2[i]);
		}
	}
	return x<=dp41[x];
}
void find1(int lh, int rh)
{
	while (lh+1!=rh)
	{
		int mid = (lh + rh) / 2;
		if (check1(mid))lh = mid;
		else rh = mid;
	}
	cout << lh;
}

int main()
{
	ios::sync_with_stdio, cin.tie(0), cout.tie(0);
	cin >> n2;
	for (int i = 1; i <= n2; ++i)
	{
		cin >> t2[i] >> w2[i];
		sum2 += w2[i];
	}
	find1(0, 200);

	return 0;
}