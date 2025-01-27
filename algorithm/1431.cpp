#include<bits/stdc++.h>
using namespace std;

int W, n;
long long dp[10005];

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> W;
    long long w, v, c;
    for(int i = 0; i < n; ++i)
    {
        cin>>w>>v>>c;
        for(int k = 1; k < c && k * w <= W ; c -= k, k += k)
        {
            for(long long j = W; j >= k * w; --j)
            {
                dp[j] = max(dp[j], dp[j - k * w] + k * v);
            }
        }
        for(long long j = W; j >= c * w; --j)
        {
            dp[j] = max(dp[j], dp[j - c * w] + c * v);
        }

    }

    cout << dp[W];


    return 0;
}