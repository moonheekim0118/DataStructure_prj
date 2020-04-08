#include <new>
#include <stdexcept>
#include <iostream>
#include <string.h>
using namespace std;
class List;
class ListNode;

class birthdayInfo { /*생일정보 저장 클래스*/
private:
    birthdayInfo();
    string year; //년도
    string month; //월
    string date; //일
    friend class ListNode;
    friend class List;
    
};
class ListNode         
{


private:
    ListNode(string info[]);
    ListNode();
    string name;
    string phone_number;
    string birthday_origin; //원형태의 생일 입력정보 저장
    birthdayInfo birthday_parsing; //생일입력정보 '/' 단위로 끊어서 년도, 월, 일 저장 
    string return_month(string m);
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
