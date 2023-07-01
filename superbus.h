#pragma once
#include<string>
#include "avtobus.h"
using namespace std;

	struct Node{
		Node* next, * prev;
		struct data value;
	};

	bool situation1(Node* , Node* );
	bool situation2(Node* i, Node* j);
	bool situation3(Node* i, Node* j);
	bool situation4(Node* i, Node* j);
	bool situation5(Node* i, Node* j);
	bool muholovka(Node* temp, int x);
	void print_Node(Node* p);
	void init_list(Node*& head, Node*& tail);
	bool is_empty(Node* haed);
	void add_to_head(Node*& head, int reg1, int num1, std::string brand1, std::string FIO1, int route1, std::string status1);
	void add_after_node(Node*&tail,Node*& pNode, int reg1, int num1, std::string brand1, std::string FIO1, int route1, std::string status1);
	void delete_current_node(Node*& head, Node*& tail, Node*& pNode);
	void delete_after_node(Node* pNode);
	void delete_from_head(Node*& head);
	void print_list(Node*head);
	void sorting(Node*head, int x);
	int find_count_brand_in_reg(Node* &p, string str, int reg1);
	int find_max_brand_in_all_reg(Node* p, string str);
	int find_count_regs(Node* head);
	void max_count_brand(Node* head, string str);

	void one(Node* head, int route1);
	void two(Node* head);
	void three(Node*head, string brand1);
	void four(Node*head, int reg1);
	void five(Node*& head);

	
	
	

