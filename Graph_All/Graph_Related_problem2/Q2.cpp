#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int vertex, edges;
struct Node
{
    int data;
    Node* next;
    Node(int data){
        this->data=data;
        this->next=nullptr;
    }
};

Node *head[100]={nullptr};

void addEdges(int u,int v){
    Node* newNode =new Node(v);
    if(head[u]==nullptr){
        head[u]=newNode;
        return;
    }
    Node* tem=head[u];
    while (tem->next!=nullptr)
    {
        tem=tem->next;
    }
    tem->next=newNode;

    
}


int MostPopularParticipent(){
    int popularity[vertex]={0};
    for(int i=0;i<vertex;i++){
        Node* temp=head[i];
        while (temp!=nullptr)
        {   popularity[i]++;
            temp=temp->next;
        }
        
    }
    
   int Mostpopular=0;
   int Maxtpopularity=popularity[0];
   for(int i=0;i<vertex;i++){
     if(Maxtpopularity<popularity[i]){
         Maxtpopularity=popularity[i];
         Mostpopular=i;
     }
       
   }
   return Mostpopular;
   
}



int main() {

    cout << "Enter total number of vertex and edges:";
    cin >> vertex >> edges;

    for (int i = 0; i < edges; i++)
    {
        cout << "Enter edges from u to v:";
        int u, v;
        cin >> u >> v;
        addEdges(u,v);
        addEdges(v,u);
        
    }

    cout<<"Most popular participent:"<<MostPopularParticipent()<<endl;

    return 0;
}
