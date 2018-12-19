#include <stdlib.h>
#include <string.h>
#include "linked_list.h"


static node_t *create_node(const void *data, size_t data_size)
{
  node_t *new = calloc(sizeof(node_t), 1);

  if (!new)
    return NULL;
  new->data = malloc(data_size);
  if (!new->data)
    return NULL;
  memcpy(new->data, data, data_size);
  return new;
}

bool ll_push_back(linked_list_t *list, const void *data)
{
  node_t *new = create_node(data, list->msize);

  if (!new)
    return false;
  if (!list->tail) {
    list->tail = new;
    list->head = new;
  } else {
    new->prev = list->tail;
    list->tail->next = new;
    list->tail = new;
  }
  list->size++;
  return true;
}

bool ll_push_front(linked_list_t *list, const void *data)
{
  node_t *new = create_node(data, list->msize);

  if (!new)
    return false;
  if (!list->head) {
    list->head = new;
    list->tail = new;
  } else {
    new->next = list->head;
    list->head->prev = new;
    list->head = new;
  }
  list->size++;
  return true;
}

bool ll_insert_after(linked_list_t *list, node_t *node, const void *data) {
  if (node == list->tail)
    return ll_push_back(list, data);

  node_t *new = create_node(data, list->msize);

  if (!new)
    return false;
  node->next->prev = new;
  new->next = node->next;
  new->prev = node;
  node->next = new;
  list->size++;
  return true;
}

bool ll_insert_before(linked_list_t *list, node_t *node, const void *data)
{
  if (node == list->head)
    return ll_push_front(list, data);

  node_t *new = create_node(data, list->msize);

  if (!new)
    return false;
  node->prev->next = new;
  new->prev = node->prev;
  new->next = node;
  node->prev = new;
  list->size++;
  return true;
}
