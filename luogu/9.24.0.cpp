#include <bits/stdc++.h>

using namespace std;

int stop[1005],indegree[1005],outing[1005];
bool st[1005],maps[1005][1005],outed[1005];
int n,m,top,ans;


int main()
{
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

    cin>>n>>m;
    for(int i =1;i<=m;++i)
    {
        memset(st,0,sizeof st);
        int num;
        cin>>num;
        for(int j =1;j<=num;++j)
        {
            cin>>stop[j];
            st[stop[j]] = 1;
        }
        for(int j = stop[1];j<=stop[num];++j)
        {
            if(!st[j])
            {
                for(int k = 1;k<=num;++k)
                {
                    if(!maps[j][stop[k]])
                    {
                        maps[j][stop[k]] = 1;
                        indegree[stop[k]]++;
                    }
                }
            }
        }
    }
    do
    {
        top = 0;
        for(int i = 1;i<=n;++i)
        {
            if(!indegree[i]&&!outed[i])
            {
                outing[++top] = i;
                outed[i] = 1;
            }
        }
        for(int i = 1;i<=top;++i)
        {
            for(int j = 1;j<=n;++j)
            {
                if(maps[outing[i]][j])
                {
                    indegree[j]--;
                    maps[outing[i]][j] = 0;
                }
            }

        }
        ans++;

    }while(top);
    cout<<ans-1;

    return 0;
}