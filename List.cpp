#include "List.h"
#include <fstream>
#include <string.h>
using namespace std;


//listNode 생성자
ListNode::ListNode(string info[]) {
	name = info[0];
	phone_number = info[1];
	birthday_origin = info[2];
	string month = return_month(info[2].substr(0,1));
	string date = info[2].substr(3, 4);
	string year = info[2].substr(6, 9); //이거 수정해주기 
	birthday_parsing.year = year;
	birthday_parsing.month = month; //여기에 들어가는 month의 형태는 January 
	birthday_parsing.date = date; 
}


List::List() //List 생성자 
{
	head = NULL;
	tail = NULL;
}

List::~List() //List 소멸자
{
	clear();
}

void List::insert(string info[])
{
	ListNode* newNode = new ListNode(info);
	if (isFull()) { return; }
	newNode->next = NULL; //맨 뒤에 저장되기때문에 null값 
	if (head == NULL)  //첫노드라면 head와 tail이 모두 가리킨다.
	{
		head = newNode; //head에 저장  
	}
	tail = newNode;
}


void List::remove(string Name)
{
	if (isEmpty()) {
		cout << "List is Empty"<< endl;
		return;
	}
	ListNode* tmp = head;
	ListNode* before = tmp; //이전요소 탐색 : next변경을 위해 
	ListNode* removed;
	while (tmp != NULL) {
		if (tmp->name == Name) { //같은 이름 가진 사람 탐색 
			before->next = tmp->next;
			removed = tmp;
			delete removed;
			return;
		}
		before = tmp;
		tmp = tmp->next;
	}
	cout << " there is no such person!" << endl;
	return;

}


void List::clear() //전체삭제 (for destructor) 
{

	ListNode* tmp;
	while (head != NULL) {
		tmp = head;
		head = head->next;
		delete tmp;
	}

}

bool List::isEmpty() const
{
	if (head == NULL && tail == NULL) return true;
	else return false;
}


bool List::isFull() const
{
	ListNode* tmp;
	tmp = new ListNode; //확인을 위해 임시 생성
	tmp->next = NULL;
	if (tmp == NULL) {
		return true;
	}
	else {
		delete tmp;
		return false;
	}
}

string ListNode:: return_month(string m) { 
	if (m == "01") return "January";
	if (m == "02") return "Fabuary";
	if (m == "03") return "March";
	if (m == "04") return "April";
	if (m == "05") return "May";
	if (m == "06") return "June";
	if (m == "07") return "July";
	if (m == "08") return "August";
	if (m == "09") return "September";
	if (m == "10") return "October";
	if (m == "11") return "November";
	if (m == "12") return "December";
	else return "-1";
}

int List::searchbyMonth(string m) { //해당 month에 해당된 사람 수 찾기 
	int count = 0; 
	ListNode* tmp = head;
	while (tmp != NULL) {
		if (tmp->birthday_parsing.month == m) {
			count++;
		}
		tmp = tmp->next;
	}
	return count;
}

void List::displayByMonth(string m) { //해당 month의 포함된 사람들 출력 
	ListNode* tmp = head;
	while (tmp != NULL) {
		if (tmp->birthday_parsing.month == m) {
			cout << tmp->name << endl;
			cout << tmp->phone_number << endl;
			cout << tmp->birthday_origin << endl;
		}
		tmp = tmp->next;
	}

}
 
void List::showStructure() const
{
	if (isEmpty()) { return; }

	ListNode* tmp = head;
	int total = 0;
	int month_count[13] = { 0, };
	while (tmp != NULL) {
		total++;
		tmp = tmp->next;
	}
	cout << "Total number of entries in the list: " << total << endl;
	//어떻게 효율적으로 출력할것인가 생각해보기  
}

void List::write_file() const{
	string fileName;
	ifstream in(fileName);
	ListNode* tmp = head;
	while (tmp != NULL) 
	{
		cout << tmp->name << endl;
		cout << tmp->phone_number << endl;
		cout << tmp->birthday_origin << endl;
		tmp = tmp->next;
	}

}