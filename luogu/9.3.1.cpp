#include <bits/stdc++.h>

using namespace std;

int dp[300005];
int m,s,t;

int main()
{
    cin>>m>>s>>t;
    dp[0] = 0;
    for(int i = 1;i<=t;++i)
    {
        if(m>=10)
        {
            dp[i] = dp[i-1] + 60;
            m -= 10;
        }
        else 
        {
            dp[i] = dp[i-1];
            m += 4;
        }
    }
    
    for(int i = 1;i<=t;++i)
    {
        if(dp[i]<dp[i-1] + 17)
        {
            dp[i] = dp[i-1] + 17;
        }
        if(dp[i]>=s)
        {
            cout<<"Yes"<<endl<<i;
            return 0;
        }
    }
    cout<<"No"<<endl<<dp[t];





    return 0;
}