#include<iostream>
#include<string>
#include"superbus.h"
#include "avtobus.h"
using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	Node* list;
	Node* list2;
	init_list(list, list);
	add_to_head(list,9, 66, "Univers", "������� �������� ������������", 01, "� �����");
	add_to_head(list,11, 8, "Universe", "����� ���� �������", 02, "� �����");
	add_to_head(list,11, 1337, "Universe", "������ ����� ��������", 02, "�� �����������");
	add_to_head(list,90, 0, "Universe", "��� ������ ���������", 1488, "� �����");
	add_to_head(list,64, 8, "Universe", "������ ������", 7, "�� ������");
	add_to_head(list,11, 80, "Univers", "������ ������", 77, "�� ��������");
	add_to_head(list, 90, 0, "Universe", "��� ����� ��������", 228, "� �����");
	string str = "Universe";
	//five(list);
	max_count_brand(list, str);
	cout<< endl << endl;
	print_list(list);
	cin.get();
}