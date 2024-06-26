#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <set>
#include <functional>

using namespace std;
using ll = long long;

vector <int> a35;
vector <ll>  res35;
bool vis35[10000009];
int n35, k35;

ll prime35[10005];
ll ans35=0;

int Euler_sieve(ll n)
{
	int i, j, k=0;
	for (i = 2; i <= n; ++i)
	{
		if (vis35[i] == 0)
			prime35[k++] = i;
		for (j = 0; j < k; ++j)
		{
			if (i * prime35[j] > n)break;
			vis35[i * prime35[j]] = 1;
			if (i % prime35[j] == 0)break;
		}
	}
	return k;
}

void dfs16(int index)
{
	
	static int num = 0;
	if (num == k35-1)
	{
		res35.push_back(ans35+a35[index]);
		return;
	}
	ans35 += a35[index];
	num++;
	for (int i = index+1; i < n35; ++i)
	{
		dfs16(i);
	}
	ans35 -= a35[index];
	num--;
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	memset(vis35, 0, sizeof vis35);
	cin >> n35 >> k35;
	int x;
	for (int i = 1; i <= n35; ++i)
	{
		cin >> x;
		a35.push_back(x);
	}
	for (int i = 0; i <= n35 - k35; ++i)
	{
		dfs16(i);
	}
	ll m = *max_element(res35.begin(), res35.end());
	
	int size=Euler_sieve(m);
	int ans = 0;
	for (int i=0;i<size;++i)
	{
		for (auto j : res35)
			if (prime35[i] == j)ans++;
	}
	cout << ans;
	




	return 0;
}