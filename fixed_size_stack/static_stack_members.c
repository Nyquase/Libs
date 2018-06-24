/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** Fixed size stack implementation
*/

#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"

void *top_s(static_stack_t *stack)
{
	return ((uint8_t *)stack->data_array +
		stack->top_index * stack->member_size);
}

bool is_empty_s(static_stack_t *stack)
{
	return (stack->top_index == -1);
}

bool is_full_s(static_stack_t *stack)
{
	return (stack->top_index == (int)stack->size - 1);
}
