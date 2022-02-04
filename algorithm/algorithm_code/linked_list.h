#pragma once

typedef struct linked_list
{
	int data;
	struct linked_list* link;
} Node;
Node* init(void);
int add_last(Node* head, Node* tail, const int data);
int add_first(Node* head, Node* tail, const int data);
int insert(Node* head, Node* tail, const int data, const int pos);
int delete_node_pos(Node* head, Node* tail, const int pos);
int search_data(Node* head, Node* tail, const int configdata);
int print_list(Node* head, Node* tail);
int exit_node(Node** head, Node** tail);