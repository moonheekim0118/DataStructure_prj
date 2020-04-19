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

void print_help() {
	cout << "Commands: " << endl;
	cout << "     R: read from a file" << endl;
	cout << "     +: add a new entry" << endl;
	cout << "     -: removed an entry" << endl;
	cout << "     W: write to a file" << endl;
	cout << "     M: select a month" << endl;
	cout << "     Q: quit the program" << endl;
}

void read_file(List&list) { //���Ϸκ��� read �Լ�  
	bool flag = false; //���� �Է��� �������� ���� 
	string fileName; //���� �̸� �Է¹޴� string 
	int entry_num; //entry num �Է¹޴� ���� 
	string info[3]; //���� entry ���� ���� string 
	cout << "Enter the name of the file : ";
	cin >> fileName; //���� �̸��� �Է¹޴´�
	cout << "Total number of entries in the list: ";
	cin >> entry_num;
	fileName.append(".txt"); 
	ifstream in(fileName); //�Է¹��� ������ ���� 
	
	if (in.is_open()) {
		for (int i = 0; i < entry_num+(entry_num-1); i++) { //������ ��==entry_num-1
			for (int j = 0; j < 3; j++) {
				getline(in, info[j]);
				if (info[j] == "") { //�����ϰ�� insert ���� ���� 
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
	else {
		cout << "������ ã�� �� �����ϴ�" << endl;
		return;
	}
	in.close();
}


int main(void) {
	List list;
	string FirstName;
	string LastName; 
	string info[3]; //name, phone, birthday ���� 
	string delete_Name; //������ �̸� �Է� 
	string Month; //ã�� month �Է�
	char cmd; //��ɾ�

	do {
		cout << endl;
		print_help();
		cin >> cmd;
		switch (cmd) {
		case 'R' : case 'r': //���� �б� 
			read_file(list);
			list.showStructure();
			break;
		case '+': // ���� �߰� 
			cout << "Add an entry:" << endl;
			cout << "Name:";  
			cin >> FirstName; //��
			cin >> LastName; //�̸� 
			FirstName.append(" ");
			info[0] = FirstName.append(LastName);
			cin.ignore(100, '\n'); 
			cout << "Phone: "; 
			cin >> info[1];
			cin.ignore(100, '\n');
			cout << "Birthday: ";
			cin >> info[2];
			list.insert(info); 
			list.showStructure();
			break;
		case '-': //�̸� �Է½� �ش� �̸��� �ش��ϴ� ���� ���� 
			cout << "Remove an entry:" << endl;
			cout << "Name:  ";  
			cin >> FirstName;
			cin >> LastName;
			FirstName.append(" ");
			FirstName.append(LastName);
			list.remove(FirstName);
			list.showStructure();
			break;
		case'W': //���Ͽ� ���� 
			list.write_file();
			break;
		case'M': //�Է¹��� Month�� �ش��ϴ� ������ ���� ����� ���� ���� ��� 
			cout << "Enter the selected month: ";
			cin >> Month;
			list.searchByMonth(Month);
			break;
		case'Q': //�ý��� ���� 
			break;
		}
	} while (cmd != 'Q'&& cmd!='q');

}