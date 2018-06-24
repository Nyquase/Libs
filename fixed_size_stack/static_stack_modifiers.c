/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** Fixed size stack implementation
*/

#include <string.h>
#include "stack.h"

void push_s(static_stack_t *stack, const void *data)
{
	if (is_full_s(stack))
		return;
	++stack->top_index;
	memcpy((uint8_t *)stack->data_array +
	       stack->top_index * stack->member_size,
	       data, stack->member_size);
}

void *pop_s(static_stack_t *stack)
{
	if (is_empty_s(stack))
		return NULL;
	return ((uint8_t *)stack->data_array +
		stack->member_size * stack->top_index--);
}