#include <stdio.h>
int handle_error(char *message) {
  printf("Error : %s", message);
  return -1;
}