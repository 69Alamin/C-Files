#include <iostream>
#include <vector>
using namespace std;

void reverse_Vector(vector<int> &ref)
{
    int size = ref.size();
    for (int i = 0; i < size / 2; i++)
    {
        int temp = ref[size - i-1];
        ref[size - i-1] = ref[i];
        ref[i] = temp;
    }
}

int main()
{
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);

    cout << "Size=" << vec.size() << endl;
    vec.pop_back();
    cout << "After pop Size=" << vec.size() << endl;

    for (int value : vec)
    {
        cout << value << endl;
    }
    

    reverse_Vector(vec);
    cout<<"After Reverse :"<<endl;
    for (int value : vec)
    {
        cout << value << endl;
    }

    return 0;
}