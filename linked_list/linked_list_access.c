/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** Linked list implementation
*/

#include "linked_list.h"

void *ll_get_if(linked_list_t *list, compare_func_t comp_fct, const void *comp)
{
	if (!comp_fct)
		return NULL;
	for (node_t *n = list->head; n; n = n->next) {
		if (comp_fct(n->data, comp))
			return n->data;
	}
	return NULL;
}