#include <iostream>

// 간단한 동적 배열
using namespace std;

int main()
{
    int size;
    cin>>size;

    // 동적 배열 할당
    int* arr =new int[size];

    for(int i=0;i<size;++i)
    {
        arr[i]=i+1;
    }

    for(int i=0;i<size;++i)
    {
        cout<<arr[i]<<"\n";
    }

    // 동적 배열 해제
    delete[] arr;
}