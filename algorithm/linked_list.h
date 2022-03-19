#pragma once//visual studio 만 이해.
//ifndef를 통한 구현 지향
typedef struct linked_list
{
	int data;
	struct linked_list* link;
} Node;

Node* init(void);
//.h 파일은 주석을 통해서 자세하게 설명해야함.
int add_last(Node* head, const int data);
int add_first(Node* head, const int data);
int delete_node_pos(Node* head, const int pos);
int insert(Node* head, const int data, const int pos);
int search_data(Node* head, const int configdata);
int search_pos(Node* head, const int pos);
int print_list(Node* head,int size);
int size(Node* head);
int exit_node(Node** head);