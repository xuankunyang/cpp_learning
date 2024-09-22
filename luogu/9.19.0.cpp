#include <bits/stdc++.h>

using namespace std;

int t,n;
char maps[5005][5005];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
bool vis[5005][5005] = {0};

bool dfs(int x,int y)
{
    if(maps[x][y]=='C')return 1;
    if(x!=0||y!=0)
    {
        vis[x][y] = 1;
    }
    for(int i =0;i<4;++i)
    {
        int nx = x + dx[i],ny = y + dy[i];
        if(nx<0||ny<0||nx>=n||ny>=n||vis[nx][ny]||maps[nx][ny]=='X')continue;
        if(nx==0&&ny==0)continue;
        if(dfs(nx,ny))return 1;
    }
    vis[x][y] = 0;
    return 0;
}

void solve()
{
    memset(vis,0,sizeof vis);
    bool res1 = dfs(0,0);
    if(!res1)
    {
        cout<<0<<endl;
        return;
    }
    bool res2 = dfs(0,0);
    if(res1&&!res2)
    {
        cout<<1<<endl;
    }
    else 
    {
        cout<<2<<endl;
    }


}

int main()
{
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>t;
    for(int i =0;i<t;++i)
    {
        cin>>n;
        for(int j = 0;j<n;++j)
        {
            cin>>maps[j];
        }
        solve();
    }


    return 0;
}