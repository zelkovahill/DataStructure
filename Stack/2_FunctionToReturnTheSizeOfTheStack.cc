#include <iostream>
#define MAX 1000 
using namespace std;

class Stack 
{
    int top;
    int capacity; 

public:
    int a[MAX]; 
    
    Stack() {
        top = -1; 
        capacity = 0; 
    }
    
    bool push(int x);
    int pop();
    int peek();
    bool isEmpty();
    int size(); 
};


bool Stack::push(int x) {
    if (top >= (MAX - 1)) {
        cout << "Stack Overflow\n";
        return false;
    } else {
        a[++top] = x;
        capacity++;
        cout << x << " pushed into stack\n";
        return true;
    }
}

// Function to remove an element from the stack
int Stack::pop() {
    if (top < 0) {
        cout << "Stack Underflow\n";
        return 0;
    } else {
        int x = a[top--];
        capacity--;
        return x;
    }
}


int Stack::peek() {
    if (top < 0) {
        cout << "Stack is Empty\n";
        return 0;
    } else {
        return a[top];
    }
}


bool Stack::isEmpty()
{
    return (top < 0);
}


int Stack::size() 
{
    return capacity;
}

int main() 
{
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