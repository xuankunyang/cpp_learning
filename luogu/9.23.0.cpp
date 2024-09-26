#include <bits/stdc++.h>

using namespace std;

int dp[10005];
int n,t,front,id,ans;


int main()
{
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    
    cin>>n;
    for(int i = 1;i<=n;++i)
    {
        cin>>id>>t;
        int m = 0;
        cin>>front;
        while(front)
        {
            m = max(m,dp[front]);
            cin>>front;
        }
        dp[id] = t + m;
        ans = max(ans,dp[id]);
    }
    
    cout<<ans;
    

    return 0;
}