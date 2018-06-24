/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** Fixed size stack implementation
*/

#include <stdlib.h>
#include "stack.h"

static_stack_t *create_static_stack(size_t size, size_t member_size)
{
	static_stack_t *stack = malloc(sizeof(static_stack_t));
	stack->data_array = calloc(size, member_size);
	stack->size = size;
	stack->member_size = member_size;
	stack->top_index = -1;
	return stack;
}

void destroy_static_stack(static_stack_t *stack)
{
	free(stack->data_array);
	free(stack);
}
