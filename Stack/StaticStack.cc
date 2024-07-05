#include <iostream>
using namespace std;

#define MAX_SIZE 100    // 스택의 최대 크기

// 정적 스택 
class Stack
{
    private:
        int arr[MAX_SIZE]; // 정적 배열
        int top;                // 스택의 상단을 가리키는 변수

    public:
        Stack() : top(-1) {} // 스택 초기화

        bool isEmpty() { return top == -1; } // 스택이 비어있는지 확인
        bool isFull() { return top == MAX_SIZE - 1; } // 스택이 가득 찼는지 확인

        // 스택에 원소를 추가
        void push(int value)
        {
            if(isFull())
            {
                cout<<"Stack overflow\n";
                return;
            }
            arr[++top]=value;
        }

        // 스택의 원소를 제거
        int pop()
        {
            if(isEmpty())
            {
                cout<<"Stack underflow\n";
                return -1;
            }
            return arr[top--];
        }

        // 스택의 상단 원소를 반환
        int peek()
        {
            if(isEmpty())
            {
                cout<<"Stack is empty\n";
                return -1;
            }
            return arr[top];
        }

        // 스택의 크기 반환
        int size()
        {
            return top+1; 
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