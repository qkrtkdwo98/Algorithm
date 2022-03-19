#include <memory.h>
#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"

typedef struct queue {
	Node* q;
}queue_t;
//전반적인 에러처리
inline static int _q_empty(queue_t* q_head, queue_t* q_tail) {
	if (q_head == NULL || q_head->q == NULL||q_tail==NULL||q_tail->q==NULL)
		return -1;
	return (q_head->q->link) == q_tail->q;

}

static queue_t* _init_queue(void)//void 표기해야함.c언어에서는 표기필요, c++은 표기안함
{
	queue_t* q_node = calloc(1, sizeof(queue_t));
	if (q_node == NULL) {
		printf("Failed to allocate memory...");
		return NULL;//함수형식
	}
	q_node->q = init();
	//printf("%p\n", s_node->sp);
	//printf("%p\n", s_node);

	return q_node;
}
static int _start_queue(queue_t* q_head, queue_t* q_tail) {
	if (q_head == NULL || q_head->q == NULL || q_tail == NULL || q_tail->q == NULL)
		return -1;
	q_head->q->link = q_tail->q;
	q_tail->q->link = NULL;

}

static int _q_size(queue_t* q_head) {
	if (q_head == NULL || q_head->q == NULL)
		return -1;
	
	printf("%d\n", size(q_head->q)-1);
	
	return size(q_head->q)-1;
}
static int _q_pop(queue_t* q_head) {
	if (q_head == NULL || q_head->q == NULL )
		return -1;
	//int last=size(q_head->q);
	delete_node_pos(q_head->q, size(q_head->q)-1);//큐는 사이즈를 통한 끝확인

	return 0;
}
static int _q_push(queue_t* q_head, const int data) {
	if (q_head == NULL || q_head->q == NULL )
		return -1;
	add_first(q_head->q, data);
	return 0;
}
static int _print_queue(queue_t* q_head,queue_t* q_tail) {
	if (q_head == NULL || q_head->q == NULL )
		return -1;
	if (q_head->q->link == q_tail->q)
		printf("empty\n");
	print_list(q_head->q,size(q_head->q)-1);
	
	return 0;
}

static int _exit_node_queue(queue_t** q_head) {
	if (q_head == NULL || *q_head == NULL)
		return -1;
	//linked_list 해제코드로 하도록 하자
	exit_node(*q_head);
	free(*q_head);
	return 0;
}
int main(void) {

	queue_t* q_head = _init_queue();	
	queue_t* q_tail = _init_queue();
	_start_queue(q_head, q_tail);
	
	for (int i = 1; i <= 5; i++)
		_q_push(q_head, i);

	_print_queue(q_head,q_tail);

	_q_push(q_head, 3);
	_print_queue(q_head, q_tail);
	for (int i = 0; i <= 6; i++) {
		_q_pop(q_head);
	}
	_print_queue(q_head, q_tail);
	_q_size(q_head);
	_print_queue(q_head, q_tail);
	printf("%d\n", _q_empty(q_head,q_tail));
	
	_exit_node_queue(&q_head);

	return 0;
}
