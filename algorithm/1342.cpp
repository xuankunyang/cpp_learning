#include <bits/stdc++.h>

using namespace std;

int n,m,s,t;
list<pair<int,int>> v[2505];
bool vis[2505];

struct node
{
    int index;
    long long dist = 7e15;  
    bool operator< (const node& a) const
    {
        return dist > a.dist;
    }
};
node nodes[2505];

priority_queue<node> p;

void Dijkstra()
{
    memset(vis,0,sizeof vis);
    for(int i = 1;i<=n;++i)
    {
        nodes[i].index = i;
    }
    nodes[s].dist = 0;
    p.push(nodes[s]);
    while(!p.empty())
    {
        node h = p.top();
        p.pop();
        if(vis[h.index])continue;
        vis[h.index] = 1;
        if(vis[t])return;
        for(auto iter = v[h.index].begin();iter != v[h.index].end();++iter)
        {
            int u = (*iter).first;
            int w = (*iter).second;
            nodes[u].dist = min(nodes[u].dist,nodes[h.index].dist + w);
            p.push(nodes[u]);
        }
    }
    
}

int main()
{
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n>>m>>s>>t;
    
    int x,y,w;
    for(int i = 0;i<m;++i)
    {
        cin>>x>>y>>w;
        v[x].push_back(make_pair(y,w));
        v[y].push_back(make_pair(x,w));
        //cao,之前写的都是有向边...
    }

    Dijkstra();
    cout<<nodes[t].dist;


    return 0;
}