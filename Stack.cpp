#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
Node *top = nullptr;

void push(int data)
{
    Node *newNode = new Node(data);
    if (top == nullptr)
    {
        top = newNode;
    }
    else
    {
        newNode->next = top;
        top = newNode;
    }
}

int pop()
{
    if (top == nullptr)
        cout << "Stack is Empty" << endl;
    else
    {
        Node *temp = top;
        int data = top->data;
        top = top->next;

        delete (temp);
        return data;
    }
    return -1;
}
void pushAtBottom(int data)
{
    if (top == nullptr)
    {
        push(data);
        return;
    }

    int store = pop();
    pushAtBottom(data);
    push(store);
}
void reverse()
{
    if (top == nullptr)
        return;

    int p = pop();
    reverse();
    pushAtBottom(p);
}

void AssendingSort(){
     Node *out=top;
     while(out!=nullptr){
          Node* in=out->next;
          while(in!=nullptr){
              if(in->data<out->data){
                int temp=out->data;
                out->data=in->data;
                in->data=temp;

              }
              in=in->next;
          }
        out=out->next;
     }

}

void Display()
{
    if (top == nullptr)
        cout << "Stack is Empty" << endl;
    else
    {
        int c = 0;
        Node *tr = top;
        while (tr != NULL)
        {
            if (c == 0)
                cout << tr->data << "  Top" << endl;
            else
                cout << tr->data << endl;
            c = 1;
            tr = tr->next;
        }
    }
}

int main()
{
    pop();
    push(1);
    push(10);
    push(7);
    push(5);
    push(9);
    // Display();
    //pop();
    //pop();
    Display();
     
    
    //cout<<"Reverse :"<<endl;
    //reverse();
    //Display();

    AssendingSort();
    Display();

    return 0;
}