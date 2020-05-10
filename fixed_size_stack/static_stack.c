#include <stdlib.h>
#include "stack.h"

static_stack_t *create_static_stack(size_t size, size_t member_size)
{
	static_stack_t *stack = malloc(sizeof(static_stack_t));
	stack->data = calloc(size, member_size);
	stack->size = size;
	stack->member_size = member_size;
	stack->top = -1;
	return stack;
}

void destroy_static_stack(static_stack_t *stack)
{
	free(stack->data);
	free(stack);
}
