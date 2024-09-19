#include <bits/stdc++.h>

using namespace std;

int dp1[105],dp2[105];
int a[105];
int n;

int main()
{
    cin>>n;
    for(int i = 1;i<=n;++i)
    {
        cin>>a[i];
    }
    a[0] = 0;
    dp1[0] = 0;
    for(int i = 1;i<=n;++i)
    {
        for(int j = 0;j<i;++j)
        {
            if(a[i]>a[j])
            {
                dp1[i] = max(dp1[j]+1,dp1[i]);
            }
        }
    }
    a[n+1] = 0;
    dp2[n+1] = 0;
    for(int i = n;i>0;--i)
    {
        for(int j = n+1;j>i;--j)
        {
            if(a[i]>a[j])
            {
                dp2[i] = max(dp2[j]+1,dp2[i]);
            }
        }
    }

    int ans = 105;
    for(int i = 1;i<=n;++i)
    {
        ans = min(ans,n-dp1[i]-dp2[i]+1);
    }

    cout<<ans<<endl;


    return 0;
}