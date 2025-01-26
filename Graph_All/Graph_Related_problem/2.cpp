#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> adj[100];
bool vis[100];

bool checkCycle(int u)
{
    vis[u] = true;
    for (int v: adj[u])
    {
        if (vis[v])
            return true;
        return checkCycle(v);
    }
    return false;
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

    int c=checkCycle(0);
    if(c==1)
        cout<<"True";
    else
        cout<<"False";

    return 0;
}
