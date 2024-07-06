#include <iostream>
#include <deque>

using namespace std;

int main()
{
    deque<int> dq;

    // 덱의 뒤에 원소를 추가
    dq.push_back(10); 
    dq.push_back(20);
    dq.push_back(30);

    // 덱의 앞에 원소를 추가
    dq.push_front(5);
    dq.push_front(1);

    // 덱의 모든 요소 출력
    cout<< "Deque: ";
    for(int elem :dq)
    {
        cout<<elem<<" ";
    }
    cout<<"\n";

    // 덱의 앞쪽 요소 제거
    dq.pop_front();
    cout<<"Deque after pop_front(): ";
    for(int elem :dq)
    {
        cout<<elem<<" ";
    }
    cout<<"\n";

    // 덱의 뒤쪽 요소 제거
    dq.pop_back();
    cout<<"Deque after pop_back(): ";
    for(int elem :dq)
    {
        cout<<elem<<" ";
    }
    cout<<"\n";

    // 덱의 앞쪽 요소 출력
    cout<<"Front element: "<<dq.front()<<"\n";

    // 덱의 뒤쪽 요소 출력
    cout<<"Back element: "<<dq.back()<<"\n";

    // 덱의 크기 확인
    cout<<"Size of deque: "<<dq.size()<<"\n";

    // 덱이 비어있는지 확인
    if(dq.empty())
    {
        cout<<"Deque is empty\n";
    }
    else
    {
        cout<<"Deque is not empty\n";
    }

    return 0;
}