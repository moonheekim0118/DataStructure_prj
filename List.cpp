#include "List.h"
#include <fstream>
#include <string.h>
#include <stdlib.h>
using namespace std;

//문자로 들어온 month를 숫자로 찾을 수 있게 구현한 배열
//해당 인덱스가 숫자 month 
string month_words[13] = 
{ "","January", "Fabuary", "March", "April", "May", "June", "July", "August", "September",
	"October","November","December" };

//listNode 생성자
ListNode::ListNode(string info[]) { //구현완료 
	name = info[0];
	phone_number = info[1];
	birthday_origin = info[2];
	//정수로 변환해서 저장하기 
	//atoi함수는 string 1글자만 변환가능하므로 1월~9월인경우는 스트링 1번째만 변환해서 저장 
	month = atoi(info[2].substr(1, 1).c_str());  
	if (info[2].at(0)=='1'){ //10~12월은 10 더해주기 
		month += 10; }

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

void List::insert(string info[]) //구현완료
{
	ListNode* newNode = new ListNode(info);
	if (isFull()) { return; }

	newNode->next = NULL; //맨 뒤에 저장되기때문에 null값 
	if (head == NULL)  //첫노드라면 head와 tail이 모두 가리킨다.
	{
		head = newNode; //head에 저장  
	}
	else {
		tail->next = newNode;
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
			if (tmp == tail) 
			{
				tail = before;
			}
			delete removed;
			return;
		}
		before = tmp;
		tmp = tmp->next;
	}
	cout << " there is no such person!" << endl;
}


void List::clear() //전체삭제 (for destructor) 
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
	return false;
}



void List::searchByMonth(string m) { //해당 month의 포함된 사람들 출력 

	int count = 0;
	ListNode* tmp = head;
	int n;
	for (int i = 1; i <= 12; i++) { //받은 문자 m에 해당하는 month 숫자로 변환 
		if (month_words[i] == m) { n = i; break; }
	}

	while (tmp != NULL) { //해당 month에 해당하는 사람 수 count 
		if (tmp->month == n) {
			count++;
		}
		tmp = tmp->next;
	}

	cout << "Total number of birthdays in " <<m<<": "<<count << endl;
	tmp = head;
	while (tmp != NULL) { //해당 month에 해당하는사람들 출력 
		if (tmp->month == n) {
			cout << tmp->name << endl;
			cout << tmp->phone_number << endl;
			cout << tmp->birthday_origin << endl;
			cout << endl;
		}
		tmp = tmp->next;
	}

}
 
void List::showStructure() const //모든 entry 수 , 각 month에 속한 사람의 수 출력 
{
	if (isEmpty()) { return; }

	int month_count[13] = { 0, }; //각 month에 속한 사람의 수 count를 위한 배열 
	ListNode* tmp = head;
	int total = 0;
	while (tmp != NULL) {
		total++; //모든 entry 수 계산 
		month_count[tmp->month]++; //해당 month인 사람들 count
		tmp = tmp->next;
	}
	cout << "Total number of entries in the list: " << total << endl;
	 
	for (int i = 1; i <= 12; i++) {
		if (month_count[i] != 0) { //해당 month에 사람이 1명 이상 있다면 출력 
			cout <<"    " << month_words[i] << ": " << month_count[i] << endl;
		}
	}
	
}

void List::write_file() const{ //파일에 쓰기 함수 list node에 접근해야하므로 List의 멤버함수
	string fileName;
	cin >> fileName; //쓸 파일 이름 입력받기 
	fileName.append(".txt");
	ofstream out(fileName); 
	ListNode* tmp = head;
	while (tmp != NULL) 
	{
		out<< tmp->name << endl;
		out << tmp->phone_number << endl;
		out << tmp->birthday_origin << endl;
		out << endl;
		tmp = tmp->next;
	}

}