/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmani <mrahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 23:42:59 by mrahmani          #+#    #+#             */
/*   Updated: 2021/04/10 22:03:47 by mrahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_substr(char const *s, unsigned int start, size_t len) {
  char *ptr;
  size_t i;

  i = 0;
  if (s == NULL)
    return (NULL);
  if (start > ft_strlen(s))
    return (ft_strdup(""));
  ptr = malloc(sizeof(*ptr) * (len + 1));
  if (ptr == NULL)
    return (NULL);
  while (i < len) {
    ptr[i] = s[start + i];
    i++;
  }
  ptr[i] = '\0';
  return (ptr);
}
