#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int gcd(int x)
{
	int ans = 0;
	for (int i = 1; i <= x/2; ++i)
	{
		if (x % i == 0)
			ans += i;
	}
	return  ans;
}
int main()
{
	int s;
	ios::sync_with_stdio, cin.tie(0), cout.tie(0);
	cin >> s;
	vector<int>dp36(s + 1);
	for (int i = 1; i <= s; ++i)
	{
		for (int j = s; j >= i; --j)
		{
			dp36[j] = max(dp36[j], dp36[j - i] + gcd(i));
		}
	}
	cout << dp36[s];





	return 0;
}