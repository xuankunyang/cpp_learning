#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int n36;
vector <int> s36, b36;

long long solve36()
{
	long long ans=1e9;
	int s = pow(2, n36);
	for (int i = 0; i < s; ++i)
	{
		long long souce = 1, bitter = 0;
		int j = i;
		for (int k = 0; k < n36; ++k)
		{
			if (j & 1)
			{
				souce *= s36[k];
				bitter += b36[k];
				ans = min(abs(souce - bitter), ans);
			}
			j >>= 1;
		}
	}

	return ans;
}


int main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n36;
	int a, b;
	for (int i = 1; i <= n36; ++i)
	{
		cin >> a >> b;
		s36.push_back(a);
		b36.push_back(b);
	}

	cout << solve36();

	return 0;
}