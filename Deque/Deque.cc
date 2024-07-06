#include <iostream>

using namespace std;

// 이중 연결 리스트 노드
class Node
{
    public:
        int data;
        Node* next;
        Node* prev;

        Node(int data)
        {
            this->data = data;
            this->next = nullptr;
            this->prev = nullptr;
        }
};

class Deque
{
    private:
        Node* front;
        Node* rear;
        int size;

        public:
            Deque()
            {
                front = nullptr;
                rear = nullptr;
                size =0;
            }

            void push_front(int data);
            void push_back(int data);
            int pop_front();
            int pop_back();
             int get_front();
              int get_back();
              bool is_empty();
                int get_size();
};

// 덱의 앞쪽에 요소 추가
void Deque::push_front(int data)
{
    Node* newNode = new Node(data);
    if(is_empty())
    {
        front = rear = newNode;
    }
    else
    {
        newNode->next =front;
        front->prev = newNode;
        front = newNode;
    }
    size++;
}

// 덱의 뒤쪽에 요소 추가
void Deque::push_back(int data)
{
    Node* newNode = new Node(data);
    if(is_empty())
    {
        front = rear = newNode;
    }
    else
    {
        newNode->prev = rear;
        rear->next =newNode;
        rear = newNode;
    }
    size++;
}

// 덱의 앞쪽 요소 제거
int Deque::pop_front()
{
    if(is_empty())
    {
        throw out_of_range("Deque is empty");
    }
    Node* temp = front;
    int data = temp->data;
    front = front->next;
    if(front)
    {
        front->prev = nullptr;
    }
    else
    {
        rear = nullptr;
    }
    delete temp;
    size--;
    return data;
}

// 덱의 뒤쪽 요소 제거
int Deque::pop_back()
{
    if(is_empty())
    {
        throw out_of_range("Deque is empty");
    }
    Node* temp = rear;
    int data = temp->data;
    rear = rear->prev;
    if(rear)
    {
        rear->next =nullptr;
    }
    else
    {
        front = nullptr;
    }
    delete temp;
    size--;
    return data;
}

// 덱의 앞쪽 요소 반환
int Deque::get_front()
{
    if(is_empty())
    {
        throw out_of_range("Deque is empty");
    }
    return front->data;
}

// 덱의 뒤쪽 요소 반환
int Deque::get_back()
{
    if(is_empty())
    {
        throw out_of_range("Deque is empty");
    }
    return rear->data;
}

// 덱이 비어있는지 확인
bool Deque::is_empty()
{
    return size == 0;
}

// 덱의 크기 반환
int Deque::get_size()
{
    return size;
}

int main()
{
    Deque dq;

    // 덱의 뒤쪽에 요소 추가
    dq.push_back(10);
    dq.push_back(20);
    dq.push_back(30);

    // 덱의 앞쪽에 요소 추가
    dq.push_front(5);
    dq.push_front(1);

    // 덱의 모든 요소 출력
    cout << "Deque: ";
    while (!dq.is_empty())
    {
        cout << dq.get_front() << " ";
        dq.pop_front();
    }
    cout << "\n";

    // 덱의 앞쪽에 요소 추가
    dq.push_front(5);
    dq.push_front(1);

    // 덱의 모든 요소 출력
    cout << "Deque: ";
    while (!dq.is_empty())
    {
        cout << dq.get_back() << " ";
        dq.pop_back();
    }
    cout << "\n";

    return 0;
}
