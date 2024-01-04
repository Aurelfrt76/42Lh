/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afromont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 08:59:33 by afromont          #+#    #+#             */
/*   Updated: 2023/12/01 15:28:19 by afromont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(int fd, char *stack)
{
	int		j;
	char	*buff;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	j = 1;
	while (!ft_strchr(stack, '\n') && j != 0)
	{
		j = read(fd, buff, BUFFER_SIZE);
		if (j == -1)
		{
			free(stack);
			free(buff);
			return (NULL);
		}
		buff[j] = '\0';
		stack = ft_strjoin(stack, buff);
	}
	free (buff);
	return (stack);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stack;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	stack = ft_read(fd, stack);
	if (!stack)
		return (NULL);
	line = ft_getline(stack);
	stack = ft_extract(stack);
	return (line);
}
/*
int	main(void)
{
	int	fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);

	if (fd == -1)
	{
		perror("Error opening file");
		return (1);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s\n", line);
		free(line);
	}
	close(fd);
	return 0;
}*/
