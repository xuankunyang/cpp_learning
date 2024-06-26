#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
int main()
{
	int ans = 0;
	vector<int>s(5);
	ios::sync_with_stdio, cin.tie(0), cout.tie(0);
	for (int i = 1; i <= 4; ++i)
	{
		cin >> s[i];
	}
	vector<vector<int>>t(5, vector<int>(1, 0));
	for (int i = 1; i <= 4; ++i)
	{
		for (int j = 1; j <= s[i]; ++j)
		{
			int x;
			cin >> x;
			t[i].push_back(x);
		}
	}
	for (int i = 1; i <= 4; ++i)
	{
		int m = 1, pd = 1e8,res=0;
		for (int l = 1; l < s[i]; ++l)
		{
			m<<=1;
			m += 1;
		}
		for (int j = 0; j <= m; ++j)
		{
			int lh = 0, rh = 0,jj=j;
			for (int k = 1; k <= s[i]; ++k)
			{
				if (jj & 1)lh += t[i][k];
				else rh += t[i][k];
				jj>>=1;
			}
			if (abs(lh - rh) <= pd)
			{
				 pd=abs(lh-rh);
				res = max(lh, rh);
			}
		}
		ans += res;
	}
	cout << ans;







	return 0;
}
