#include <iostream>
#include <vector>

using namespace std;

//  배열 리스트
// 배열 리스트는 선형 리스트와 비슷하지만 동적 배열을 사용하여 크기를 유동적으로 조절할 수 있다.

class ArrayList
{
    private:
        vector<int> arr;

    public:
        void insert(int value)
        {
            arr.push_back(value);
        }
        
        void display()
        {
            for(int value : arr)
            {
                cout <<value<<" ";
            }
            cout<<"\n";
        }

        void remove(int value)
        {
            auto it = find(arr.begin(),arr.end(),value);
            if(it!= arr.end())
            {
                arr.erase(it);
            }
        }
};

int main()
{
    ArrayList list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);
    list.display();

    list.remove(3);
    list.display();
    return 0;
   
}