#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;

    Node(int data){
        this->data=data;
        this->next=nullptr;
    }
};

struct Stack
{
    Node* top=nullptr;

void push(int data){
    Node* newNode=new Node(data);
    newNode->next=top;
    top=newNode;
}

bool isEmpty(){
    if(top==nullptr)
        return true;

   return false;
}

void pop(){
    if(isEmpty())
      cout<<"Stack Underflow";
      else{
        Node* temp=top;
        top=top->next;
        delete(temp);
      }
}

int Peek(){
    if(isEmpty())
       return -1;
      else{
        return top->data;
      }
}
};





Stack stack1,stack2;

void enqueu(int data){
    while (!stack1.isEmpty())
    {
        stack2.push(stack1.Peek());
        stack1.pop();
    }
    
    stack1.push(data);
    while (!stack2.isEmpty())
    {
        stack1.push(stack2.Peek());
        stack2.pop();
    }
    

}


void deQueue(){
    if(stack1.isEmpty())
      cout<<"Queue is underflow"<<endl;

      else
        stack1.pop();

}

int front(){
    if(stack1.isEmpty())
        return -1;
    return stack1.Peek();
}

void Display(){
  if(stack1.isEmpty())
     cout<<"Queue is Empty";
     else{
        Node* tem=stack1.top;
        while (tem!=nullptr)
        {
            cout<<tem->data<<" ";
            tem=tem->next;
        }
        

     }
}


int main() {
    enqueu(5);
    enqueu(6);
    enqueu(7);
    enqueu(8);

    cout << "Queue elements after enqueue operations: ";
    Display();

    deQueue();
    cout << "\nQueue elements after one dequeue operation: ";
    Display();

    cout << "\nFront element: " << front() << endl;

    return 0;


    

    return 0;
}