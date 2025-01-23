#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
} *front = NULL, *rear = NULL;

void enqueue(int data)
{
    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;
    if (rear == NULL)
    {
        front = newNode;
        rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
}

void dequeue()
{
    if (front == NULL)
    {
        cout << "Queue Underflow" << endl;
    }
    else
    {
        Node *temp = front;
        front = front->next;
        delete (temp);
        if (front == NULL)
        {
            rear = NULL;
        }
    }
}

int Front_Element()
{
    if (front != NULL)
        return front->data;

    else
        return -1;
}
bool queueIsEmpty()
{
    return front == NULL;
}

void BFS(int graph[][5], int start, int Nummber_of_Vertex)
{
    enqueue(start);

    bool Check_Visit[Nummber_of_Vertex] = {false};
    Check_Visit[start] = true;
    cout << "BFS Traversal: ";
    while (!queueIsEmpty())
    {
        int current = Front_Element();
        dequeue();
        cout << current << " ";

        for (int i = 0; i < Nummber_of_Vertex; i++)
        {
            if (graph[current][i] == 1 && !Check_Visit[i])
            {
                enqueue(i);
                Check_Visit[i] = true;
            }
        }
    }
}

int main()
{
    int Nummber_of_Vertex = 5; // 0 1 2 3 4
    int Grpah[5][5] = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 1, 0},
        {1, 1, 0, 0, 0},
        {0, 1, 1, 0, 1},
        {0, 0, 1, 1, 0},

    };
    BFS(Grpah, 0, 5);

    return 0;
}