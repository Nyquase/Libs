#include <stdlib.h>
#include "linked_list.h"

static void free_list(node_t *n)
{
	if (!n)
		return;
	free_list(n->next);
	free(n->data);
	free(n);
}

void ll_destroy(linked_list_t *list)
{
	free_list(list->head);
	list->head = NULL;
	list->tail = NULL;
	list->size = 0;
}
