#include <bits/stdc++.h>

using namespace std;

int n, m, x;

long long dp[366][366];
vector<int> s[366], a[366];

int main()
{
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    
    cin >> n >> m >> x;

    for(int i = 0; i < m; ++i)
    {
        int s_i, t_i, a_i;

        cin >> s_i >> t_i >> a_i;

        s[t_i].push_back(s_i);
        a[t_i].push_back(a_i);
    }

    memset(dp, -1, sizeof dp);
    dp[0][0] = 0;

    for(int i = 1; i<=n; ++i)
    {
        for(int j = 0; j<=i; ++j)
        {
            dp[i][j] = max(dp[i][j], dp[i-1][j]);

            if (j > 0 && dp[i-1][j-1] >= x)
            {
                dp[i][j] = max(dp[i][j], dp[i-1][j-1] - x);
            }

            for(int k = 0; k<s[i].size(); ++k)
            {
                int start = s[i][k], wage = a[i][k];
                if(dp[start - 1][j] != -1)
                {
                    dp[i][j] = max(dp[i][j], dp[start - 1][j] + wage);
                }
            }
        }
    }

    for(int j = n; j >= 0; --j)
    {
        if(dp[n][j] != -1)
        {
            cout<<dp[n][j]<<endl;
            return 0;
        }
    }

    
    



    return 0;
}