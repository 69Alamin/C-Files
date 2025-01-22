#include <iostream>

using namespace std;

struct Node
{
    char vertex;
    Node *next;

    Node(char vertex)
    {
        this->vertex = vertex;
        this->next = nullptr;
    }
};
Node *head[100] = {nullptr};

void addEdges(char source, char destination)
{  Node* newNode1=new Node(destination);

   for(int i=0;i<100;i++){
    if(head[i] != nullptr&&head[i]->vertex==source){
        Node* tr=head[i];
        while (tr->next!=nullptr)
        {
            tr=tr->next;
        }
        tr->next=newNode1;
    break;
    }

   }


   //for undirected graph
   Node* newNode2=new Node(source);
   for(int i=0;i<100;i++){
    if(head[i] != nullptr&&head[i]->vertex==destination){
        Node* tr=head[i];
        while (tr->next!=nullptr)
        {
            tr=tr->next;
        }
        tr->next=newNode2;
    break;
    }

   }

   
}

void Display(int vertices)
{
    cout << "Adjacency List: " << endl;
    for (int i = 0; i < vertices; i++)
    {   cout << head[i]->vertex << " :";

        Node *traversal = head[i]->next;  //head[i] already printed so i start form head next
        
        while (traversal != nullptr)
        {
            cout << traversal->vertex << "->";
            traversal = traversal->next;
        }
        cout << "NULL" << endl;
    }
}

int main()
{
    int vertices, edges;
    cout << "Enter the number of vertices and edges :";
    cin >> vertices >> edges;
    cout << endl
         << "Enter the vertices Name :";
    for (int i = 0; i < vertices; i++)
    {
        char v_Name;
        cin >> v_Name;
        head[i] = new Node(v_Name);
    }
    cout << endl
         << "Enter The Connectection Between Source and Destination :" << endl;
    for (int i = 0; i < edges; i++)
    {
        char source, destination;
        cout << "Source <-> Destination :";
        cin >> source >> destination;
        addEdges(source, destination);
    }
    Display(vertices);

    return 0;
}