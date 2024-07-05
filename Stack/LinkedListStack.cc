#include <iostream>
using namespace std;

class StackNode
{
    public:
        int data;
        StackNode* next;
};

class Stack
{
    private:
        StackNode* top; // 스택의 상단을 가리키는 변수

    public:
        Stack() : top(nullptr) {} // 스택 초기화
        
        ~Stack()
        {
            while(!isEmpty())
            {
                pop();
            }
        }

        bool isEmpty() { return top == nullptr; } // 스택이 비어있는지 확인

        //  스택의 원소를 추가
        void push(int value)
        {
            StackNode* newNode = new StackNode();
            newNode->data = value;
            newNode->next = top;
            top = newNode;
        }

        // 스택의 원소를 제거
        int pop()
        {
            if(isEmpty())
            {
                cout <<"Stack underflow\n";
                return -1;
            }
            StackNode* temp =top;
            int value = temp->data;
            top = top->next;
            delete temp;
            return value;
        }

        // 스택의 상단 원소를 반환
         int peek()
         {
            if(isEmpty())
            {
                cout<<"Stack is empty\n";
                return -1;
            }
         return top -> data;
         }

        // 스택의 크기 반환
         int size()
         {
            int count =0;
            StackNode* current = top;
            while(current)
            {
                count++;
                current = current->next;
            }
            return count;
         }
};


int main()
{
    Stack stack;

    stack.push(1);
    stack.push(2);
    stack.push(3);

    cout<<"top element is "<<stack.peek()<<"\n";
    cout<<"Stack size is "<<stack.size()<<"\n";

    stack.pop();
    cout<<"top element is "<<stack.peek()<<"\n";
    cout<<"Stack size is "<<stack.size()<<"\n";

    return 0;
}