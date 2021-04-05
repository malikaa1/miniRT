/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmani <mrahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 17:41:12 by mrahmani          #+#    #+#             */
/*   Updated: 2021/04/04 23:13:11 by mrahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_strncmp(const char *s1, const char *s2, size_t n) {
  while (n != 0) {
    if (*s1 != *s2++)
      return (*(unsigned char *)s1 - *(unsigned char *)(s2 - 1));
    if (*s1++ == '\0')
      break;
    n--;
  }
  return (0);
}

int ft_strcmp(const char *s1, const char *s2) {

  int n;
  n = ft_strlen(s1);
  while (n != 0) {
    if (*s1 != *s2++)
      return (*(unsigned char *)s1 - *(unsigned char *)(s2 - 1));
    if (*s1++ == '\0')
      break;
    n--;
  }
  return (0);
}
