/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:16:57 by jmeirele          #+#    #+#             */
/*   Updated: 2024/11/12 15:16:16 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_read_to_new_line(int fd, char *storage)
{
	ssize_t	bytes_read;
	char	*temp;

	bytes_read = 1;
	temp = malloc(BUFFER_SIZE + 1);
	if (!temp)
		return (NULL);
	while (bytes_read > 0 && !ft_strchr(storage, '\n'))
	{
		bytes_read = read(fd, temp, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(temp), free(storage), NULL);
		if (bytes_read == 0)
			break ;
		temp[bytes_read] = '\0';
		storage = ft_strjoin(storage, temp);
	}
	free(temp);
	return (storage);
}

char	*ft_extract_line(char *storage)
{
	char	*temp;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!storage || !*storage)
		return (NULL);
	while (storage[i] != '\n' && storage[i])
		i++;
	temp = malloc(i + 2 * sizeof(char));
	if (!temp)
		return (NULL);
	while (j < i + 1)
	{
		temp[j] = storage[j];
		j++;
	}
	temp[j] = '\0';
	return (temp);
}

char	*ft_save_remaining(char *storage)
{
	char	*to_save;
	size_t	len;

	len = 0;
	if (!storage)
		return (NULL);
	while (storage[len] && storage[len] != '\n')
		len++;
	if (!storage[len])
		return (free(storage), NULL);
	to_save = ft_strdup(storage + len + 1);
	free(storage);
	return (to_save);
}

char	*get_next_line(int fd)
{
	static char	*storage[1024];
	char		*res;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!storage[fd])
	{
		storage[fd] = malloc(1);
		if (!storage[fd])
			return (free(storage[fd]), NULL);
		storage[fd][0] = '\0';
	}
	storage[fd] = ft_read_to_new_line(fd, storage[fd]);
	res = ft_extract_line(storage[fd]);
	storage[fd] = ft_save_remaining(storage[fd]);
	return (res);
}
