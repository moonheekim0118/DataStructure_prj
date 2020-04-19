#include <new>
#include <stdexcept>
#include <iostream>
#include <string.h>
using namespace std;
class List;
class ListNode;

class ListNode         
{
private:
    ListNode(string info[]);
    ListNode() {};
    string name;
    string phone_number;
    string birthday_origin; //원형태의 생일 입력정보 저장
    int month; //month만 따로 저장
    // List data item
    ListNode* next;   // Pointer to the next list node

    friend class List;
};


class List
{
public:


    List(); //생성자
    ~List(); //소멸자
    //그 외 멤버함수 
    void insert(string info[]); //ListNode 삽입 
    void remove(string Name); //ListNode 삭제 
    void clear(); // List모두 삭제 (for destructor) 
    void searchByMonth(string m); //입력받은 m (month)에 해당하는 사람의 수와 정보 출력 
    bool isEmpty() const; // list가 empty인지 확인 
    bool isFull() const; //list가 full인지 확인 
    void showStructure() const; //현재 데이터 정보 (총 entry 수와 month별 사람의 수 )
    void write_file() const; //파일에 쓰기 함수 

private:
    // Data members
    ListNode* head,     // 맨 앞 노드를 가리키는 포인터 
        * tail; //맨 마지막 노드를 가리키는 포인터
};
