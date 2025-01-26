#include<bits/stdc++.h>
#define inf INT_MAX

using namespace std;

int n, m;
vector<int> adjlist[100];
int dist[100];
int parent[100];
string color[100];

void initialize() {
    for (int i = 0; i < n; i++) {
        dist[i] = inf;
        color[i] = "white";
        parent[i] = -1;
    }
}

void bfs(int source) {
    initialize();
    dist[source] = 0;
    color[source] = "gray";
    queue<int> q;
    q.push(source);
    while (not q.empty()) {
        int u = q.front();
        q.pop();
        color[u] = "black";
        for (int v: adjlist[u]) {
            if (color[v] == "white") {
                dist[v] = dist[u] + 1;
                parent[v] = u;
                color[v] = "gray";
                q.push(v);
            }
        }
    }
}

int main() {
    cin >> n >> m;
    bool adj[n][n];
    memset(adj, false, sizeof(adj));


    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adjlist[u].push_back(v);
    }

    bfs(0);
    for (int i = 0; i < n; i++) {
        cout << "Distance of " << i << " from source is: " << dist[i] << endl;
    }
}
