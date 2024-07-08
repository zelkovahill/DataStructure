#include <iostream>
#include <list>
using namespace std;

// 순서 리스트
// 순서 리스트는 항상 정렬된 상태를 유지하는 리스트
// 새 요소를 삽입할 때 적절한 위치에 삽입하여 정렬 상태를 유지

class OrderedList
{
    private:
        list<int> lst;

    public:
        void insert(int value)
        {
            auto it = lst.begin();
            while(it != lst.end() && *it < value)
            {
                ++it;
            }
            lst.insert(it, value);
        }

        void display()
        {
            for(int value :  lst)
            {
                cout<< value << " ";
            }
            cout<<"\n"; 
        }

        void remove(int value)
        {
            lst.remove(value);
        }
};

int main()
{
    OrderedList list;
    list.insert(1);
    list.insert(3);
    list.insert(2);
    list.insert(4);
    list.display();

    list.remove(3);
    list.display();
    return 0;
}
