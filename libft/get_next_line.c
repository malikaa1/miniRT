/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmani <mrahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 17:21:53 by mrahmani          #+#    #+#             */
/*   Updated: 2021/04/05 18:40:41 by mrahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *find_line(char *old_str, int *index, char **str) {
  char *line;

  line = ft_substr(old_str, 0, *index);
  *str = ft_substr(old_str, *index + 1, ft_strlen(old_str) - *index - 1);
  free(old_str);
  *index = *index + 1;
  return (line);
}

char *extract_line(char **str, int eof, int *last_line) {
  int index;
  char *old_str;

  index = 0;
  old_str = *str;
  *last_line = 0;
  while (old_str && old_str[index] != '\0') {
    if (old_str[index] == '\n')
      return (find_line(old_str, &index, str));
    index++;
  }
  if (index >= 0) {
    if (eof == 1)
      *last_line = 1;
    return (ft_substr(*str, 0, index));
  }
  return (NULL);
}

char *ft_read(int bytes, char buff[], char *str) {
  char *val;
  char *new_str;

  if (bytes > BUFFER_SIZE || bytes < 0)
    return (NULL);
  if (bytes > 0) {
    buff[bytes] = '\0';
    val = ft_substr(buff, 0, bytes);
    new_str = ft_strjoin(str, val);
    free(str);
    free(val);
    str = new_str;
  }
  return (str);
}

char *read_line(int fd, int *eof) {
  char *str;
  int bytes;
  char buff[BUFFER_SIZE + 1];

  *eof = 0;
  str = ft_strdup("");
  bytes = 1;
  while (ft_strchr(str, '\n') == NULL && bytes > 0) {
    bytes = read(fd, buff, BUFFER_SIZE);
    str = ft_read(bytes, buff, str);
    if (str == NULL) {
      *eof = -2;
      return (NULL);
    }
  }
  if (bytes == 0)
    *eof = 1;
  return (str);
}

int get_next_line(int fd, char **line) {
  static char *str;
  int eof;
  char *new_line;
  int last_line;
  char *old_str;

  if (fd < 0 || line == NULL || BUFFER_SIZE <= 0)
    return (-1);
  if (str == NULL)
    str = ft_strdup("");
  new_line = read_line(fd, &eof);
  if (eof == -2)
    return (-1);
  old_str = str;
  str = ft_strjoin(old_str, new_line);
  free(new_line);
  free(old_str);
  *line = extract_line(&str, eof, &last_line);
  if (last_line == 0)
    return (1);
  free(str);
  str = NULL;
  return (0);
}
