#include <iostream>
#include <vector>

using namespace std;

class Stack 
{
private:
    vector<int> a; 

public:
    Stack() {}
    
    bool push(int x);
    int pop();
    int peek();
    bool isEmpty();
    int size(); 
    
};



bool Stack::push(int x) 
{
    a.push_back(x);
    cout << x << " pushed into stack\n";
    return true;
}



int Stack::pop() 
{
    if (a.empty())
     {
        cout << "Stack Underflow\n";
        return 0;
    } 
    else 
    {
        int x = a.back();
        a.pop_back();
        return x;
    }
}


int Stack::peek() 
{
    if (a.empty()) 
    {
        cout << "Stack is Empty\n";
        return 0;
    } 
    else 
    {
        return a.back();
    }
}


bool Stack::isEmpty() 
{
    return a.empty();
}


int Stack::size() 
{
    return a.size();
}

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << s.pop() << " popped from stack\n";
    cout << "Top element is " << s.peek() << "\n";
    cout << "Size of the stack is " << s.size() << "\n";
    cout << "Is stack empty? " << (s.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}