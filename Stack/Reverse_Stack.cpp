#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};
Node *top = nullptr;

void push(int data)
{
    Node *newNode = new Node(data);
    newNode->next = top;
    top = newNode;
}

bool isEmpty()
{
    if (top == nullptr)
        return true;

    return false;
}

int pop()
{
    if (isEmpty())
        return -1;
    else
    {   int data=top->data;
        Node *temp = top;
        top = top->next;
        delete(temp);
        return data;
    }
}
void Display()
{
    if (isEmpty())
        cout << "Stack is Empty";
    else
    {
        Node *tem = top;
        while (tem != nullptr)
        {
            cout << tem->data << endl;
            tem = tem->next;
        }
    }
}

void pushAtbuttom(int data){
     if(top==nullptr){
        push(data);
        return;
     }
     int store=pop();
     pushAtbuttom(data);
     push(store);
}

void reverse(){
    if(top==nullptr)
       return;
      int data=pop();
      reverse();
      pushAtbuttom(data);
      
}

int main()
{
    push(5);
    push(6);
    push(7);
    push(8);
    push(9);
    Display();
    reverse();
    cout<<"After reverse :"<<endl;
    Display();

    return 0;
}