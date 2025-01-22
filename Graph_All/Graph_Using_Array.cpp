#include <iostream>
#include<bits/stdc++.h>
#define n 100

using namespace std;
int vertices, edges;
int adjacencyMatrix[n][n]={0};

void addEdges(int source ,int destination){  
   adjacencyMatrix[source][destination]=1;   
   adjacencyMatrix[destination][source]=1; //for undirected Graph
}


void Display(){
    for(int i=0;i<vertices;i++){
        cout<<i<<" :";
        for(int j=0;j<vertices;j++){
            cout<<adjacencyMatrix[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main() {
    cout<<"Enter the Nunber of Nodes and Edges :";
    cin>>vertices>>edges;
    cout<<"Enter the connections :"<<endl;
    int source,destination;
    for(int i=0;i<edges;i++){
       cout<<"Source and Destination :";
       cin>>source>>destination;
       addEdges(source,destination);

    }
     Display();
  
    return 0;
}