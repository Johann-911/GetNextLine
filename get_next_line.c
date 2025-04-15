/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoumani <jtoumani@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:49:57 by jtoumani          #+#    #+#             */
/*   Updated: 2025/04/15 13:00:36 by jtoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


void update_buffer(char *buffer)
{
    int     i;
    int j;
    j = 0;
    i = 0;

    while (buffer[i] && buffer[i] != '\n')
        i++;
    if (buffer[i] == '\n')
    {
        i++; 
        while(buffer[i])
            buffer[j++] = buffer[i++];
    }
    else
    {
        buffer[0] = '\0';
        return;
    }
    while (j <= BUFFER_SIZE)
        buffer[j++] = '\0';
}

int build_line(char **line, char *buffer)
{
    char *temp;
    int i;

    i = 0;    
    temp = ft_strjoin(*line, buffer);
    free(*line);
    if (!temp)
        return (-1);
    *line = temp;
    if (*line == NULL) 
        return (-1);
    while ((*line)[i] != '\0')
    {
        if ((*line)[i] == '\n') 
            return 1;
        i++;
    }
    return 0;
}
char    *get_next_line(int fd)
{
    static char buffer[BUFFER_SIZE + 1];
    char        *line;
    int         bytes_read;
    int         ready;
    
    line = NULL;
    if (fd < 0 || BUFFER_SIZE <= 0)
        return NULL;
    while (1)
    {
        if(buffer [0] == '\0')
        {
            bytes_read = read(fd, buffer, BUFFER_SIZE);
			if (bytes_read == -1)
				return (free(line), NULL);
			if (bytes_read == 0)
				return (line);        
        }    
        ready = build_line(&line, buffer);
        update_buffer(buffer);
        if (ready == 1)
            return (line);
        if (ready == -1)
            return NULL;
    }
}

// #include <fcntl.h>
// int main(void)
// {
//     int     fd;
//     char    *line;

//     fd = open("test.txt", O_RDONLY);
//     if (fd < 0)
//     {
//         perror("Fehler beim Öffnen der Datei");
//         return (1);
//     }

//     while ((line = get_next_line(fd)) != NULL)
//     {
//         printf("Line: %s", line);
//         free(line);
//     }

//     close(fd);
//     return (0);
// }
// void    read_file(char *buffer, int fd)
// {
//     int     bytes_read;
//     bytes_read = read(fd, buffer, BUFFER_SIZE);
// }

// char    *read_file(char *buffer, int fd)
// {
        //     int     bytes_read;
        //     char    *temp;
        //     char    *new_buffer;
        //     if (!buffer)
        //         buffer = ft_strdup("");
        //     temp = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
        //     if (!temp)
        //         return (NULL);
        //     bytes_read = 1;
        //     while (!ft_strrchr(buffer, '\n') && bytes_read > 0)
        //     {
        //         bytes_read = read(fd, temp, BUFFER_SIZE);
        //         if (bytes_read < 0)
        //         {
        //             free(buffer);
        //             return (free(temp), NULL);
        //         }
        //         temp[bytes_read] = '\0';
        //         new_buffer = ft_strjoin(buffer, temp);
        //         free(buffer);
        //         buffer = new_buffer;
        //     }
        //     free(temp);
        //     return (buffer);
        // }//new
        // #include <fcntl.h>// int  main(void)
        // {
            //  int     fd;
            //  char    *line;//  fd = open("empty.txt", O_RDONLY);
            //  line = get_next_line(fd);
            //  printf("%s", line);
            //  free(line);
            //  // line = get_next_line(fd);
            //  // printf("%s", line);
            //  // free(line);
            //  // line = get_next_line(fd);
            //  // printf("%s", line);
//  // free(line);
//  close(fd);
//  return (0);
// }abcd\nefghi
// abcd\nef
// abcd\n
// efef\0\0\0\0\0\0ef\0\0\0\0