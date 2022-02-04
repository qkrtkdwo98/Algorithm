#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct linked_list
{
	int data;
	struct linked_list* link;
} Node;

Node* init(void)//void 표기해야함.c언어에서는 표기필요, c++은 표기안함
{
	Node* node = malloc(sizeof(Node));//옛날에는 형변환 필요(Node*), 요즘은 필요없음
	if (node == NULL) {
		printf("Failed to allocate memory...");
		return -1;
	}
	//memset(node, 0, sizeof(Node)); //확장성을 고려하여 설계
	//malloc + memset = calloc 속도는 앞이 조금 더 빠름
	return node;
}
//inline을 사용할 시 헤더에 함수를 통째로 선언해야함.
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
			printf("위치 : %d 번째\n", i);
			cnt++;
		}
		cur = cur->link;
		i++;
	}
	printf("갯수:%d\n", cnt);
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
		printf("%d번째:%d\n", i + 1, prt->data);
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
파일이름도 무조건 영어(소문자), 단어사이는 '_'
const char 붙혀야함. const는 read only 영역에 배치, 속도업
코드는 최대한 간결하게
조건문안에서 함수를 직접적으로 호출하는것은 지양

*/