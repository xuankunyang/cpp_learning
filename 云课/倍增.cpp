#include <iostream>
using namespace std;
using ll = long long;
#define mod 998244353
ll ksm(ll a, ll b)
{
	ll res = 1;
	while (b)
	{
		if (b & 1)res = res * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return res % mod;
}
int main()
{
	//¿ìËÙÃÝ
	ll a, b;
	cin >> a >> b;
	cout << ksm(a, b) % mod << endl;



	return 0;
}