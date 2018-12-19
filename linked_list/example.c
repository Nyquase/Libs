/*
** Example main to test linked lists
*/

#include <stdio.h>
#include "linked_list.h"

// Trivial struct representing the data each node will be holding
typedef struct {
  int id;
} info_t;

static bool cmp_func(const void *node, const void *my_info) {
  const info_t *n = node;
  const info_t *cmp_info = my_info;
  return (n->id == cmp_info->id);
}

static void print_list(const linked_list_t *list) {

  printf("--------\n");
  for (node_t *n = list->head; n; n = n->next) {
    info_t *info = n->data;
    printf("[%d]", info->id);
  }
  printf("\n--------\n");
}

int main() {
  linked_list_t list = new_list(info_t);
  // Lists should always be initialized like this
  // otherwise the behavior is undefined

  // Using compound literals to fill the linked list
  printf("Adding 5 nodes at the back...\n");
  ll_push_back(&list, &(info_t) {1});
  ll_push_back(&list, &(info_t) {2});
  ll_push_back(&list, &(info_t) {3});
  ll_push_back(&list, &(info_t) {4});
  ll_push_back(&list, &(info_t) {5}); // [1, 2, 3, 4, 5]

  printf("Adding 5 nodes at the front...\n");
  ll_push_front(&list, &(info_t) {1}); // [1, 1, 2, 3, 4, 5]
  ll_push_front(&list, &(info_t) {2});
  ll_push_front(&list, &(info_t) {3});
  ll_push_front(&list, &(info_t) {4});
  ll_push_front(&list, &(info_t) {5}); // [5, 4, 3, 2, 1, 1, 2, 3, 4, 5]

  print_list(&list);

  printf("Removing every nodes containing 1\n");
  ll_remove_if(&list, cmp_func, &(info_t) {1}); // Remove every node with id == 1
  printf("Removing first and last nodes\n");
  ll_pop_front(&list);
  ll_pop_back(&list);

  print_list(&list);

  // Manual loop when you have to remove while looping
  // This will replace every node containing 2 by a new node containing 42
  printf("Replacing every 2 by 42\n");
  node_t *node = list.head;
  while (node) {
    node_t *next = node->next; // You have to save the next in case
    // you delete the current node
    if (((info_t *) node->data)->id == 2) {
      ll_insert_after(&list, node, &(info_t) {42});
      ll_remove(&list, node);
      // You could also do this
      // ((info_t *)node->data)->id = 42;
      // but you wouldn't have learned how to remove while looping :D
    }
    node = next;
  }

  print_list(&list);

  printf("Getting first node containing 3\n");
  info_t *info = ll_get_if(&list, cmp_func, &(info_t) {3}); // This will get the first data containing 3 from the list
  printf("%d\n", info->id);

  ll_destroy(&list);
  return (0);
}
