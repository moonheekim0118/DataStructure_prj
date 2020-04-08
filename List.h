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
    ListNode();
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
    void insert(string info[]);
    void remove(string Name);
    void clear();
    int searchbyMonth(string m);
    void displayByMonth(string m);
    bool isEmpty() const;
    bool isFull() const;
    void showStructure() const;
    void write_file() const;

private:
    // Data members
    ListNode* head,     // 맨 앞 노드를 가리키는 포인터 
        * tail; //맨 마지막 노드를 가리키는 포인터
};
