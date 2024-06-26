#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
	int n, m, k, r;
	ios::sync_with_stdio, cin.tie(0), cout.tie(0);
	cin >> n >> m >> k >> r;
	vector<int>t1(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		cin >> t1[i];
	}
	vector<int>t2(m + 1);
	int sum = 0;
	for (int i = 1; i <= m; ++i)
	{
		cin >> t2[i];
		sum += t2[i];
	}
	vector<int>score(m + 1);
	for (int i = 1; i <= m; ++i)
	{
		cin >> score[i];
	}
	vector<int>dp33(sum+1);
	for (int i = 1; i <= m; ++i)
	{
		for (int j = sum; j >= t2[i]; --j)
		{
			dp33[j] = max(dp33[j], dp33[j - t2[i]] + score[i]);
		}
	}
	int left;
	for (int i = 0; i <= sum; ++i)
	{
		if (dp33[i] > k)//ÄæÏòË¼Î¬
		{
			left = r - i;
			break;
		}
	}
	vector<int>dp34(left + 1);
	for (int i = 1; i <= n; ++i)
	{
		for (int j = left; j >= t1[i]; --j)
		{
			dp34[j] = max(dp34[j], dp34[j - t1[i]] + 1);
		}
	}
	cout << dp34[left];



	return 0;
}