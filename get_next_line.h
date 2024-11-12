/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 11:09:21 by jmeirele          #+#    #+#             */
/*   Updated: 2024/11/12 15:12:17 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

//        DEFAULT VALUE FOR BUFFER_SIZE         //
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

//             MANDATORY FUNCTIONS              //
char	*get_next_line(int fd);
char	*ft_read_to_new_line(int fd, char *storage);
char	*ft_extract_line(char *storage);
char	*ft_save_remaining(char *storage);

//                    UTILS                     //
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *s);

#endif