#include <iostream>
#include <stdexcept>

using namespace std;

class Stack {
private:
    vector<int> a; 

public:
    Stack() {}
    
    void push(int x);
    int pop();
    int peek();
    bool isEmpty();
    int size(); 
};


void Stack::push(int x) 
{
    a.push_back(x);
    cout << x << " pushed into stack\n";
}


int Stack::pop()
{
    if (a.empty()) 
    {
        throw runtime_error("Stack Underflow");
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
        throw runtime_error("Stack is Empty");
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
    try 
    {
        s.push(10);
        s.push(20);
        s.push(30);
        cout << s.pop() << " popped from stack\n";
        cout << "Top element is " << s.peek() << "\n";
        cout << "Size of the stack is " << s.size() << "\n";
        cout << "Is stack empty? " << (s.isEmpty() ? "Yes" : "No") << endl;
    } 
    catch (const runtime_error& e) 
    {
        cerr << e.what() << endl;
    }

    return 0;
}