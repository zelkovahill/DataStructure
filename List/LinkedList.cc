#include <iostream>
using namespace std;

// 연결 리스트
// 연결 리스트는 노드로 구성되며, 각 노드는 데이터와 다음 노드를 가리키는 포인터로 구성

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

class LinkedList
{
    private:
        Node* head;

        public: 
            LinkedList()
            {
                head = nullptr;
            }

            void insert(int value)
            {
                Node* newNode = new Node(value);
                newNode->next = head;
                head = newNode;
            }

            void display()
            {
                Node* temp = head;
                while(temp)
                {
                    cout<<temp->data<<" ";
                    temp = temp -> next;
                }
            }

            void remove(int value)
            {
                if(!head)
                {
                    return;
                }
                if(head->data ==value)
                {
                    Node* temp = head;
                    head = head->next;
                    delete temp;
                    return;
                }
                Node* temp = head;
                while(temp->next && temp->next->data != value)
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
};

int main()
{
    LinkedList list;
    list.insert(1);
    list.insert(2);
    list.insert(3);

    list.display();
    cout<<"\n";

    list.remove(2);
    list.display();
    return 0;
}