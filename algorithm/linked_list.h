#pragma once//visual studio ¸¸ ÀÌÇØ.

typedef struct linked_list
{
	int data;
	struct linked_list* link;
} Node;
//typedef struct linked_list Node;
Node* init(void);

int add_last(Node* head, const int data);
int add_first(Node* head, const int data);
int insert(Node* head, const int data, const int pos);
int delete_node_pos(Node* head, const int pos);
int search_data(Node* head, const int configdata);
int search_pos(Node* head, const int pos);
int print_list(Node* head);
int exit_node(Node** head);