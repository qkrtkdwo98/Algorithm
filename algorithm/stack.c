#include <memory.h>
#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"

typedef struct stack {
	Node* sp;
}stack_t;
//�������� ����ó��
inline static int _empty(stack_t* stack_point) {
	if (stack_point == NULL||stack_point->sp==NULL)
		return -1;
	return (stack_point->sp->link) == NULL;
	
}

static stack_t* _init_stack(void)//void ǥ���ؾ���.c������ ǥ���ʿ�, c++�� ǥ�����
{
	stack_t* s_node = calloc(1, sizeof(stack_t));
	if (s_node == NULL) {
		printf("Failed to allocate memory...");
		return NULL;//�Լ�����
	}
	s_node->sp = init();
	//printf("%p\n", s_node->sp);
	//printf("%p\n", s_node);

	return s_node;
}
static int _pop(stack_t* stack_point) {
	if (stack_point == NULL)
		return -1;
	delete_node_pos(stack_point->sp, 1);//ť�� ����� ���� ��Ȯ��
	return 0;
}
static int _push(stack_t* stack_point, const int data) {
	if (stack_point == NULL)
		return -1;
	add_first(stack_point->sp, data);
	return 0;
}
static int _top(stack_t* stack_point) {
	
	if (stack_point == NULL)
		return -1; 
	search_pos(stack_point->sp, 1);
	return 0;
}

static int _size(stack_t* stack_point) {
	if (stack_point == NULL)
		return -1; 
	printf("%d\n", size(stack_point->sp));//���Ӱ� ������
	return size(stack_point->sp);
}

static int _exit_node_stack(stack_t** stack_point) {
	if (stack_point == NULL || *stack_point == NULL)
		return -1;
	//linked_list �����ڵ�� �ϵ��� ����
	exit_node(*stack_point);

	/*Node* cur = NULL;
	Node* del = NULL;
	del = cur = (*stack_point)->sp;
	while (cur != NULL) {
		
		
		//(*stack_point)->sp = (*stack_point)->sp->link;
		cur = cur->link;

		free(del);
		cur = NULL;
	}*/
	//printf("%p\n", *stack_point);
	free(*stack_point);
	return 0;
}
/*
int main(void){

	stack_t* stack_point = _init_stack();

	for (int i = 1; i <= 5; i++)
		_push(stack_point, i);

	_push(stack_point,  3);
	for (int i = 0; i <= 6; i++) {
		_top(stack_point);
		_pop(stack_point);
	}
	_size(stack_point);

	printf("%d\n", _empty(stack_point));
	
	_exit_node_stack(&stack_point);

	return 0;
}*/

//�ý���->�ڽ��� ���� ���
// stack �̹Ƿ� �ʿ��� �Ķ���� �����ؾ���...sp(stack point)
// ������ ���°��� stack�� �°� �����. sp�� ����
// linked list ������ �����ϸ� �ȉ�, �ǹ� ����.
// que�� head, tail;
//typedef�� ���� ����ü�� ���� ���ִ�.
// linked_list�� �ٲ��� stack�� �ٲ�� �ȵȴ�.