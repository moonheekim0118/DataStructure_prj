#include "List.h"
#include <fstream>
#include <string.h>
#include <stdlib.h>
using namespace std;

//���ڷ� ���� month�� ���ڷ� ã�� �� �ְ� ������ �迭
//�ش� �ε����� ���� month 
string month_words[13] = 
{ "","January", "February", "March", "April", "May", "June", "July", "August", "September",
	"October","November","December" };

//listNode ������
ListNode::ListNode(string info[]) { 
	name = info[0]; // ���� ���� ���� 
	phone_number = info[1];
	birthday_origin = info[2];
	//������ ��ȯ�ؼ� �����ϱ� 
	//atoi�Լ��� string 1���ڸ� ��ȯ�����ϹǷ� 1��~9���ΰ��� ��Ʈ�� 1��°�� ��ȯ�ؼ� ���� 
	month = atoi(info[2].substr(1, 1).c_str());  
	if (info[2].at(0)=='1'){ //10~12���� 10 �����ֱ� 
		month += 10; }

}


List::List() //List ������ 
{
	head = NULL;
	tail = NULL;
}

List::~List() //List �Ҹ���
{
	clear();
}

void List::insert(string info[]) 
{
	ListNode* newNode = new ListNode(info);
	if (isFull()) { return; }

	newNode->next = NULL; //�� �ڿ� ����Ǳ⶧���� null�� 
	if (head == NULL)  //ù����� head�� tail�� ��� ����Ų��.
	{
		head = newNode; //head�� ����  
	}
	else {
		tail->next = newNode;
	}
	tail = newNode;
}


void List::remove(string Name)
{
	if (isEmpty()) { //����Ʈ�� ����� ��� 
		cout << "List is Empty"<< endl;
		return;
	}
	ListNode* tmp = head;
	ListNode* before = tmp; //������� Ž�� : next������ ���� 
	ListNode* removed;
	while (tmp != NULL) {
		if (tmp->name == Name) { //���� �̸� ���� ��� Ž�� 
			before->next = tmp->next;
			removed = tmp;

			if (tmp == head) { //�����ؾ� �� ��尡 head��� 
				head = tmp->next;
			}
			if (tmp == tail) //�����ؾ� �� ��尡 tail �̶�� 
			{
				tail = before; //tail�� �����ؾ��� ��� �տ� �ִ� ���� �������ֱ� 
				before->next = NULL;
			}
			delete removed; //�޸� �Ҵ�����
			return;
		}
		before = tmp;
		tmp = tmp->next;
	}
	cout << " there is no such person!" << endl;
}


void List::clear() //��ü���� (for destructor) 
{

	ListNode* tmp;
	while (head != NULL) {
		tmp = head;
		head = head->next;
		delete tmp;
	}
	tail = head;
}

bool List::isEmpty() const
{
	if (head == NULL && tail == NULL) return true;
	else return false;
}


bool List::isFull() const
{
	ListNode* location;
	location = new ListNode;
	if (location == NULL) return true;
	delete location;
	return false;
}



void List::searchByMonth(string m) { //�ش� month�� ���Ե� ����� ��� 

	int count = 0;
	ListNode* tmp = head;
	int n=0;
	for (int i = 1; i <= 12; i++) { //���� ���� m�� �ش��ϴ� month ���ڷ� ��ȯ 
		if (month_words[i] == m) { n = i; break; }
	}

	while (tmp != NULL) { //�ش� month�� �ش��ϴ� ��� �� count 
		if (tmp->month == n) {
			count++;
		}
		tmp = tmp->next;
	}

	cout << "Total number of birthdays in " <<m<<": "<<count << endl;
	tmp = head;
	while (tmp != NULL) { //�ش� month�� �ش��ϴ»���� ��� 
		if (tmp->month == n) {
			cout <<"     "<<tmp->name << endl;
			cout<< "     "<< tmp->phone_number << endl;
			cout << "     "<<tmp->birthday_origin << endl;
			cout << endl;
		}
		tmp = tmp->next;
	}

}
 
void List::showStructure() const //��� entry �� , �� month�� ���� ����� �� ��� 
{
	if (isEmpty()) { return; }

	int month_count[13] = { 0, }; //�� month�� ���� ����� �� count�� ���� �迭 
	ListNode* tmp = head;
	int total = 0;
	while (tmp != NULL) {
		total++; //��� entry �� ��� 
		month_count[tmp->month]++; //�ش� month�� ����� count
		tmp = tmp->next;
	}
	cout << "Total number of entries in the list: " << total << endl;
	cout << "Number of birthdays in" << endl;
	for (int i = 1; i <= 12; i++) {
		if (month_count[i] != 0) { //�ش� month�� ����� 1�� �̻� �ִٸ� ��� 
			cout <<"     " << month_words[i] << ": " << month_count[i] << endl;
		}
	}
	
}

void List::write_file() const{ //���Ͽ� ���� �Լ� list node�� �����ؾ��ϹǷ� List�� ����Լ�
	string fileName;
	cout << "Enter the name of the file: ";
	cin >> fileName; //�� ���� �̸� �Է¹ޱ� 
	//fileName.append(".txt");
	ofstream out(fileName+".txt"); 
	ListNode* tmp = head;
	while (tmp != NULL)  //�Է� 
	{
		out<< tmp->name << endl;
		out << tmp->phone_number << endl;
		out << tmp->birthday_origin << endl;
		out << endl;
		tmp = tmp->next;
	}
	cout << "The list is written into " << fileName << endl;
}