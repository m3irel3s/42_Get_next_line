/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:10:27 by jmeirele          #+#    #+#             */
/*   Updated: 2024/11/12 11:17:48 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/get_next_line.h"

/**
 * @brief Locates the first occurrence of a character in a string.
 * 
 * @param s The string to be searched.
 * @param c The character to locate.
 * 
 * @return A pointer to the first occurrence of the character in the string,
 *         or NULL if the character is not found. If the character is '\0',
 *         the function returns a pointer to the null terminator of the string.
 */
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

/**
 * @brief Allocates (with malloc(3)) and returns a new string,
 *        which is the result of the concatenation of 's1' and 's2'.
 * 
 * @param s1 The prefix string.
 * @param s2 The suffix string.
 * 
 * @return The new string. NULL if the allocation fails.
 */
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

/**
 * @brief Calculates the length of a string.
 * 
 * @param str The string.
 * 
 * @return The length of the string.
 */
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

/**
 * @brief Creates a duplicate of a string.
 * 
 * Allocates memory for a string and copies the string s into it.
 * 
 * @param s The string to duplicate.
 * 
 * @return The duplicated string.
 */
char	*ft_strdup(const char *s)
{
	size_t	len;
	size_t	i;
	char	*p;

	i = 0;
	len = ft_strlen(s);
	p = malloc(sizeof(char) * (len + 1));
	if (p == NULL)
		return (NULL);
	while (s[i])
	{
		p[i] = s[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}
