#include <iostream>
#include <fstream>
#include <string>
#include "List.h"
using namespace std;
/*
�־��� txt ���Ͽ��� ���� ( �̸�, ��ȭ��ȣ , ������� )�� �Է¹޽��ϴ�.
�Է¹��� ������ ����Ʈ�� ����Ǿ� Ŀ�ǵ������ ���� Ž�� �����մϴ�. 
�ٸ� txt ���Ͽ� ����� ������ ���, ������ �� �ֽ��ϴ�.
*/

//���� �� : cmd + �� -  �� ����
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

void read_file(List&list) { //���Ϸκ��� read �Լ�  �����Ϸ� 
	bool flag = false; //���� �Է��� �������� ���� 
	string fileName; 
	int entry_num;
	string txt = ".txt";
	string info[3];
	cin >> fileName; //���� �̸��� �Է¹޴´�
	cin >> entry_num;
	fileName.append(txt);
	ifstream in(fileName); //�Է¹��� ������ ���� 
	if (in.is_open()) {
		for (int i = 0; i < entry_num+(entry_num-1); i++) { //���黩�� �޾ƾ��Ѵ�. ������ �� (entry_num-1)
			for (int j = 0; j < 3; j++) {
				getline(in, info[j]);
				if (info[j] == "") { //�����ϰ�� insert�����ֱ� 
					flag = true;
					break;
				}
			}
			if (!flag) {
				list.insert(info); }
			//����Ʈ�� ���� 
			flag = false;
		}
	}
	in.close();
}


int main(void) {
	print_help();
	List list;
	string info[3]; //name, phone, birthday ���� 
	string delete_Name; //������ �̸� �Է� 
	string Month; //ã�� month �Է�
	char cmd; //��ɾ�

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