#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> adj[100];
bool vis[100];
stack<int> topologicalOrder;

void topSort(int u)
{
    vis[u] = true;
    for (int v: adj[u])
        if (not vis[v])
            topSort(v);
    topologicalOrder.push(u);
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);

    }

    for (int i = 0; i < n; i++)
    {
        if (not vis[i])
        {
            topSort(i);

        }
    }



    cout << "Topological sort: ";
    while (not topologicalOrder.empty())
    {
        cout << topologicalOrder.top() << " ";
        topologicalOrder.pop();
    }

}
