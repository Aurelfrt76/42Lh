/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afromont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 09:02:17 by afromont          #+#    #+#             */
/*   Updated: 2023/11/22 11:40:42 by afromont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42

# endif

char	*get_next_line(int fd);

char	*ft_strjoin(char *s1, char *s2);

char	*ft_strchr(char *buffer, int c);

char	*ft_getline(char *stack);

char	*ft_extract(char *stack);

char	*ft_read(int fd, char *stack);

size_t	ft_strlen(char *src);
#endif
