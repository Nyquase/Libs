#include "linked_list.h"

static bool default_cmp(const void *lhs, const void *rhs)
{
  return (lhs == rhs);
}

void *ll_get_if(linked_list_t *list, compare_func_t comp_fct, const void *comp)
{
	if (!comp_fct)
		comp_fct = default_cmp;
	for (node_t *n = list->head; n; n = n->next) {
		if (comp_fct(n->data, comp))
			return n->data;
	}
	return NULL;
}