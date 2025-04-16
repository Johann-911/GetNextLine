/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoumani <jtoumani@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 17:10:28 by jtoumani          #+#    #+#             */
/*   Updated: 2025/04/16 17:48:31 by jtoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdarg.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

# ifndef	BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

int build_line(char **line, char *buffer);
void read_file(char *buffer, int fd);
char	*get_next_line(int fd);
void update_buffer(char *buffer);
size_t	ft_strlen(char *str);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
void	*ft_calloc(size_t count, size_t size);



#endif