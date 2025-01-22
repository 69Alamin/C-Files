#include <iostream>
#include<bits/stdc++.h>
using namespace std;
struct Node
{
    char data;
    Node *next;

    Node(char data)
    {
        this->data = data;
        next = nullptr;
    }
};
Node *top = nullptr;

void push(char data)
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

char pop()
{
    if (top == nullptr)
        return '\0';
    else
    {
        Node *temp = top;
        char data = top->data;
        top = top->next;

        delete (temp);
        return data;
    }
    return -1;
}

bool bracketCheck(string st)
{
    for (int i = 0; i < st.length(); i++)
    {
        char s = st[i];
        if (s == '(' || s == '{' || s == '[')
            push(s);
        else
        {
            char p = pop();
            if ((s == ')' && p != '(') ||
                (s == '}' && p != '{') ||
                (s == ']' && p != '['))
            {
                return false;
            }
        }
    }
    return top==nullptr;
}

int main()
{
    string input;
    getline(cin, input);

   cout<<bracketCheck(input);

    return 0;
}