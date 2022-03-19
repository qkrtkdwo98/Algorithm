#pragma once//visual studio �� ����.
//ifndef�� ���� ���� ����
typedef struct linked_list
{
	int data;
	struct linked_list* link;
} Node;

Node* init(void);
//.h ������ �ּ��� ���ؼ� �ڼ��ϰ� �����ؾ���.
int add_last(Node* head, const int data);
int add_first(Node* head, const int data);
int delete_node_pos(Node* head, const int pos);
int insert(Node* head, const int data, const int pos);
int search_data(Node* head, const int configdata);
int search_pos(Node* head, const int pos);
int print_list(Node* head,int size);
int size(Node* head);
int exit_node(Node** head);