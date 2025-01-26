#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int vertex, edges;
int adjmatrix[100][100] = {0};
int visited[100];

void initialize()
{
    for (int i = 0; i < 100; i++)
        visited[i] = 0;
}
void dfs(int start)
{
    visited[start] = 1;
    for (int i = 0; i < vertex; i++)
    {
        if (adjmatrix[start][i] == 1 && !visited[i])
            dfs(i);
    }
}

int findleader()
{
    for (int i = 0; i < vertex; i++)
    {
        initialize();

        dfs(i);

        bool allvisited=true;
        for (int j = 0; j < vertex; j++)
        {
            if (visited[j] == 0)
                allvisited=false;
        }

        if(allvisited)
          return i;
    }

    return -1;
}

int main()
{
    cout << "Enter total number of vertex and edges:";
    cin >> vertex >> edges;

    for (int i = 0; i < edges; i++)
    {
        cout << "Enter edges from u to v:";
        int u, v;
        cin >> u >> v;
        adjmatrix[u][v] = 1;
    }

    int l = findleader() ;

    if (l != -1)
    {
        cout << "the leader is " << l;
    }
    else cout << "theres no leader";

    return 0;
}