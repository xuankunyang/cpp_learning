#include <bits/stdc++.h>

using namespace std;

int dp[205][205];
int n;

int main()
{
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i = 1;i<=n;++i)
    {
        for(int j = i+1;j<=n;++j)
        {
            cin>>dp[i][j];
        }
    }
    for(int i = 1;i<=n;++i)
    {
        for(int j = i+1;j<=n;++j)
        {
            int m = 10000005;
            for(int k = i;k<=j;++k)
            {
                m = min(m,dp[i][k]+dp[k][j]);
            }
            dp[i][j] = m;
        }
    }

    cout<<dp[1][n];
    



    return 0;
}