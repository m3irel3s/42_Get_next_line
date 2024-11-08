/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 11:55:54 by jmeirele          #+#    #+#             */
/*   Updated: 2024/11/08 16:34:55 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_to_new_line(int fd, char *storage)
{
	ssize_t	bytes_read;
	char	*temp;

	temp = malloc(1);
	temp[0] = '\0';
	bytes_read = 1;
	while ((bytes_read) && (!ft_strchr(storage, '\n')))
	{
		bytes_read = read(fd, storage, BUFFER_SIZE);
		if (!bytes_read)
		{
			free(storage);
			free(temp);
			return (NULL);
		}
		temp = ft_strjoin(temp, storage);
	}
	return (temp);
}

char	*ft_extract_line(char *storage)
{
	char	*temp;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (storage[i] != '\n')
		i++;
	temp = ft_calloc(i + 1, sizeof(char));
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

	to_save = ft_strchr(storage, '\n');
	return (to_save);
}

char	*get_next_line(int fd)
{
	static char	*storage;
	char		*read;
	char		*res;

	res = malloc(1);
	res[0] = '\0';
	storage = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	if (!storage)
		return (NULL);
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	read = ft_read_to_new_line(fd, storage);
	ft_save_remaining(read);
	res = ft_extract_line(read);
	return (res);
}

int	main(void)
{
	char	*res;
	char	*res1;
	int	fd = open("tests/test3.txt", O_RDONLY);
	res = get_next_line(fd);
	// res1 = get_next_line(fd);
	printf("%s", res);
	// printf("%s", res1);
	free(res);
	// free(res1);
}
