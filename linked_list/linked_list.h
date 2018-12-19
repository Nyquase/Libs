#pragma once

#include <stddef.h>
#include <stdbool.h>

typedef struct node_s node_t;
struct node_s {
  void *data;
  node_t *next;
  node_t *prev;
};

/*
** A linked list should be initialized like that :
** linked_list_t list = {0};
** Never directly touch these fields
*/
typedef struct {
  node_t *head;
  node_t *tail;
  size_t size;
  size_t msize;
} linked_list_t;

#define new_list(type) { .msize = sizeof(type) }

typedef bool(*compare_func_t)(const void *node_data, const void *compare_data);

// Destroy (free) the list
// In case you have some dynamically allocated data in the list,
// you should not call this function and destroy it yourself
void ll_destroy(linked_list_t *list);

// Access
void *ll_get_if(linked_list_t *list, compare_func_t, const void *comp);

// Add
// Every adding function will make a deep copy of the data
bool ll_insert_after(linked_list_t *list, node_t *node, const void *data);
bool ll_insert_before(linked_list_t *list, node_t *node, const void *data);
bool ll_push_back(linked_list_t *list, const void *data);
bool ll_push_front(linked_list_t *list, const void *data);

// Remove
void ll_remove(linked_list_t *list, node_t *node);
void ll_remove_if(linked_list_t *list, compare_func_t, const void *comp);
void ll_pop_front(linked_list_t *list);
void ll_pop_back(linked_list_t *list);
