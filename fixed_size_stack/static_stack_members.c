#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"

void *top_s(static_stack_t *stack)
{
	return ((uint8_t *)stack->data +
		stack->top * stack->member_size);
}

bool is_empty_s(static_stack_t *stack)
{
	return (stack->top == -1);
}

bool is_full_s(static_stack_t *stack)
{
	return (stack->top == (int)stack->size - 1);
}
