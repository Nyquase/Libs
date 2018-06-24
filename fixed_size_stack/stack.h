/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** who cares
*/

#pragma once

#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>

typedef struct {
    int top_index;
    size_t size;
    size_t member_size;
    void *data_array;
} static_stack_t;

static_stack_t *create_static_stack(size_t size, size_t member_size);
void destroy_static_stack(static_stack_t *stack);
void push_s(static_stack_t *stack, const void *data);
void *pop_s(static_stack_t *stack);
void *top_s(static_stack_t *stack);
bool is_empty_s(static_stack_t *stack);
bool is_full_s(static_stack_t *stack);
