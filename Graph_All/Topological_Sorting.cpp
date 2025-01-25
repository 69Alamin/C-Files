#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void topological_Sort(int Graph[][5], int vertices)
{
    vector<int> topo;
    int inDEgree[vertices] = {0};
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            if (Graph[i][j] == 1)
                inDEgree[j]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < vertices; i++)
    {
        if (inDEgree[i] == 0)
            q.push(i);
    }

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        topo.push_back(node);

        for (int i = 0; i < vertices; i++)
        {
            if (Graph[node][i] == 1)
            {
                inDEgree[i]--;
                if (inDEgree[i] == 0)
                {
                    q.push(i);
                }
            }
        }
    }

    if (topo.size() == vertices)
    {
        for (int n : topo)
            cout << n << " ";
    }
    else
        cout << "Graph is not a DAG" << endl;
}

int main()
{

    int Nummber_of_Vertex = 4; // 0 1 2 3 4
    int Graph[5][5] = {
        {0, 1, 1, 1},
        {0, 0, 0, 1},
        {0, 0, 0, 1},
        {0, 0, 0, 0},

    };

    topological_Sort(Graph, Nummber_of_Vertex);

    return 0;
}