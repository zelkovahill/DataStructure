#include <iostream>
#define MAX 1000  

class Stack 
{
    int top;
public:
    int a[MAX]; 

    Stack() { top = -1; } 

    bool push(int x);
    int pop();
    int peek();
    bool isEmpty();
};


bool Stack::push(int x) 
{
    if (top >= (MAX - 1)) 
    {
        std::cout << "Stack Overflow" << std::endl;
        return false;
    } 
    else 
    {
        a[++top] = x;
        std::cout << x << " pushed into stack" << std::endl;
        return true;
    }
}


int Stack::pop() 
{
    if (top < 0) 
    {
        std::cout << "Stack Underflow" << std::endl;
        return 0;
    } 
    else 
    {
        int x = a[top--];
        return x;
    }
}


int Stack::peek() 
{
    if (top < 0) 
    {
        std::cout << "Stack is Empty" << std::endl;
        return 0;
    } 
    else 
    {
        int x = a[top];
        return x;
    }
}


bool Stack::isEmpty() 
{
    return (top < 0);
}

int main() 
{
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    std::cout << s.pop() << " popped from stack" << std::endl;

    std::cout << "Top element is " << s.peek() << std::endl;

    std::cout << "Is stack empty? " << (s.isEmpty() ? "Yes" : "No") << std::endl;

    return 0;
}