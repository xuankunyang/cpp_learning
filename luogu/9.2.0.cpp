#include <bits/stdc++.h>
using namespace std;

int r;
int a[1005][1005] = {0};
int dp[1005][1005] = {0};

int main()
{
    ios::sync_with_stdio,cin.tie(0),cout.tie(0);

    int ans = 0;

    cin>>r;
    for(int i = 1;i<=r;++i)
    {
        for(int j = 1;j<=i;++j)
        {
            cin>>a[i][j];
            if(i>=1 && j==1)
            {
                dp[i][j] = a[i][j] + dp[i-1][j];
            }
            else if(i>1 && j==r)
            {
                dp[i][j] = a[i][j] + dp[i-1][j-1];
            }
            else
            {
                dp[i][j] = max(a[i][j] + dp[i-1][j-1],a[i][j] + dp[i-1][j]);
            }
            if(i==r)
            {
                ans = max(ans,dp[r][j]);
            }
        }
    }

    cout<<ans<<endl;



    return 0;
}