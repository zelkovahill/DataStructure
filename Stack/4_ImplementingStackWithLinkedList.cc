#include <iostream>

using namespace std;


class Node
{
public:
    int data;
    Node* next;

    Node(int data) 
    {
        this->data = data;
        this->next = nullptr;
    }
};


class Stack
{
private:
    Node* top;
    int capacity; 

public:
    Stack() 
    {
        top = nullptr;
        capacity = 0;
    }
    
    bool push(int x);
    int pop();
    int peek();
    bool isEmpty();
    int size(); 
};


bool Stack::push(int x) 
{
    Node* newNode = new Node(x);
    newNode->next = top;
    top = newNode;
    capacity++;
    cout << x << " pushed into stack\n";
    return true;
}


int Stack::pop() 
{
    if (isEmpty()) 
    {
        cout << "Stack Underflow\n";
        return 0;
    } 
    else
    {
        Node* temp = top;
        int poppedData = temp->data;
        top = top->next;
        delete temp;
        capacity--;
        return poppedData;
    }
}


int Stack::peek() 
{
    if (isEmpty()) 
    {
        cout << "Stack is Empty\n";
        return 0;
    } 
    else 
    {
        return top->data;
    }
}


bool Stack::isEmpty() 
{
    return top == nullptr;
}


int Stack::size() 
{
    return capacity;
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