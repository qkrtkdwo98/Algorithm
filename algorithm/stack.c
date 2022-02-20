#include <memory.h>
#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"
//시스템->자신이 만든 헤더
// stack 이므로 필요한 파라미터 생각해야함...sp(stack point)
// 가져다 쓰는거지 stack에 맞게 써야함. sp만 노출
// linked list 내용을 노출하면 안됌, 의미 없다.
// que는 head, tail;
typedef struct stack {
	Node* sp;
}stack_t;
inline static int _empty(stack_t* stack_point) {//inline으로 충분히 구현 가능함.
	return (stack_point->sp->link) == NULL;
	
}
//typedef를 통해 구조체는 감출 수있다.
// linked_list가 바껴도 stack은 바뀌면 안된다.
stack_t* init_stack(void)//void 표기해야함.c언어에서는 표기필요, c++은 표기안함
{
	//printf("check");
	stack_t* s_node = calloc(1, sizeof(stack_t));//옛날에는 형변환 필요(Node*), 요즘은 필요없음
	s_node->sp = init();
	if (s_node == NULL) {
		printf("Failed to allocate memory...");
		return -1;
	}
	//printf("check");
	//memset(node, 0, sizeof(Node)); //확장성을 고려하여 설계
	//malloc + memset = calloc 속도는 앞이 조금 더 빠름
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
/*static int _empty(stack_t* stack_point) {//inline으로 충분히 구현 가능함.
	if ((stack_point->sp->link)== NULL)
		return 1;
	else
		return 0;
}*/
static int _size(stack_t* stack_point) {
	int* ptr=NULL;
	
	printf("%d\n", search_data(stack_point->sp, NULL));//NULL관련 형변환 필요.
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