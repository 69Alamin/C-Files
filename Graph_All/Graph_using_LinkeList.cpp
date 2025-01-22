#include <iostream>
using namespace std;
#define n 100

int vertices, edges;

struct Node
{
    int data;
    Node* next;

    Node(int data){
        this->data=data;
        this->next=nullptr;
    }
};
Node* head[n];
void addEdges(int source,int destination){
    Node* newNodee=new Node(destination);
    newNodee->next= head[source];
    head[source]=newNodee;
    
    //for undirected graph
    Node* newNode=new Node(source);
    newNode->next= head[destination];
    head[destination]=newNode;
}

void Display(){
    cout<<"Adjacency List: "<<endl;
    for(int i=0;i<vertices;i++){
        Node *traversal=head[i];
        cout<<i<<" :";
        while(traversal!=nullptr){
            cout<<traversal->data<<"->";
            traversal=traversal->next;
        }
        cout<<"NULL"<<endl;
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