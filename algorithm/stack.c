#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include "linked_list.h"

int pop(Node* head, Node* tail) {
	delete_node_pos(head, tail, 1);
	return 0;
}
int push(Node* head, Node* tail, const int data) {
	add_first(head, tail, data);
	return 0;
}
int top(Node* head, Node* tail) {
	search_pos(head, tail, 1);
	return 0;
}
int empty(Node* head, Node* tail) {
	if (head->link == tail)
		return 1;
	else
		return 0;
}
int size(Node* head, Node* tail) {
	printf("%d\n", search_data(head, tail, NULL));
	return search_data(head, tail,NULL);
}
int main(void)
{
	Node* head = init();
	Node* tail = init();
	head->link = tail;
	tail->link = tail;

	if (head == NULL || tail == NULL) {
		printf("Failed to allocate memory...");
		return -1;
	}
	for (int i = 1; i <= 5; i++)
		push(head, tail, i);

	push(head, tail, 3);
	top(head, tail);
	//pop(head, tail);
	//top(head, tail);
	//pop(head, tail);
	//top(head, tail);
	//pop(head, tail);
	//pop(head, tail);
	size(head, tail);
	//pop(head, tail);
	//pop(head, tail);
	printf("%d\n", empty(head, tail));
	
	exit_node(&head, &tail);

	return 0;
}