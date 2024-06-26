#include <iostream>
#include <algorithm>
#include <cstring>
#include <utility>
#include <vector>

using namespace std;
int dp47[505][505];
int a18[505][505];
int main()
{
	int n,m,q;
	ios::sync_with_stdio, cin.tie(0), cout.tie(0);
	memset(dp47, 0, sizeof dp47);
	memset(a18, 0, sizeof a18);
	cin >> n >> m >> q;
	for (int i = 1; i <= m; ++i)
	{
		int l, r;
		cin >> l >> r;
		a18[l][r]++;
	}
	vector<pair<int, int>>qst(q + 1);
	for (int i = 1; i <= q; ++i)
	{
		int l, r;
		cin >> l >> r;
		qst[i].first = l;				
		qst[i].second = r;
	}
	for (int lh = n; lh>0; --lh)
	{
		for (int rh = lh; rh<=n; ++rh)
		{
			dp47[lh][rh] = dp47[lh + 1][rh] + dp47[lh][rh - 1] - dp47[lh + 1][rh - 1]+a18[lh][rh];
		}
	}
	for (int i = 1; i <= q; ++i)
	{
		cout << dp47[qst[i].first][qst[i].second] << endl;
	}




	return 0;
}