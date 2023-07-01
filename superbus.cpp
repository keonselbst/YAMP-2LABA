#include <iostream>
#include <string>
#include "superbus.h"
#include "avtobus.h"

using namespace std;

void init_list(Node*& head, Node*&tail) {
	head = tail = NULL;
};

bool is_empty(Node* head)
{
	if (head == NULL) return true;
	else return false;
};
void add_to_head(Node*& head, int reg_, int num_, std::string brand_, std::string FIO_, int route_, std::string status_)
{
	Node* p = new Node;
	p->value.regnum.reg = reg_;
	p->value.regnum.num = num_;
	p->value.brand = brand_;
	p->value.FIO = FIO_;
	p->value.route = route_;
	p->value.status = status_;

	p->next = head;
	head = p;
}
void add_after_node(Node*&tail, Node*&pNode, int reg_, int num_, std::string brand_, std::string FIO_, int route_, std::string status_)
{
	Node* p = new Node;
	p->value.regnum.reg = reg_;
	p->value.regnum.num = num_;
	p->value.brand = brand_;
	p->value.FIO = FIO_;
	p->value.route = route_;
	p->value.status = status_;

	p->next = pNode->next;
	p->prev = pNode;
	pNode->next = p;
	if (p->next != NULL) p->next->prev = p;
	else tail = p;
}
void delete_current_node(Node*& head, Node*& tail, Node*& pNode)
{
	if (pNode != head && pNode != tail) {
		pNode->next->prev = pNode->prev;
		pNode->prev->next = pNode->next;
	}
	else if (pNode == tail)
		tail = pNode->prev;
	else if (pNode == head)
		head = pNode->next;
	pNode->next = NULL;
	pNode->prev = NULL;
	delete pNode; pNode = 0;
}
void delete_after_node(Node* pNode)
{
	if (pNode->next)
	{
		Node* after_node = pNode->next->next;

		delete pNode->next;
		pNode->next = after_node;
	}
}
void delete_from_head(Node*& head)
{
	Node* p = head;
	head = p->next;
	p->next = nullptr;
	delete p;
	p = nullptr;
}

bool muholovka(Node* i,Node*j, int x)
{
	bool z;
	switch (x) {
	case 1:
		z = situation1(i, j);
		break;
	case 2:
		z = situation2(i,j);
		break;
	case 3:
		z = situation3(i, j);
		break;
	case 4:
		z = situation4(i,j);
		break;
	case 5:
		z = situation5(i,j);
		break;
	}
	return z;
}
void sorting(Node* head, int x)
{
	bool b;
	
	Node* i = head;
	while (i->next != nullptr) {
		Node* j = i->next;
		while (j != nullptr) {
			if (muholovka(i, j, x)) {
				swap(i->value.regnum.reg, j->value.regnum.reg);
				swap(i->value.regnum.num, j->value.regnum.num);
				swap(i->value.brand, j->value.brand);
				swap(i->value.FIO, j->value.FIO);
				swap(i->value.route, j->value.route);
				swap(i->value.status, j->value.status);
			}
			j = j->next;
		}
		i = i->next;
	}
}

bool situation1(Node* i, Node* j)
{
	bool b = false;
	if (i->value.route > j->value.route) 
		b = true;
	return b;
}
bool situation2(Node* i, Node* j)
{
	bool b = false;
	string s1 = i->value.FIO;
	string s2 = j->value.FIO;
	
	if (s1.compare(s2) > -1) b = true;
	return b;
}

bool situation3(Node* i, Node* j)
{
	bool b = false;
	if (i->value.regnum.reg > j->value.regnum.reg)
		b = true;
	else if (i->value.regnum.reg == j->value.regnum.reg)
		if (i->value.regnum.num > j->value.regnum.num)
			b = true;
	return b;
}

bool situation4(Node* i, Node* j)
{
	bool b = false;
	if (i->value.brand.compare(j->value.brand) > -1)
		b = true;
	return b;
}

