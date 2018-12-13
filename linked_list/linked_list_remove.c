#include <stdlib.h>
#include "linked_list.h"

void ll_remove(linked_list_t *list, node_t *node)
{
	if (node == list->head)
		ll_pop_front(list);
	else if (node == list->tail)
		ll_pop_back(list);
	else {
		node->next->prev = node->prev;
		node->prev->next = node->next;
		free(node->data);
		free(node);
		list->size--;
	}
}

void ll_remove_if(linked_list_t *list, compare_func_t cmp_f, const void *comp)
{
	node_t *n = list->head;
	while (n) {
		node_t *next = n->next;
		if (cmp_f(n->data, comp))
			ll_remove(list, n);
		n = next;
	}
}

void ll_pop_front(linked_list_t *list)
{
	if (!list->head)
		return;
	node_t *popped = list->head;
	list->head = popped->next;
	if (!list->head)
		list->tail = NULL;
	else
		list->head->prev = NULL;
	free(popped->data);
	free(popped);
	list->size--;
}

void ll_pop_back(linked_list_t *list)
{
	if (!list->tail)
		return;
	node_t *popped = list->tail;
	list->tail = popped->prev;
	if (!list->tail)
		list->head = NULL;
	else
		list->tail->next = NULL;
	free(popped->data);
	free(popped);
	list->size--;
}

