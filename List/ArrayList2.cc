#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;

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