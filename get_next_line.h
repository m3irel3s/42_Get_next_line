/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 11:09:21 by jmeirele          #+#    #+#             */
/*   Updated: 2024/11/08 15:53:15 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FT_GET_NEXT_LINE_H
# define FT_GET_NEXT_LINE_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

//        DEFAULT VALUE FOR BUFFER_SIZE         //
# ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
# endif

//             MANDATORY FUNCTIONS              //
char	*get_next_line(int fd);

//                    UTILS                     //
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *str);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_read_to_newline(int fd, char *storage);
char	*ft_extract_line(char *storage);
char	*ft_save_remaining(char *storage);



# endif