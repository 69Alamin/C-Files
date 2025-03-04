#include <iostream>
#include <bits/stdc++.h>

using namespace std;


int main() {
    string word;
    cin>>word;
    stack<char>Stack;
    for(int i=0;i<word.length();i++){
         Stack.push(word[i]);
    }

    for(int i=0;i<word.length();i++){
        char c=Stack.top();
        Stack.pop();
        if(c!=word[i]){
            cout<<"Not Palindrome";
            break;
        }
           
        if(i==word.length()-1&&c==word[i])
           cout<<"Palindrome";
    }
    

    return 0;
}