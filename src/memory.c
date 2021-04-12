#include "libft.h"
#include <stdlib.h>

void free_value(void *value) {
  if (value != NULL) {
    free(value);
  }
}

void free_values(void **value) {
  while (*value != NULL) {
    free_value(*value++);
  }
}

void free_linked_list(t_list *list) {
  t_list *current;
  t_list *next;

  current = list;
  while (current != NULL) {
    free_value(current->content);
    next = current->next;
    free_value(current);
    current = next;
  }
}
