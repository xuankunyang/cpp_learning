#include <bits/stdc++.h>

using namespace std;

bool vis[105];
int n;
string s[105];
queue<int> q;



int bfs()
{
    q.push(1);
    vis[1] = 1;
    cin>>s[1];

    while(q.size())
    {
        int x = q.front();
        q.pop();
        if(x != 1)
        {
            cout<<x<<endl;
            fflush(stdout);
            cin>>s[x];
        }
        
        if(x == n)return 1;

        if(s[x] == "FAIL")return -1;

        for(int i =1;i<= n;++i)
        {
            if(s[x][i-1] == '1')
            {
                if(vis[i])continue;
                q.push(i);
                vis[i] = 1;
            }
        }
    }
    return 0;
}

int main()
{
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

    cin>>n;

    int res = bfs();

    if(res == 1)
    {
        cout<<"yes";
        fflush(stdout);
    }
    else if(res == 0)
    {
        cout<<"no";
        fflush(stdout);
    }

    
    return 0;
}