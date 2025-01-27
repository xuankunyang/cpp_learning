#include <bits/stdc++.h>

using namespace std;

int n;


bool bfs(const vector<vector<int>>& capacity, vector<vector<int>>& residual, int s, int t, vector<int>& parent) 
{
    int n = capacity.size();
    vector<bool> visited(n, 0);
    queue<int> q;
    q.push(s);
    visited[s] = true;
    
    while (!q.empty()) 
    {
        auto u = q.front();
        q.pop();
        
        for (int v = 0; v < n; ++v) 
        {
            if (!visited[v] && residual[u][v] > 0)
            {
                q.push(v);
                visited[v] = true;
                parent[v] = u;
                if (v == t) 
                {
                    return true;
                }
            }
        }
    }
    return false;
}


int edmondsKarp(int n, vector<vector<int>>& capacity, vector<vector<int>>& residual, int s, int t, vector<vector<int>>& matrix) 
{
    
    
    vector<int> parent(n);

    int max_flow = 0;
    
    while (bfs(capacity, residual, s, t, parent)) 
    {
        int min_flow = 1e9;

        for (int v = t; v != s; v = parent[v]) 
        {
            int u = parent[v];

            min_flow = min(min_flow, residual[u][v]);
        }
        

        for (int v = t; v != s; v = parent[v]) 
        {
            int u = parent[v];

            residual[u][v] -= min_flow;
            residual[v][u] += min_flow;  // 反向边的流量
        }
        
        max_flow += min_flow;
    }
    
    return max_flow;
}

int main() 
{
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

    cin >> n;

    vector<vector<int>> capacity(2*n + 2, vector<int>(2*n + 2, 0));

    for (int i = 0; i < n * n; ++i)
    {
        int u = 1 + i / n, v = n + 1 + i % n, c;
        cin >> c;
        capacity[u][v] = c;
        capacity[0][u] = 1;
        capacity[v][2*n + 1] = 1;

    }

    vector<vector<int>> residual = capacity;

    int s = 0;
    int t = 2*n + 1;

        
    vector<vector<int>> matrix(n + 1, vector<int>(n + 1, 0));

    int max_flow = edmondsKarp(2*n + 2, capacity,residual, s, t, matrix);


    if (max_flow == n)
    {
        cout<<"Yes"<<endl;

        for(int i = 1; i <= n; ++i)
        {
            for(int j = 1; j <= n; ++j)
            {
                if(capacity[i][j + n] == 1 && residual[i][j + n] == 0)
                {
                    matrix[i][j] = 1;
                }
            }
        }
        for(int i = 1; i <= n; ++i)
        {
            for(int j = 1; j <= n; ++j)
            {
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    else
    {
        cout<<"No"<<endl;
    }
    
    return 0;
}
