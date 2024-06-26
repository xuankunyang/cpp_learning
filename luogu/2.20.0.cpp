#include <iostream>
#include <algorithm>
using namespace std;

//看不懂接着看

int main() 
{
    const int N = 2e4 + 5;
    using ll = long long;
    ll dp17[N];
    int t[N], value[N];
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    int sum = 0;
    for (int i = 1; i <= n; i++) 
    {
        cin >> t[i] >> value[i];
        t[i] += 1; // 因为买完这个商品可以获得 t[i]+1 个商品
        sum = max(sum, t[i]); // 找到等待时间最多的商品，最后获得商品的最多的情况就是 n+sum
    }
    sum += n;

    for (int i = 1; i <= sum + 1; i++)
        dp17[i] = 1e17;

    for (int i = 1; i <= n; i++) 
    {
        for (int j = sum; j >= t[i]; j--)
        {
            dp17[j] = min(dp17[j], dp17[j - t[i]] + value[i]);
        }
    }

    ll ans = 1e18;
    for (int i = n; i <= sum; i++) // 因为买的东西就这几种情况
        ans = min(dp17[i], ans);

    cout << ans << '\n';
    return 0;
}
