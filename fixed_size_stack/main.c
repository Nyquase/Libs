/*
** Main to test static stack usage
** and fonctionnalities
*/

#include <stdio.h>
#include "stack.h"

int main()
{
	static_stack_t *stack = create_static_stack(10, sizeof(int));

	push_s(stack, &(int){1});
	push_s(stack, &(int){2});
	push_s(stack, &(int){3});
	push_s(stack, &(int){4});
	push_s(stack, &(int){5});
	push_s(stack, &(int){6});
	push_s(stack, &(int){7});
	push_s(stack, &(int){8});
	push_s(stack, &(int){9});
	push_s(stack, &(int){10});

	push_s(stack, &(int){11}); // These calls will be ignored because
	push_s(stack, &(int){12}); // the stack is full

	while (!is_empty_s(stack)) {
		int *val = top_s(stack);
		printf("%d\n", *val);
		pop_s(stack);    // pop also return the poped value
	}

	destroy_static_stack(stack);
	return (0);
}
