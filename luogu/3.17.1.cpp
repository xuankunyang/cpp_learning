#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	vector<int>a(7);
	ios::sync_with_stdio, cin.tie(0), cout.tie(0);
	int sum = 0;
	for (int i = 1; i <= 6; ++i)
	{
		cin >> a[i];
		int kg;
		switch (i)
		{
		case 1:kg = 1; break;
		case 2:kg = 2; break;
		case 3:kg = 3; break;
		case 4:kg = 5; break;
		case 5:kg = 10; break;
		case 6:kg = 20; break;
		}
		sum += (a[i]*kg);
	}
	vector<int>dp53(sum + 1);
	for (int i = 1; i <= 6; ++i)
	{
		int kg;
		switch (i)
		{
		case 1:kg = 1; break;
		case 2:kg = 2; break;
		case 3:kg = 3; break;
		case 4:kg = 5; break;
		case 5:kg = 10; break;
		case 6:kg = 20; break;
		}
		for (int k = 1; k <= a[i]; a[i] -= k, k += k)
		{
			for (int j = sum; j >= k * kg; --j)
			{
				dp53[j] = max(dp53[j], dp53[j - k * kg] + k * kg);
			}
		}
		if (!a[i])continue;
		for (int j = sum; j >= a[i] * kg; --j)
		{
			dp53[j] = max(dp53[j], dp53[j - a[i] * kg] + a[i] * kg);
		}
	}
	int ans = 0;
	for (int i = 1; i <= sum; ++i)
	{
		if (dp53[i] == i)ans++;
	}
	cout << "Total=" << ans;


	return 0;
}