/*
** Main to test linked lists
*/

#include <stdio.h>
#include "linked_list.h"

typedef struct {
	int id;
} info_t;

static bool cmp_func(const void *node, const void *my_info)
{
	const info_t *n = node;
	const info_t *cmp_info = my_info;
	return (n->id == cmp_info->id);
}

static void print_list(linked_list_t *list)
{

	printf("--------\n");
	for (node_t *n = list->head; n; n = n->next) {
		info_t *info = n->data;
		printf("%d\n", info->id);
	}
	printf("--------\n");
}

int main()
{
	linked_list_t list = {0}; // Lists should always be initialized like this
	                          // otherwise the behavior is undefined

	ll_push_back(&list, &(info_t){1}, sizeof(info_t));
	ll_push_back(&list, &(info_t){2}, sizeof(info_t));
	ll_push_back(&list, &(info_t){3}, sizeof(info_t));
	ll_push_back(&list, &(info_t){4}, sizeof(info_t));
	ll_push_back(&list, &(info_t){5}, sizeof(info_t)); // [1, 2, 3, 4, 5]

	ll_push_front(&list, &(info_t){1}, sizeof(info_t)); // [1, 1, 2, 3, 4, 5]
	ll_push_front(&list, &(info_t){2}, sizeof(info_t));
	ll_push_front(&list, &(info_t){3}, sizeof(info_t));
	ll_push_front(&list, &(info_t){4}, sizeof(info_t));
	ll_push_front(&list, &(info_t){5}, sizeof(info_t));
        // [5, 4, 3, 2, 1, 1, 2, 3, 4, 5]
	print_list(&list);

	ll_remove_if(&list, cmp_func, &(info_t){1}); // Remove every node whith id == 1
	ll_pop_front(&list);
	ll_pop_back(&list);
	print_list(&list);

	// Manual loop when you have to remove while looping
	node_t *node = list.head;
	while (node) {
		node_t *next = node->next; // You have to save the next in case
		                           // you delete the current node
		if (((info_t *)node->data)->id == 2) {
			ll_insert_after(&list, node, &(info_t){42}, sizeof(info_t));
			ll_remove(&list, node); // replace every 3's by 42
		}
		node = next;
	}
	print_list(&list);

	info_t *info = ll_get_if(&list, cmp_func, &(info_t){3}); // This will get the fisrt 3 of the list
	printf("%d\n", info->id);

	ll_destroy(&list);
	return (0);
}
