#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;


// ㅇ 일반 연산
//      - 특정 크기를 갖는 빈 리스트의 생성 (생성된 리스트를 반환)
//         . 例) list create(size)
//      - 리스트 크기 (원소 수를 반환)
//         . 例) integer size()
//      - 빈 리스트 여부 (논리값을 반환)
//         . 例) boolean isEmpty()
//      - 소속 원소 전체를 반환
//         . 例) iterator elements()                                   

//   ㅇ 접근 및 갱신 연산
//      - 원소 접근/탐색
//         . 例) element get(index)
//      - 원소 대체
//         . 例) element set(index,element) 또는 element replace(index,element)
//      - 원소 삭제 (맨 뒤,맨 앞,특정 원소)
//         . 例) element removeFirst(), 
//               element removeLast(),
//               element remove(index)
//      - 원소 삽입 (맨 뒤,맨 앞,특정 원소 뒤)
//         . 例) boolean addFirst(elemet),
//               boolean addLast(elemet),
//               boolean add(index,element)

template <typename T>
class ArrayList
{
    private:
        vector<T> arr;

    public:
        ArrayList(int size =0)
        {
            arr.reserve(size);
        }

        int size() const
        {
            return arr.size();
        }

        bool isEmpty() const
        {
            return arr.empty();
        }

        typename vector<T>::iterator begin()
        {
            return arr.begin();
        }

        T get(int index) const
        {
            if(index <0||index >=arr.size())
            {
                throw out_of_range("Index out of range");
            }
            return arr[index];
        }

        void set(int index, T element)
        {
            if(index<0 || index>=arr.size())
            {
                throw out_of_range("Index out of range");
            }
            arr[index] = element;
        }

        void removeFirst()
        {
            if(arr.empty())
            {
                throw out_of_range("List is empty");
            }
            arr.erase(arr.begin());
        }

        void removeLast()
        {
            if(arr.empty())
            {
                throw out_of_range("List is empty");
            }
            arr.pop_back();
        }

        void remove(int index)
        {
            if(index<0 || index>=arr.size())
            {
                throw out_of_range("Index out of range");
            }
            arr.erase(arr.begin()+index);
        }

        void addFirst(T element)
        {
            arr.insert(arr.begin(),element);
        }

        void addLast(T element)
        {
            arr.push_back(element);
        }

        void add(int index, T element)
        {
            if(index <0||index>arr.size())
            {
                throw out_of_range("Index out of range");
            }
            arr.insert(arr.begin()+index,element);
        }

        void display()
        {
            for(const auto& elem : arr)
            {
                cout << elem << " ";
            }
            cout<<"\n";
        }
};

int main()
{
    ArrayList<int> list;
  
    list.addLast(1);
    list.addLast(2);
    list.addLast(3);
    list.addFirst(5);
    list.display(); // 5 1 2 3

    cout<<"Element at index 2 : "<<list.get(2)<<"\n"; // 2

    list.set(1,15);
    list.display(); // 5 15 2 3

    list.removeFirst();
    list.removeLast();
    list.display(); // 15 2

    list.add(1,20);
    list.display(); // 15 20 2

    cout<<"Size of list : "<<list.size()<<"\n"; // 3
    cout<< "Is list empty : "<<list.isEmpty()<<"\n"; // 0
}