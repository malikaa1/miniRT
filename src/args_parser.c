#include "libft.h"
#include "minirt.h"
#include <stdio.h>

int is_valid_file_extension(char *file_name) {
  char *extension;
  extension = ft_substr(file_name, ft_strlen(file_name) - 3, 3);
  if (ft_strncmp(extension, ".rt", 3) == 0) {
    if (extension != NULL) {
      free(extension);
    }
    return 1;
  }
  return 0;
}

int parse_args(int argc, char **argv, t_minirt *minirt) {
  char *error_msg;
  error_msg = "Usage : ./miniRT {scene.rt} [--save]";
  if (argc < 2 || argc > 4) {
    printf("%s", error_msg);
    return -1;
  }

  if (argc >= 2) {
    minirt->scene_file = argv[1];
    if (is_valid_file_extension(minirt->scene_file) == 0) {
      printf("wrong file extension\n");
      printf("%s\n", error_msg);
      return -1;
    }
    printf("%s\n", minirt->scene_file);
  }

  if (argc > 2) {
    if (ft_strncmp(argv[2], "--save", ft_strlen("--save")) != 0) {
      printf("Invalid argument %s\n", argv[2]);
      printf("%s\n", error_msg);
      return -1;
    } else {
      minirt->save = 1;
    }
  }
  return 1;
}
