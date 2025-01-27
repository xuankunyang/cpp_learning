#include <bits/stdc++.h>

using namespace std;

int n, m;


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


int edmondsKarp(int n, vector<vector<int>>& capacity, int s, int t) 
{
    vector<vector<int>> residual = capacity; 

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
        

        for (int v = t; v != s; v = parent[v]) {
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

    cin >> n >> m;

    vector<vector<int>> capacity(n, vector<int>(n, 0));

    for (int i = 0; i < m; ++i) 
    {
        int u, v, c;
        cin >> u >> v >> c;
        --u; --v;  // 0-based index

        if (u != v) 
        { 
            capacity[u][v] += c; // 可能有重边
        }
    }

    int s = 0;
    int t = n - 1;

    int max_flow = edmondsKarp(n, capacity, s, t);
    
    cout << max_flow << endl;
    
    return 0;
}
