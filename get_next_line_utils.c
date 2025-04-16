/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoumani <jtoumani@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 13:18:25 by jtoumani          #+#    #+#             */
/*   Updated: 2025/04/15 18:03:30 by jtoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	int	a;

	a = 0;
	if(str == NULL)
		return 0;
	while (str[a] != '\0')
	{
		if(str[a] == '\n')
			return a +1;
		a++;	
	}
	return (a);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*strjoin;
	int		i;
	int		j;
	
	i = 0;
	j = 0;
	if(!s1 && !s2)
		return NULL;
	strjoin = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (strjoin == NULL)
		return (NULL);
	while (s1 != NULL && s1[i] != '\0')
	strjoin[j++] = s1[i++];
	i = 0;
	while (s2[i] != '\0')
	{
		strjoin[j++] = s2[i++];
		if(strjoin[i - 1] == '\n')
			break;
	}
	strjoin[j] = '\0';
	return (strjoin);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned char	chr;
	
	chr = c;
	while (*s)
	{
		if (*s == chr)
		return ((char *)s);
		s++;
	}
	if (chr == '\0')
	return ((char *)s);
	return (NULL);
}

// size_t	ft_strlcpy(char *dst, char *src, size_t size)
// {
// 	size_t	i;

// 	i = 0;
// 	if (size == 0)
// 		return (ft_strlen(src));
// 	while (src[i] != '\0' && i < size - 1)
// 	{
// 		dst[i] = src[i];
// 		i++;
// 	}
// 	dst[i] = '\0';
// 	return (ft_strlen(src));
// }

// char	*ft_substr(char *s, unsigned int start, size_t len)
// {
// 	char	*substr;
// 	size_t	i;

// 	i = 0;
// 	if (s == NULL)
// 		return (NULL);
// 	if (start >= ft_strlen(s))
// 	{
// 		substr = (char *)malloc(sizeof(char) * (1));
// 		if (substr == NULL)
// 			return (NULL);
// 		*substr = '\0';
// 		return (substr);
// 	}
// 	if (len > ft_strlen(s) - start)
// 		len = ft_strlen(s) - start;
// 	substr = (char *)malloc(sizeof(char) * (len + 1));
// 	if (substr == NULL)
// 		return (NULL);
// 	while (s[i] != '\0' && i < len)
// 		substr[i++] = s[start++];
// 	substr[i] = '\0';
// 	return (substr);
// }
// char	*ft_strdup(const char *s1)
// {
	// 	char	*dupe;
	// 	int		i;
	
	// 	i = 0;
	// 	if(!s1)
	// 		return NULL;
	// 	while (s1[i])
	// 		i++;
	// 	dupe = (char *)malloc((i + 1) * sizeof(char));
	// 	if (!dupe)
	// 		return (NULL);
	// 	i = 0;
// 	while (s1[i] != '\0')
// 	{
// 		dupe[i] = s1[i];
// 		i++;
// 	}
// 	dupe[i] = '\0';
// 	return (dupe);
// }
// void	*ft_calloc(size_t count, size_t size)
// {
// 	void	*ptr;
// 	size_t	i;

// 	i = 0;
// 	ptr = malloc(count * size);
// 	if (ptr == NULL)
// 		return (NULL);
// 	while (i < (size * count))
// 	{
// 		((char *)ptr)[i] = '\0';
// 		i++;
// 	}
// 	return (ptr);
// }
