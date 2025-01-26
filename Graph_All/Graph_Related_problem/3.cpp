#include <bits/stdc++.h>
#define inf INT_MAX

using namespace std;

int n, m;
vector<int> adjlist[100];

bool isbipartite()
{
    vector<int> color(n, -1);

    for (int i = 0; i < n; i++)
    {
        if (color[i] == -1)
        {
            queue<int> q;
            q.push(i);
            color[i] = 0;

            while (!q.empty())
            {
                int u = q.front();
                q.pop();

                for (int neighbor : adjlist[u])
                {
                    if (color[neighbor] == -1)
                    {

                        color[neighbor] = 1 - color[u];
                        q.push(neighbor);
                    }
                    else if (color[neighbor] == color[u])
                    {

                        return false;
                    }
                }
            }
        }
    }
    return true;
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

    if (isbipartite())
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }

    return 0;
}
