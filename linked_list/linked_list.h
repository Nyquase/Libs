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

typedef struct node_s {
    void *data;
    struct node_s *next;
    struct node_s *prev;
} node_t;

/*
** A linked list should be zero-initialized
*/
typedef struct {
    node_t *head;
    node_t *tail;
    size_t size;
} linked_list_t;

typedef bool(*compare_func_t)(const void *node_data, const void *compare_data);

// Destroy (free) the list
// In case you have some dynamically allocated data in the list,
// you should not call this function and destroy it yourself
void ll_destroy(linked_list_t *list);

// Access
void *ll_get_if(linked_list_t *list, compare_func_t, const void *comp);

// Add
bool ll_insert_after(linked_list_t *list, node_t *node,
		     const void *data, size_t dataSize);
bool ll_insert_before(linked_list_t *list, node_t *node,
		      const void *data, size_t dataSize);
bool ll_push_back(linked_list_t *list, const void *data, size_t dataSize);
bool ll_push_front(linked_list_t *list, const void *data, size_t dataSize);

// Remove
void ll_remove(linked_list_t *list, node_t *node);
void ll_remove_if(linked_list_t *list, compare_func_t, const void *comp);
void ll_pop_front(linked_list_t *list);
void ll_pop_back(linked_list_t *list);
