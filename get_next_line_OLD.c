/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_OLD.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoumani <jtoumani@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 18:01:03 by jtoumani          #+#    #+#             */
/*   Updated: 2025/04/14 18:37:06 by jtoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*update_bufer(char *buffer)
{
	char	*new_buffer;
	int		i;
	int		buff_len;

	i = 0;
	buff_len = ft_strlen(buffer);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	if (i >= buff_len)
	{
		free(buffer);
		return (NULL);
	}
	new_buffer = ft_substr(buffer, i, buff_len - i);
	free(buffer);
	return (new_buffer);
	
}

char	*build_line(char *buffer)
{
	char	*line;
	int		i;

	if (!buffer)
		return (NULL);
	i = 0;
	while (buffer[i] != '\n' && buffer[i])
		i++;
	if (buffer[i] == '\n')
		i++;
	line = ft_substr(buffer, 0, i);
	return (line);
}

char	*read_file(char *buffer, int fd)
{
	int		bytes_read;
	char	*temp;
	char	*new_buffer;

	if (!buffer)
		buffer = ft_strdup("");
	temp = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp)
		return (NULL);
	bytes_read = read(fd, temp, BUFFER_SIZE);
	while (!ft_strchr(buffer, '\n') && bytes_read > 0)
	{
		if (bytes_read < 0)
		{
			free(buffer);
			return (free(temp), NULL);
		}
		temp[bytes_read] = '\0';
		new_buffer = ft_strjoin(buffer, temp);
		free(buffer);
		buffer = new_buffer;
		bytes_read = read(fd, temp, BUFFER_SIZE);
	}
	free(temp);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return NULL;
	buffer = read_file(buffer, fd);
	if (!buffer)
		return (NULL);
	line = build_line(buffer);
	if (!line)
		return (NULL);
	buffer = update_bufer(buffer);
	if (line[0] == '\0')
	{
		free(line);
		return (NULL);
	}
	return (line);
}
