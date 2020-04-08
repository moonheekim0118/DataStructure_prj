#include <iostream>
#include <fstream>
#include <string>
#include "List.h"
using namespace std;
/*
주어진 txt 파일에서 정보 ( 이름, 전화번호 , 생년월일 )을 입력받습니다.
입력받은 정보는 리스트에 저장되어 커맨드라인을 통해 탐색 가능합니다. 
다른 txt 파일에 변경된 정보를 출력, 저장할 수 있습니다.
*/

//남은 것 : cmd + 랑 -  더 수정
//month search
//write !!

void print_help() {
	cout << "R: read from a file" << endl;
	cout << "+: add a new entry" << endl;
	cout << "-: removed an entry" << endl;
	cout << "W: write to a file" << endl;
	cout << "M: select a month" << endl;
	cout << "Q: quit the program" << endl;
}

void read_file(List&list) { //파일로부터 read 함수  구현완료 
	bool flag = false; //받은 입력이 공백인지 구분 
	string fileName; 
	int entry_num;
	string txt = ".txt";
	string info[3];
	cin >> fileName; //파일 이름을 입력받는다
	cin >> entry_num;
	fileName.append(txt);
	ifstream in(fileName); //입력받은 파일을 연다 
	if (in.is_open()) {
		for (int i = 0; i < entry_num+(entry_num-1); i++) { //공백빼고 받아야한다. 공백의 수 (entry_num-1)
			for (int j = 0; j < 3; j++) {
				getline(in, info[j]);
				if (info[j] == "") { //공백일경우 insert안해주기 
					flag = true;
					break;
				}
			}
			if (!flag) {
				list.insert(info); }
			//리스트에 삽입 
			flag = false;
		}
	}
	in.close();
}


int main(void) {
	print_help();
	List list;
	string info[3]; //name, phone, birthday 저장 
	string delete_Name; //삭제할 이름 입력 
	string Month; //찾을 month 입력
	char cmd; //명령어

	do {
		cin >> cmd;
		switch (cmd) {
		case 'R' : case 'r':
			read_file(list);
			list.showStructure();
			break;
		case '+':
			cout << "Name:"; 
			cin >> info[0];
			cin.ignore(100, '\n');
			cout << "Phone: "; 
			cin >> info[1];
			cin.ignore(100, '\n');
			cout << "Birthday: ";
			cin >> info[2];
			list.insert(info); 
			list.showStructure();
			break;
		case '-':
			cout << "Name:  ";
			cin >> delete_Name;
			list.remove(delete_Name);
			break;
		case'W':
			list.write_file();
			break;
		case'M':
			cout << "Month: ";
			cin >> Month;
			cout << list.searchbyMonth(Month) << endl;
			list.displayByMonth(Month);
			break;
		case'Q':
			break;
		}
	} while (cmd != 'Q'&& cmd!='q');

}