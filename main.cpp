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
	add_to_head(list,9, 66, "Univers", "Водилов Водитель Водительевич", 01, "в парке");
	add_to_head(list,11, 8, "Universe", "Шуров Шура Шурович", 02, "в парке");
	add_to_head(list,11, 1337, "Universe", "Грушов Груша Грушович", 02, "на автовокзале");
	add_to_head(list,90, 0, "Universe", "Вол Володя Володявич", 1488, "в парке");
	add_to_head(list,64, 8, "Universe", "Иванов Иванов", 7, "на дороге");
	add_to_head(list,11, 80, "Univers", "Иванов Иванов", 77, "на маршруте");
	add_to_head(list, 90, 0, "Universe", "Дим Диман Иванович", 228, "в парке");
	string str = "Universe";
	//five(list);
	max_count_brand(list, str);
	cout<< endl << endl;
	print_list(list);
	cin.get();
}