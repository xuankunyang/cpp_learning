#include <bits/stdc++.h>

using namespace std;

vector<int> edge[2000005],edge_[2000005];
int id[2000005],vis[2000005];
int n,m;
vector<int>finish_time;
int ans[1000005];

void dfs_(int x)
{
    if(vis[x])return ;
    vis[x] = 1;
    for(auto i:edge_[x])
    {
        dfs_(i);
    }
    finish_time.push_back(x);
}

void dfs(int x,int scc)
{
    if(id[x])return;
    id[x] = scc;
    for(auto i:edge[x])
    {
        dfs(i, scc);
    }
}



int main()
{
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    int i,j,a,b;
    for(int t = 0;t<m;++t)
    {
        cin>>i>>a>>j>>b;
        if((!a)&&(!b))
        {
            edge[i*2-1].push_back(j*2);
            edge_[j*2].push_back(i*2-1);
            edge[j*2-1].push_back(i*2);
            edge_[i*2].push_back(j*2-1);
        }
        else if((!a)&&b)
        {
            edge[i*2-1].push_back(2*j-1);
            edge_[2*j-1].push_back(i*2-1);
            edge[2*j].push_back(2*i);
            edge_[2*i].push_back(2*j);
        }
        else if((!b)&&a)
        {
            edge[2*j-1].push_back(2*i-1);
            edge_[2*i-1].push_back(2*j-1);
            edge[2*i].push_back(2*j);
            edge_[2*j].push_back(2*i);
        }
        else
        {
            edge[2*i].push_back(2*j-1);
            edge_[2*j-1].push_back(2*i);
            edge[2*j].push_back(2*i-1);
            edge_[2*i-1].push_back(2*j);
        }
        
    }
    for(int i =1;i<=2*n;++i)
    {
        if(vis[i])continue;
        dfs_(i);
    }

    reverse(finish_time.begin(),finish_time.end());

    int count = 0;
    for(auto i:finish_time)
    {
        if(id[i])continue;
        dfs(i,++count);
    }
    
    for(int i =1;i<=n;++i)
    {
        if(id[2*i-1] == id[2*i])
        {
            cout<<"No"<<endl;
            return 0;
        }
        ans[i] = id[2*i] > id[2*i-1];
    }
    
    memset(vis,0,sizeof vis);
    cout<<"Yes"<<endl;

    for(int i = 1;i<=n;++i)
    {
        cout<<ans[i]<<" ";
    }

    return 0;
}