bool situation5(Node* i, Node* j)
{
	bool b = false;
	if (i->value.status.compare(j->value.status) >-1)
		b = true;
	return b;
}
void print_Node(Node* p)
{
	cout << "регистрационный номер: " << p->value.regnum.reg << " | " << p->value.regnum.num << endl;
	cout << "фирма: " << p->value.brand << endl;
	cout << "фио водителя: " << p->value.FIO << endl;
	cout << "номер маршрута: " << p->value.route << endl;
	cout << "состояние: " << p->value.status << endl << "-----------------------------------------" << endl;
}
void print_list(Node*head)
{
	Node* p = head;
	while (p)
	{
		print_Node(p);
		p = p->next;
	}
}
int find_count_brand_in_reg(Node* &p, string str, int reg1)
{
	int count = 0;
	while (p!=NULL&&p->value.regnum.reg==reg1) {
		if (p->value.brand == str)
			count++;
		p = p->next;
	}
	return count;
}
int find_max_brand_in_all_reg(Node* head, string str)
{
	sorting(head, 3);
	Node* p = head;
	int max = 0, curmax = 0;;
	int reg1 = head->value.regnum.reg;
	while (p) {
		curmax = find_count_brand_in_reg(p, str, reg1);
		p = p->next;
		reg1 = p->value.regnum.reg;
		if (max > curmax) max = curmax;
	}
	return max;
}
void one(Node* head, int route1)
{
	sorting(head, 1);
	Node* p = head;
	int count = 0, size = 0;
	while (p) {
		if (p->value.route == route1) count++;
		size++;
		p = p->next;
	}
	double pr = count * 100 / size;
	cout << pr << "%" << endl;
}
void two(Node* head)
{
	sorting(head, 2);
	Node* p = head;
	while (p->next) {
		Node* k = p;
		int count = 1;
		while (k) {
			
			if (p->value.FIO == k->value.FIO && p->value.route != k->value.route) {
				count++;

			}
				
			k = k->next;
		}
		if (count >= 2)
			cout << p->value.FIO << endl;
		p = p->next;
	}
}
int find_count_regs(Node* head)
{
	sorting(head, 3);
	int count = 1;
	Node* p = head;
	while (p->next != NULL)  {
		if (p->value.regnum.reg != p->next->value.regnum.reg)
		count++;
		p = p->next;
	}
	return count;
}

void max_count_brand(Node* head, string str) {
	sorting(head, 3);
	int n = find_count_regs(head);
	Node* p = head;
	int* countarr = new int[n];
	int* regarr = new int[n];
	int max = 0;
	for (int i = 0; i < n; i++) {
		regarr[i] = p->value.regnum.reg;
		countarr[i] = find_count_brand_in_reg(p, str, regarr[i]);

		//p = p->next;
		if (max < countarr[i]) max = countarr[i];
	}
	for (int i = 0; i < n; i++) {
		if (countarr[i] == max) cout << regarr[i] << endl;
	}
}
void three(Node* head, string brand1)
{
	sorting(head, 3);
	Node* p = head;
	int max = 0;
	int count = 0;
	int maxreg = head->value.regnum.reg;
	int curreg = head->value.regnum.reg;

	while (p) {
		if (p->value.brand == brand1 && p->value.regnum.reg == curreg)
			count++;
		if (count > max ) {
			max = count;
			maxreg = curreg;//&& p->value.regnum.reg == curreg
		}
		else if (p->value.regnum.reg != curreg) count = 0;
		curreg = p->value.regnum.reg;
		p = p->next;
		
	}
	p = head; 
	count = 0;

	while (p) {
		if (p->value.brand == brand1 && p->value.regnum.reg)
			count++;
		
		if (count == max) {
			cout << p->value.regnum.reg << endl;
			count = 0;
		}


		p = p->next;
	}
	cout << find_max_brand_in_all_reg(head, brand1) << endl;
}
void four(Node* head, int reg1)
{
	sorting(head, 4);
	int max = 0;
	string maxstr = head->value.brand;
	Node* p = head;
	int count = 0;
	string curstr = head->value.brand;
	while (p->next) {
		
		if (p->value.regnum.reg == reg1 && p->value.brand==curstr) {
			count++;
			
		}
		if (count > max&& p->value.brand == curstr) {
			max = count;
			maxstr = curstr;
		}
		curstr = p->value.brand;
		p = p->next;
	}
	

	cout << maxstr << endl;;
}

void five(Node*&head)
{
	sorting(head, 5);
	while (head->value.status == "в парке")
		delete_from_head(head);
}
