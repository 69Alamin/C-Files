#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adjlist[100];
vector<bool> visited(100, false);

int dfs(int node)
{
    visited[node] = true;
    int count = 1;

    for (int neighbor : adjlist[node])
    {
        if (!visited[neighbor])
        {
            count += dfs(neighbor);
        }
    }
    return count;
}

int main()
{
    cin >> n >> m;


    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }

    int totalNodes = 0;


    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            int componentSize = dfs(i);
            totalNodes += componentSize;
        }
    }

    cout << "Total number of nodes in the graph: " << totalNodes << endl;

    return 0;
}
