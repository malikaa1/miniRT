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
