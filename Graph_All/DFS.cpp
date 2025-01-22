#include <iostream>
#include <bits/stdc++.h>

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
{
    Node *newNode1 = new Node(destination);

    for (int i = 0; i < 100; i++)
    {
        if (head[i] != nullptr && head[i]->vertex == source)
        {
            Node *tr = head[i];
            while (tr->next != nullptr)
            {
                tr = tr->next;
            }
            tr->next = newNode1;
            break;
        }
    }

    // for undirected graph
    Node *newNode2 = new Node(source);
    for (int i = 0; i < 100; i++)
    {
        if (head[i] != nullptr && head[i]->vertex == destination)
        {
            Node *tr = head[i];
            while (tr->next != nullptr)
            {
                tr = tr->next;
            }
            tr->next = newNode2;
            break;
        }
    }
}

bool isVisited(char vertex, int NumberOfVertex, char Visited[])
{
    for (int i = 0; i < NumberOfVertex; i++)
    {
        if (Visited[i] != '\0' && Visited[i] == vertex)
        {
            return true;
        }
    }
    return false;
}

void DFS(Node *source, int NumberOfVertex)
{
    stack<char> Stack;
    Stack.push(source->vertex);
    char Visited[NumberOfVertex];
    memset(Visited, '\0', sizeof(Visited));

    int Vindex = 0;
    while (!Stack.empty())
    {
        char vertex = Stack.top();
        Stack.pop();
        if (!isVisited(vertex, NumberOfVertex, Visited))
        {
            Visited[Vindex++] = vertex;
            for (int i = 0; i < NumberOfVertex; i++)
            {
                if (head[i] && head[i]->vertex == vertex)
                {
                    Node *tr = head[i]->next;
                    while (tr != nullptr)
                    {
                        Stack.push(tr->vertex);
                        tr = tr->next;
                    }
                    break;
                }
            }
        }
    }

    for (int i = 0; i < Vindex; i++)
    {
        cout << Visited[i] << " ";
    }
}

void Display(int NumberOfVertex)
{
    cout << "Adjacency List: " << endl;
    for (int i = 0; i < NumberOfVertex; i++)
    {
        cout << head[i]->vertex << " :";

        Node *traversal = head[i]->next; // head[i] already printed so i start form head next

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
    int NumberOfVertex, edges;
    cout << "Enter the number of NumberOfVertex and edges :";
    cin >> NumberOfVertex >> edges;
    cout << endl
         << "Enter the Vertices Name :";
    for (int i = 0; i < NumberOfVertex; i++)
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
    Display(NumberOfVertex);
    DFS(head[0], NumberOfVertex);

    return 0;
}