#include <bits/stdc++.h>

using namespace std;

int n,m;
list<pair<int,int>> v[2505];
long long dist[2505];
int pre[2505];

void Bellman_Ford()
{
    int last = 0;
    for(int t = 1;t<=n+1;++t)
    {
        last = -1;
        for(int i = 0;i<=n;++i)
        {
            for(auto j:v[i])
            {
                if(dist[j.first] > dist[i] + j.second)
                {
                    dist[j.first] = dist[i] + j.second;
                    pre[j.first] = i;
                    last = j.first;
                }
            }
        }
    }
    if(last != -1)
    {
        for(int i = 0;i<=n;++i)
        {
            last = pre[last];
        }
        unordered_set<int>ans;
        while(true)
        {
            if(ans.count(last))break;
            ans.insert(last);
            last = pre[last];
        }
        cout<<"Yes"<<endl;
        cout<<ans.size()<<endl;
        for(auto i: ans)
        {
            cout<<i<<" ";
        }
        
        return;
    }

    cout<<"No"<<endl;

}

int main()
{
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

    cin>>n>>m;
    int x,y,w;
    for(int i = 1;i<=n;++i)
    {
        v[0].push_back(make_pair(i,0));
    }
    for(int i = 0;i<m;++i)
    {
        cin>>x>>y>>w;
        v[x].push_back(make_pair(y,w));
    }

    fill(dist, dist + n + 1, 1e17);

    Bellman_Ford();

    



    return 0;
}