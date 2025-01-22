#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<vector<char>> adj;

void BFS(vector<vector<char>> &adj, char start){
    queue<char> que;
    que.push(start);
    vector<bool> visited(adj.size(), false);
    while (!que.empty())
    {
        char node =que.front();
        que.pop();
        if(!visited[node-'A']){

            for(int i=0;i<adj[node].size();i++){
                que.push(adj[node][i]);
            }
        }
    }
    
    for(int i=0;i<visited.size();i++){
        if(visited[i]){
            cout<<char('A'+i)<<" ";
        }
    }


}

int main() {
    int n, m;
    cin >> n >> m;
    adj.resize(n);
    for (int i=0;i<m;i++){
        cout<<"Enter the edges: ";
        char u, v;
        cin >> u >> v;
        adj[u - 'A'].push_back(v);
        adj[v - 'A'].push_back(u); 
    }

    for (int i=0;i<n;i++){
        cout<<"Node "<< char('A' + i) <<" is connected to: ";
        for (int j=0;j<adj[i].size();j++){
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
    BFS(adj, 'A');
    return 0;
}
