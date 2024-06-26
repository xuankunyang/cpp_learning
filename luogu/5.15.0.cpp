#include <iostream>
#include <algorithm>
#include <utility>
#include <cmath>

using namespace std;
using ll = long long;

#define x first
#define y second 

ll gcd44(ll a, ll b)
{
	if (a % b == 0)return b;
	else return gcd44(b, a % b);
}

void gcd43(pair<ll, ll>& ans)
{
	if (ans.x < 0 && ans.y < 0)
	{
		ans.x = -ans.x;
		ans.y = -ans.y;
	}
	else if(ans.x>0&&ans.y<0)
	{
		ans.x = -ans.x;
		ans.y = -ans.y;
	}
	bool flag1 = ans.x > 0 ? 1 : 0;
	ans.x = abs(ans.x);
	bool flag2 = ans.x > ans.y;
	ll m = min(ans.x, ans.y),n=max(ans.x,ans.y);
	if (m == 0)
	{
		ans.x = 0;
		ans.y = 1;
		return;
	}
	ll a = gcd44(n, m);
	m /= a;
	n /= a;
	if (flag2)
	{
		ans.x = n;
		ans.y = m;
	}
	else
	{
		ans.x = m;
		ans.y = n;
	}
	if (!flag1)
	{
		ans.x = -ans.x;
	}
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n,a,b,opt;
	cin >> n;
	pair<ll, ll>ans = { 0,1 };
	for (int i = 1; i <= n; ++i)
	{
		cin >> a >> b >> opt;
		if (opt == 1)
		{
			ll tmp = ans.y;
			ans.y = ans.y * b;
			ans.x = ans.x * b + tmp * a;
			gcd43(ans);
		}
		else
		{
			ll tmp = ans.y;
			ans.y = ans.y * b;
			ans.x = ans.x * b - tmp * a;
			gcd43(ans);
		}
		
	}

	if (ans.y == 1)
		cout << ans.x;
	else if (ans.x == 0)
		cout << 0;
	else cout << ans.x <<"/" << ans.y;

	return 0;
}

