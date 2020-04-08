#include <new>
#include <stdexcept>
#include <iostream>
#include <string.h>
using namespace std;
class List;
class ListNode;

class birthdayInfo { /*�������� ���� Ŭ����*/
private:
    birthdayInfo();
    string year; //�⵵
    string month; //��
    string date; //��
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
    string birthday_origin; //�������� ���� �Է����� ����
    birthdayInfo birthday_parsing; //�����Է����� '/' ������ ��� �⵵, ��, �� ���� 
    string return_month(string m);
    // List data item
    ListNode* next;   // Pointer to the next list node

    friend class List;
};


class List
{
public:


    List(); //������
    ~List(); //�Ҹ���
    //�� �� ����Լ� 
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
    ListNode* head,     // �� �� ��带 ����Ű�� ������ 
        * tail; //�� ������ ��带 ����Ű�� ������
};
