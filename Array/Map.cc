#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
    // map을 사용하여 연관 배열 생성
    map<string,int> myMap;

    // 키 - 값 쌍 추가
    myMap["apple"] =1;
    myMap["banana"] =2;
    myMap["cherry"] =3;

    // 키를 사용하여 값에 접근
    cout << "apple: " << myMap["apple"] << endl;
    cout << "banana: " << myMap["banana"] << endl;
    cout << "cherry: " << myMap["cherry"] << endl;

    // 맵에 존재하는 모든 요소 출력
    for(const auto& elem : myMap)
    {
        cout << elem.first << " " << elem.second << endl;
    }

    // 키를 이용해 값 수정
    myMap["banana"] = 20;
    cout<<"banana: "<<myMap["banana"]<<endl;    

    // 키를 이용해 요소 삭제
    myMap.erase("banana");
    cout<<"banana: "<<myMap["banana"]<<endl;    // 0
    // 바나나의 값이 0으로 출력된다. 이는 맵에 해당 키가 없기 때문이다.


    for(const auto& elem : myMap)
    {
        cout << elem.first << " " << elem.second << endl;   //
    }


    return 0;
}