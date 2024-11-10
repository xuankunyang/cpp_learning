#include <bits/stdc++.h>

using namespace std;

list<pair<int,int>> a[3005];
int n,m;
int h[3005];
bool vis[3005];

struct node
{
    long long dist;
    int index;
    bool operator<(const node& a) const 
    { 
        return dist > a.dist; 
    }
};

long long inf = 1e9;
node nodes[3005];
priority_queue<node> p;

bool Bellman_Ford(int s)
{
    memset(h,1e9,sizeof h);
    h[s] = 0;
    int round = 0;
    bool flag = 1;
    while(flag&&round<n+1)
    {
        flag = 0;
        for(int i = 0;i<=n;++i)
        {
            for(auto iter = a[i].begin();iter!=a[i].end();++iter)
            {
                if(h[(*iter).first] > h[i] + (*iter).second)
                {
                    h[(*iter).first] = h[i] + (*iter).second;
                    flag = 1;
                }
            }
        }
        round++;
    }
    if(round == n+1)return 0;
    return 1;
}

void Dijkstra(int s)
{
    while(p.size())
    {
        node v = p.top();
        p.pop();
        if(vis[v.index])continue;
        vis[v.index] = 1;
        for(auto iter = a[v.index].begin();iter!=a[v.index].end();++iter)
        {
            int u = (*iter).first,w = (*iter).second;
            nodes[u].dist = min(nodes[u].dist,nodes[v.index].dist+w+h[v.index]-h[u]);
            p.push(nodes[u]);
        }
    }
}


int main()
{
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i = 1;i<=n;++i)
    {
        a[0].push_back(make_pair(i,0));
    }
    int x,y,w;
    for(int i = 0;i<m;++i)
    {
        cin>>x>>y>>w;
        a[x].push_back(make_pair(y,w));
    }
    if(!Bellman_Ford(0))
    {
        cout<<-1;
        return 0;
    }
    for(int j = 1;j<=n;++j)
    {
        nodes[j].dist = 1e9;
        nodes[j].index = j;
    }
    for(int i=1;i<=n;++i)
    {
        memset(vis ,0,sizeof vis);
        for(int  j= 1;j<=n;++j)
        {
            nodes[j].dist = 1e9;
            nodes[j].index = j;
        }
        nodes[i].dist = 0;
        p.push(nodes[i]);
        Dijkstra(i);
        long long res = 0;
        for(int j=1;j<=n;j++)
        {
	        if(nodes[j].dist == inf)
		        res += 1ll*inf*j;
	        else
		        res += (nodes[j].dist+h[j]-h[i])*j;
        }
        cout<<res<<endl;
        
    }

    



    return 0;
}