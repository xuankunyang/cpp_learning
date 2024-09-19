#include <bits/stdc++.h>

using namespace std;

int dp[41][41][41][41];
int s[355],num[5] = {0};
int n,m;

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    cin>>n>>m;
    for(int i = 1;i<=n;++i)
    {
        cin>>s[i];
    }
    int x;
    for(int i = 1;i<=m;++i)
    {
        cin>>x;
        num[x]++;
    }
    dp[0][0][0][0] = s[1];
    for(int a = 0;a<=num[1];++a)
    {
        for(int b = 0;b<=num[2];++b)
        {
            for(int c = 0;c<=num[3];++c)
            {
                for(int d = 0;d<=num[4];++d)
                {
                    x = 1 + a + 2*b + 3*c + 4*d;
                    if(a)dp[a][b][c][d] = max(dp[a-1][b][c][d]+s[x],dp[a][b][c][d]);
                    if(b)dp[a][b][c][d] = max(dp[a][b-1][c][d]+s[x],dp[a][b][c][d]);
                    if(c)dp[a][b][c][d] = max(dp[a][b][c-1][d]+s[x],dp[a][b][c][d]);
                    if(d)dp[a][b][c][d] = max(dp[a][b][c][d-1]+s[x],dp[a][b][c][d]);
                }
            }
        }
    }

    cout<<dp[num[1]][num[2]][num[3]][num[4]];




    return 0;
}