#include <bits/stdc++.h>

using namespace std;

int dist[200005],fa[200005],t;
int n,minn;

int find(int x)
{
    if(x != fa[x])
    {
    int last = fa[x];
    fa[x] = find(fa[x]);
    dist[x] += dist[last];
    }
    return fa[x];

}

void check(int i,int j)
{
    int x = find(i),y = find(j);
    if(x != y)
    {
        fa[x] = y;
        dist[i] = dist[j] + 1;
    }
    else
    {                       
        minn = min(minn,dist[i]+dist[j]+1);                                                                                                   
    }    
}

int main()
{
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    minn = 0x7777777;
    cin>>n;
    for(int i = 1;i<=n;++i)
    {
        fa[i] = i;
    }
   
    for(int i = 1;i<=n;++i)
    {
        cin>>t;
        check(i,t);
    }
    cout<<minn;

    return 0;
}