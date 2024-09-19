#include <bits/stdc++.h>

using namespace std;

struct node
{
    int x,y,time;
};

char maps[105][105];
int dp[105][105][20];
int n,m,t;
int stx,sty,edx,edy;
queue<node>q;
int nx[] = {1,-1,0,0};
int ny[] = {0,0,1,-1};

void solve()
{
    while(q.size())
    {
        auto head = q.front();
        q.pop();
        for(int i = 0;i<4;++i)
        {
            node nxt;
            nxt.x = head.x + nx[i];
            nxt.y = head.y + ny[i];
            nxt.time = head.time+1;
            if(nxt.x<0||nxt.y<0||nxt.x>=n||nxt.y>=m||nxt.time>t)continue;
            if(maps[nxt.x][nxt.y] == '*')continue;
            if(dp[nxt.x][nxt.y][nxt.time])
            {
                dp[nxt.x][nxt.y][nxt.time] += dp[head.x][head.y][head.time];
                continue;
            }
            dp[nxt.x][nxt.y][nxt.time] += dp[head.x][head.y][head.time];
            q.push(nxt);
        }
        
    }
}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    cin>>n>>m>>t;
    for(int i = 0;i<n;++i)
    {
        cin>>maps[i];
    }
    cin>>stx>>sty>>edx>>edy;
    stx--,sty--,edx--,edy--;
    node st;
    st.x = stx;
    st.y = sty;
    st.time = 0;
    dp[stx][sty][0] = 1;
    q.push(st);
    solve();
    cout<<dp[edx][edy][t];





    return 0;
}