#include <string.h>
#include "stack.h"

void push_s(static_stack_t *stack, const void *data)
{
	if (is_full_s(stack))
		return;
	++stack->top;
	memcpy((uint8_t *)stack->data +
	       stack->top * stack->member_size,
	       data, stack->member_size);
}

void *pop_s(static_stack_t *stack)
{
	if (is_empty_s(stack))
		return NULL;
	return ((uint8_t *)stack->data +
		stack->member_size * stack->top--);
}
