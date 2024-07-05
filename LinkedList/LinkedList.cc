#include <iostream>
using namespace std;

// 단순 연결리스트 템플릿

class Node
{
    public:
        int data;           // 데이터
        Node* next;     // 다음 노드를 가리키는 포인터

        Node(int data)
        {
            this->data = data;
            this->next = nullptr;
        }
};

class LinkedList
{
    private:
        Node* head;   // 리스트의 시작을 나타내는 포인터

    public:
        LinkedList()
        {
            head = nullptr;
        }

        // 리스트의 끝에 노드를 추가하는 함수
        void append(int data)
        {
            Node* newNode = new Node(data);

            if(!head)
            {
                head = newNode;
            }
            else
            {
                Node* temp = head;
                while(temp->next)
                {
                    temp = temp->next;
                }
                temp->next = newNode;
            }
        }

        // 리스트의 특정 위치에 노드를 삽입하는 함수
        void insert(int data, int position)
        {
            Node* newNode = new Node(data);
            if(position == 0)
            {
                newNode ->next = head;
                head=newNode;
            }
            else
            {
                Node* temp = head;
                for(int i=0;i<position-1 && temp->next;++i)
                {
                    temp = temp->next;
                }
                newNode->next = temp->next;
                temp->next = newNode;
            }
        }

        // 특정 데이터를 가진 첫 번째 노드를 삭제하는 함수
        void remove(int data)
        {
            if(!head)
            {
                return;
            }
             if(head->data ==data)
             {
                Node* temp = head;
                head = head->next;
                delete temp;
                return;
             }
             Node* temp = head;
             while(temp -> next && temp -> next -> data !=data)
             {
                temp = temp->next;
             }
             if(temp->next)
             {
                Node* nodeToDelete = temp -> next;
                temp->next = temp->next->next;
                delete nodeToDelete;
             }
        }

        // 리스트의 모든 요소를 출력하는 함수
        void printList()
        {
            Node* temp = head;
            while(temp)
            {
                cout<<temp->data<<" -> ";
                temp = temp->next;
            }
            cout << "nullptr" << endl;
        }
};

int main()
{
    LinkedList list;

    list.append(10);
    list.append(20);
    list.append(30);
    list.printList();       // 10 -> 20 -> 30 -> nullptr

    list.insert(15, 1);
    list.printList();       // 10 -> 15 -> 20 -> 30 -> nullptr

    list.remove(20);
    list.printList();       // 10 -> 15 -> 30 -> nullptr

    return 0;
    
}
