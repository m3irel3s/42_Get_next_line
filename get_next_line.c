/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 11:55:54 by jmeirele          #+#    #+#             */
/*   Updated: 2024/11/07 17:32:31 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_search_new_line(int fd, char *str)
{
	char	*temp;
	temp = malloc(1);

	temp[0] = '\0';
	while (read(fd, str, BUFFER_SIZE) > 0)
	{
		if (ft_strchr(str, '\n'))
			
		temp = ft_strjoin(temp, str);
	}
	return (temp);
}
char	*get_next_line(int fd)
{
	static char	*storage;
	char		*res;

	storage = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	if (!storage)
		return (NULL);
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	res = ft_search_new_line(fd, storage);
	free(storage);
	return (res);
}

/* int	main(void)
{
	char	*res;
	int	fd = open("tests/test3.txt", O_RDONLY);
	res = get_next_line(fd);
	printf("%s", res);
	free(res);
}
*/