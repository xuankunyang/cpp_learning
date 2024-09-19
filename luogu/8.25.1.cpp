#include <bits/stdc++.h>

using namespace std;

int n,m;
int rest[1000005],d[1000005],s[1000005],t[1000005];
long long need[1000005] = {0} ,diff[1000005] = {0};

//同样的，利用差分做的优化，可以使用前缀和解决


bool check(int x)
{
    memset(diff,0,sizeof diff);
    for(int i = 1;i<=x;++i)
    {
        diff[s[i]] += d[i];
        diff[t[i]+1] -= d[i];
    }
    for(int i = 1;i<=n;++i)
    {
        need[i] = need[i-1] + diff[i];
        if(need[i]>rest[i])return 0;
    }
    return 1;
}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;++i)
    {
        cin>>rest[i];
    }
    for(int i=1;i<=m;++i)
    {
        cin>>d[i]>>s[i]>>t[i];
    }
    if(check(m))
    {
        cout<<0;
        return 0;
    }
    int lh = 1,rh = m,mid;
    while(lh<rh)
    {
        mid = (lh+rh)/2;
        if(check(mid))lh = mid + 1;
        else rh = mid;
    }
    cout<<-1<<endl;
    cout<<lh;



    return 0;
}

