#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct linked_list
{
	int data;
	struct linked_list* link;
} Node;

Node* init(void)//void ǥ���ؾ���.c������ ǥ���ʿ�, c++�� ǥ�����
{
	Node* node = malloc(sizeof(Node));//�������� ����ȯ �ʿ�(Node*), ������ �ʿ����
	if (node == NULL) {
		printf("Failed to allocate memory...");
		return -1;
	}
	//memset(node, 0, sizeof(Node)); //Ȯ�强�� ����Ͽ� ����
	//malloc + memset = calloc �ӵ��� ���� ���� �� ����
	return node;
}
//inline�� ����� �� ����� �Լ��� ��°�� �����ؾ���.
int add_last(Node* head, Node* tail, const int data) {
	Node* last = head;

	while (last->link != tail)
		last = last->link;

	Node* newNode = init();
	newNode->data = data;
	newNode->link = tail;
	last->link = newNode;
	printf("%p\n", newNode);
	return 0;
}

int add_first(Node* head, Node* tail, const int data) {
	Node* newNode = init();
	newNode->link = head->link;
	newNode->data = data;
	head->link = newNode;
	return 0;
}

int insert(Node* head, Node* tail, const int data, const int pos) {
	Node* cur = head;
	Node* newNode = init();
	newNode->data = data;
	if (pos == 1) {
		newNode->link = head->link;
		head->link = newNode;
	}

	else {
		int cnt = 0;
		cnt = pos;
		while (cnt != 0) {
			if (cnt == 1) {
				newNode->link = cur->link;
				cur->link = newNode;
			}
			cur = cur->link;
			cnt--;
		}
	}
	return 0;
}
int delete_node_pos(Node* head, Node* tail, const int pos) {
	Node* cur = head;
	Node* del = head;
	int cnt = 0;
	cnt = pos;
	while (cnt != 0) {
		if (cnt == 1) {
			cur = del;
		}
		del = del->link;
		cnt--;
	}
	cur->link = del->link;
	free(del);
	return 0;
}

int search_data(Node* head, Node* tail, const int configdata) {
	Node* cur = head;
	int i = 0;
	int cnt = 0;
	while (cur != tail) {
		if (cur->data == configdata) {
			printf("��ġ : %d ��°\n", i);
			cnt++;
		}
		cur = cur->link;
		i++;
	}
	printf("����:%d\n", cnt);
	return 0;
}

int search_pos(Node* head, Node* tail, const int pos) {
	Node* cur = head;
	int i = 0;
	while (cur != tail) {
		if (i == pos) {
			printf("%d\n", cur->data);
			break;
		}
		cur = cur->link;
		i++;
	}
	return 0;
}

int print_list(Node* head, Node* tail) {
	Node* prt = head->link;
	int i = 0;
	while (prt != tail) {
		printf("%d��°:%d\n", i + 1, prt->data);
		prt = prt->link;
		i++;
	}

	return 0;
}

int exit_node(Node** head, Node** tail) {
	if (*head == NULL || *tail == NULL)
		return -1;

	Node* cur = NULL;
	while (*head != *tail) {
		cur = *head;
		*head = (*head)->link;
		//printf("%p\n", cur);
		free(cur);
		cur = NULL;
	}
	free(*tail);
	return 0;
}


/*
�����̸��� ������ ����(�ҹ���), �ܾ���̴� '_'
const char ��������. const�� read only ������ ��ġ, �ӵ���
�ڵ�� �ִ��� �����ϰ�
���ǹ��ȿ��� �Լ��� ���������� ȣ���ϴ°��� ����

*/