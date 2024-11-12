/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 11:55:54 by jmeirele          #+#    #+#             */
/*   Updated: 2024/11/12 11:09:39 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
			break;
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
	if(!storage || !*storage)
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
	static char	*storage = NULL;
	char		*res;

	if (!storage)
	{
		storage = malloc(1);
		if (!storage)
			return (free(storage), NULL);
		storage[0] = '\0';
	}
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	storage = ft_read_to_new_line(fd, storage);
	res = ft_extract_line(storage);
	storage = ft_save_remaining(storage);
	return (res);
}

/* int	main(void)
{
	char	*res;
	int	fd = open("tests/test3.txt", O_RDONLY);
	// res = get_next_line(fd);
	// printf("%s", res);
	// free(res);
	while ((res = get_next_line(fd)))
	{
		printf("%s", res);
		free(res);
	}
} */
