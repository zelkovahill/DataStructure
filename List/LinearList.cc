#include <iostream>
#define MAX 100
using namespace std;

// 선형 리스트
// 선형 리스트는 배열 기반의 리스트로, 배열의 순차적인 인덱스를 사용하여 요소를 관리

class LinearList
{
    private:
        int arr[MAX];
        int size;

    public:
        LinearList()
        {
            size=0;
        }

        
        void insert(int value)
        {
            if(size<MAX)
            {
                arr[size++]=value;
            }
            else
            {
                cout<<"리스트가 가득 찼습니다.\n";
            }
        }

        void display()
        {
            for(int i=0; i<size; i++)
            {
                cout<<arr[i]<<" ";
            }
            cout<<"\n";
        }

        void remove(int value)
        {
            int i;
            for(i=0;i<size;i++)
            {
                if(arr[i]==value)
                {
                    break;
                }
            }
            if(i<size)
            {
                for(int j=0;j<size-1;j++)
                {
                    arr[j]=arr[j+1];
                }
                size--;
            }
        }
};

int main()
{
    LinearList list;

    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.insert(40);

    list.display();

    list.remove(20);
    list.display();

    return 0;
}