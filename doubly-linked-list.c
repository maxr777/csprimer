#include <stdio.h>
#include <stdlib.h>

struct Dl_list {
  int value;
  struct Dl_list *previous, *next;
};

void insert_at_start(int new_value, struct Dl_list **head) {
  struct Dl_list *new_node = malloc(sizeof(struct Dl_list));
  new_node->value = new_value;
  new_node->previous = 0;
  new_node->next = *head;
  (*head)->previous = new_node;
  *head = new_node;
}

void insert_at_end(int new_value, struct Dl_list **tail) {
  struct Dl_list *new_node = malloc(sizeof(struct Dl_list));
  new_node->value = new_value;
  new_node->previous = *tail;
  new_node->next = 0;
  (*tail)->next = new_node;
  *tail = new_node;
}

int pop_at_start(struct Dl_list **head) {
  if ((*head)->next == 0) {
    perror("head is the only element, can't remove it");
    return 0;
  }
  int result = (*head)->value;
  ((*head)->next)->previous = 0;
  struct Dl_list *new_head_ptr = (*head)->next;
  free(*head);
  (*head) = new_head_ptr;
  return result;
}

int pop_at_end(struct Dl_list **tail) {
  if ((*tail)->previous == 0) {
    perror("tail is the only element, can't remove it");
    return 0;
  }
  int result = (*tail)->value;
  ((*tail)->previous)->next = 0;
  struct Dl_list *new_tail_ptr = (*tail)->previous;
  free(*tail);
  *tail = new_tail_ptr;
  return result;
}

void print_list(struct Dl_list *head) {
  struct Dl_list *temp = head;
  do {
    printf("%d\n", temp->value);
    temp = temp->next;
  } while (temp->next != 0);
  printf("%d\n", temp->value);
}

int main() {
  struct Dl_list *head = malloc(sizeof(struct Dl_list)), *tail = malloc(sizeof(struct Dl_list));

  head->value = -9;
  head->previous = 0;
  head->next = tail;

  tail->value = 5;
  tail->previous = head;
  tail->next = 0;

  insert_at_end(99, &tail);
  insert_at_start(88, &head);
  print_list(head); // 88, -9, (77), 5, 99
  printf("head: %d\ntail: %d\n", pop_at_start(&head), pop_at_end(&tail));
  print_list(head);
}
