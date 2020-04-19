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
    string birthday_origin; //�������� ���� �Է����� ����
    int month; //month�� ���� ����
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
    void insert(string info[]); //ListNode ���� 
    void remove(string Name); //ListNode ���� 
    void clear(); // List��� ���� (for destructor) 
    void searchByMonth(string m); //�Է¹��� m (month)�� �ش��ϴ� ����� ���� ���� ��� 
    bool isEmpty() const; // list�� empty���� Ȯ�� 
    bool isFull() const; //list�� full���� Ȯ�� 
    void showStructure() const; //���� ������ ���� (�� entry ���� month�� ����� �� )
    void write_file() const; //���Ͽ� ���� �Լ� 

private:
    // Data members
    ListNode* head,     // �� �� ��带 ����Ű�� ������ 
        * tail; //�� ������ ��带 ����Ű�� ������
};
