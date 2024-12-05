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

#include "../inc/get_next_line_bonus.h"

/**
 * @brief Reads from a file descriptor until a newline character is found.
 * The read characters are stored in the storage string.
 * If the end of the file is reached, the storage string is returned.
 * If there is an error, the function returns NULL.
 *
 * @param fd the file descriptor to read from
 * @param storage the string where the read characters will be stored
 * @return the updated storage string or NULL if there is an error
 */
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

/**
 * @brief Extracts the line from the storage string.
 * The line is stored in a new string and the storage string is updated.
 * If there is no line, the function returns NULL.
 *
 * @param storage the string where the line will be extracted
 * @return the extracted line or NULL if there is no line
 */
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

/**
 * @brief Saves the remaining characters after the line break in a new string.
 * The original storage string is freed and the function returns the new string.
 * If there is no line break, the function returns NULL and frees the 
 * storage string.
 *
 * @param storage the string where the remaining characters will be saved
 * @return the new string containing the remaining characters or NULL if there
 * is no line break
 */
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

/**
 * @brief Reads a line from a file descriptor and returns it.
 *
 * The function reads from the file descriptor until it finds a line break or
 * reaches the end of the file. The line is stored in a new string and the
 * remaining characters are saved for the next call.
 *
 * The function can read from different file descriptors, not just one.
 * The static variable `storage` is an array of strings, each one is associated
 * with a file descriptor. When the function is called with a new file 
 * descriptor, it checks if the string associated with that file descriptor is 
 * NULL, and if so, it allocates memory for it.
 * 
 *
 * @param fd the file descriptor to read from
 * @return the line read from the file descriptor or NULL if an error occurred
 */
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
