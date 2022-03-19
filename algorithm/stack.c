#include <memory.h>
#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"

typedef struct stack {
	Node* sp;
}stack_t;
//전반적인 에러처리
inline static int _empty(stack_t* stack_point) {
	if (stack_point == NULL||stack_point->sp==NULL)
		return -1;
	return (stack_point->sp->link) == NULL;
	
}

static stack_t* _init_stack(void)//void 표기해야함.c언어에서는 표기필요, c++은 표기안함
{
	stack_t* s_node = calloc(1, sizeof(stack_t));
	if (s_node == NULL) {
		printf("Failed to allocate memory...");
		return NULL;//함수형식
	}
	s_node->sp = init();
	//printf("%p\n", s_node->sp);
	//printf("%p\n", s_node);

	return s_node;
}
static int _pop(stack_t* stack_point) {
	if (stack_point == NULL)
		return -1;
	delete_node_pos(stack_point->sp, 1);//큐는 사이즈를 통한 끝확인
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
	printf("%d\n", size(stack_point->sp));//새롭게 만들자
	return size(stack_point->sp);
}

static int _exit_node_stack(stack_t** stack_point) {
	if (stack_point == NULL || *stack_point == NULL)
		return -1;
	//linked_list 해제코드로 하도록 하자
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

//시스템->자신이 만든 헤더
// stack 이므로 필요한 파라미터 생각해야함...sp(stack point)
// 가져다 쓰는거지 stack에 맞게 써야함. sp만 노출
// linked list 내용을 노출하면 안됌, 의미 없다.
// que는 head, tail;
//typedef를 통해 구조체는 감출 수있다.
// linked_list가 바껴도 stack은 바뀌면 안된다.