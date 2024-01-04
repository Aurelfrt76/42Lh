/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afromont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 10:27:52 by afromont          #+#    #+#             */
/*   Updated: 2023/12/01 15:27:57 by afromont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *src)
{
	size_t	i;

	i = 0;
	/*if (!src)
		return (0);*/
	while (src[i])
		i++;
	return (i);
}

char	*ft_getline(char *stack)
{
	char	*line;
	int		i;

	i = 0;
	if (!stack[i])
		return (NULL);
	while (stack[i] && stack[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (stack[i] && stack[i] != '\n')
	{
		line[i] = stack[i];
		i++;
	}
	if (stack[i] == '\n')
	{
		line[i] = stack[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*temp;
	int		i;
	int		j;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	temp = malloc(((ft_strlen(s1) + ft_strlen(s2) + 1)) * sizeof(char));
	if (!temp)
		return (NULL);
	i = -1;
	j = 0;
	if (s1)
		while (s1[++i] != '\0')
			temp[i] = s1[i];
	while (s2[j] != '\0')
		temp[i++] = s2[j++];
	temp[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free(s1);
	return (temp);
}

char	*ft_strchr(char *src, int c)
{
	int	i;

	i = 0;
	if (!src)
		return (0);
	while (src[i])
	{
		if (src[i] == (char) c)
			return ((char *)&src[i]);
		i++;
	}
	return (0);
}

char	*ft_extract(char *stack)
{
	char	*temp;
	int		i;
	int		j;

	i = 0;
	while (stack[i] && stack[i] != '\n')
		i++;
	if (!stack[i])
	{
		free(stack);
		return (NULL);
	}
	temp = (char *)malloc((ft_strlen(stack) - i + 1) * sizeof(char));
	if (!temp)
		return (NULL);
	i++;
	j = 0;
	while (stack[i])
		temp[j++] = stack[i++];
	temp[j] = '\0';
	free(stack);
	return (temp);
}
