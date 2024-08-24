#include <bits/stdc++.h>

using namespace std;
#define inf 0x3f3f3f3f

template <typename Tp>
void read(Tp &x)
{
    char c = getchar();
    x = 0;
    int f = 1;
    while(c<'0'||c>'9')
    {
        if(c == '-')f = -1;
        c = getchar();
    }
    while(c>='0'&&c<='9')
    {
        x = x*10+c-'0';
        c = getchar();
    }
    x*=f;
}
struct node
{
    int x,y,c,w;
    bool operator < (node b)const
    {
        return w>b.w;
    }
};

priority_queue<node>q43;
int dx43[] = {0,1,0,-1,1,1,-1,-1,0,2,0,-2};
int dy43[] = {1,0,-1,0,1,-1,1,-1,2,0,-2,0};
int dw43[] = {0,0,0,0,2,2,2,2,2,2,2,2};
int a43[105][105],dis43[105][105];

int n43,m43;

void bfs43()
{
    memset(dis43,0x3f,sizeof dis43);
    dis43[1][1] = 0;
    q43.push((node){1,1,a43[1][1],dis43[1][1]});
    node cur,nxt;
    while(!q43.empty())
    {
        cur = q43.top();
        q43.pop();
        if(dis43[cur.x][cur.y]<cur.w)continue;//非最优路径
        for(int i=0;i<12;++i)
        {
            nxt.x = cur.x+dx43[i];
            nxt.y = cur.y+dy43[i];
            nxt.w = cur.w+dw43[i];
            if(nxt.x<=0||nxt.y>m43||nxt.x>m43||nxt.y<=0)continue;
            nxt.c = a43[nxt.x][nxt.y];
            if(!nxt.c)continue;
            if(cur.c!=nxt.c)nxt.w++;
            if(dis43[nxt.x][nxt.y]>nxt.w)
            {
                dis43[nxt.x][nxt.y] = nxt.w;
                q43.push(nxt);
            }
        }
    }
}

int main()
{
    int x,y,c;
    read(m43);
    read(n43);
    for(int i=1;i<=n43;++i)
    {
        read(x);
        read(y);
        read(c);
        a43[x][y] = c+1;
    }
    bfs43();
    
    if(!a43[m43][m43])
    {
        int ans = min(dis43[m43-1][m43],dis43[m43][m43-1])+2;
        if(ans>=inf)puts("-1");
        else cout<<ans;
    }
    else 
    {
        if(dis43[m43][m43] == inf)puts("-1");
        else cout<<dis43[m43][m43];
    }


    return 0;
}
