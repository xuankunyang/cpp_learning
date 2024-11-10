#include <bits/stdc++.h>

using namespace std;

int n,m;
vector<int>edge[100005],edge_r[100005];
stack<int>finish_order;
bool vis[100005];

void dfs_r(int x)
{
    if(vis[x])
    {
        return;
    }
    vis[x] = 1;
    for(auto y:edge_r[x])
    {
        dfs_r(y);
    }
    finish_order.push(x);
}

void get_order()
{
    for(int i = 1;i<=n;++i)
    {
        if(vis[i])continue;
        dfs_r(i);
    }
}

long long dfs(int x)
{
    vis[x] = 1;
    long long num = 1;
    for(auto i:edge[x])
    {
        if(vis[i])continue;
        num += dfs(i);
    }
    return num;
}

unsigned long long SCC()
{
    unsigned long long ans = 0;
    while(finish_order.size())
    {
        int x = finish_order.top();
        finish_order.pop();
        if(vis[x])continue;
        long long res = dfs(x);
        ans += res*(res-1)/2;
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    int x,y;
    for(int i =0;i<m;++i)
    {
        cin>>x>>y;
        edge[x].push_back(y);
        edge_r[y].push_back(x);
    }

    memset(vis,0,sizeof vis);

    get_order();

    memset(vis,0,sizeof vis);

    cout<<SCC();



    return 0;
}