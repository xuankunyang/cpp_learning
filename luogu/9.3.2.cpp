#include <bits/stdc++.h>

using namespace std;

int n,m;
int a[355],b[45];

int solve(vector<bool> vis,int x)
{
    bool flag[5] = {0};
    if(x == m)
    {
        return a[n];
    }
    int res = 0;
    for(int i = 1;i<=m;++i)
    {
        if(!vis[i])
        {
            if(flag[b[i]])continue;
            vector<bool> vis_ = vis;
            vis_[i] = 1;
            res = max(res,solve(vis_,x+b[i]));
            flag[b[i]] = 1;
        }
    }
    return res+a[x];
    
}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    
    cin>>n>>m;
    for(int i = 1;i<=n;++i)
    {
        cin>>a[i];
    }
    for(int i = 1;i<=m;++i)
    {
        cin>>b[i];
    }
    
    vector<bool> vis(m+1,0);
    cout<<solve(vis,1);




    return 0;
}