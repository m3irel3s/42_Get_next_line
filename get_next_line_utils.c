/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:10:27 by jmeirele          #+#    #+#             */
/*   Updated: 2024/11/07 16:51:11 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;
	size_t	j;
	char	*full_str;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	full_str = malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!full_str)
		return (NULL);
	i = 0;
	while (i < s1_len)
	{
		full_str[i] = s1[i];
		i++;
	}
	j = 0;
	while (i < (s2_len + s1_len))
		full_str[i++] = s2[j++];
	full_str[i] = '\0';
	free(s1);
	return (full_str);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	alloc_space;

	alloc_space = nmemb * size;
	ptr = malloc(alloc_space);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, alloc_space);
	return (ptr);
}
void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*p;

	i = 0;
	p = s;
	while (i < n)
		p[i++] = '\0';
}