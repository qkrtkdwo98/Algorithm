#include <memory.h>
#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"
//�ý���->�ڽ��� ���� ���
// stack �̹Ƿ� �ʿ��� �Ķ���� �����ؾ���...sp(stack point)
// ������ ���°��� stack�� �°� �����. sp�� ����
// linked list ������ �����ϸ� �ȉ�, �ǹ� ����.
// que�� head, tail;
typedef struct stack {
	Node* sp;
}stack_t;
inline static int _empty(stack_t* stack_point) {//inline���� ����� ���� ������.
	return (stack_point->sp->link) == NULL;
	
}
//typedef�� ���� ����ü�� ���� ���ִ�.
// linked_list�� �ٲ��� stack�� �ٲ�� �ȵȴ�.
stack_t* init_stack(void)//void ǥ���ؾ���.c������ ǥ���ʿ�, c++�� ǥ�����
{
	//printf("check");
	stack_t* s_node = calloc(1, sizeof(stack_t));//�������� ����ȯ �ʿ�(Node*), ������ �ʿ����
	s_node->sp = init();
	if (s_node == NULL) {
		printf("Failed to allocate memory...");
		return -1;
	}
	//printf("check");
	//memset(node, 0, sizeof(Node)); //Ȯ�强�� ����Ͽ� ����
	//malloc + memset = calloc �ӵ��� ���� ���� �� ����
	return s_node;
}
static int _pop(stack_t* stack_point) {
	delete_node_pos(stack_point->sp, 1);
	return 0;
}
static int _push(stack_t* stack_point, const int data) {
	
	add_first(stack_point->sp, data);
	//printf("check");
	return 0;
}
static int _top(stack_t* stack_point) {
	search_pos(stack_point->sp, 1);
	return 0;
}
/*static int _empty(stack_t* stack_point) {//inline���� ����� ���� ������.
	if ((stack_point->sp->link)== NULL)
		return 1;
	else
		return 0;
}*/
static int _size(stack_t* stack_point) {
	int* ptr=NULL;
	
	printf("%d\n", search_data(stack_point->sp, NULL));//NULL���� ����ȯ �ʿ�.
	return search_data(stack_point->sp, NULL);
}

static int _exit_node_stack(stack_t** stack_point) {
	if ((*stack_point)->sp == NULL)
		return -1;

	Node* cur = NULL;
	while ((*stack_point)->sp != NULL) {
		cur = (*stack_point)->sp;
		(*stack_point)->sp = (*stack_point)->sp->link;
		free(cur);
		cur = NULL;
	}
	free(*stack_point);
	return 0;
}
int main(void){

	stack_t* stack_point = init_stack();
	if (stack_point == NULL ){
		printf("Failed to allocate memory...");
		return -1;
	}
	for (int i = 0; i <= 5; i++)
		_push(stack_point, i);

	_push(stack_point,  3);
	_top(stack_point);
	_pop(stack_point);
	_top(stack_point);
	_pop(stack_point);
	_top(stack_point);
	_pop(stack_point);
	_top(stack_point);
	_pop(stack_point);
	_top(stack_point);
	_pop(stack_point);
	_top(stack_point);
	_pop(stack_point);
	_size(stack_point);

	printf("%d\n", _empty(stack_point));
	
	_exit_node_stack(&stack_point);

	return 0;
}