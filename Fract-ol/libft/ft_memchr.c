/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afromont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 14:26:21 by afromont          #+#    #+#             */
/*   Updated: 2023/10/23 10:30:58 by afromont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*result;

	result = (char *)s;
	while (n > 0)
	{
		if (*result == (char)c)
			return (result);
		result++;
		n--;
	}
	return (NULL);
}
/*
int	main(void)
{
	char buffer[80];
	char* where;
	strcpy( buffer, "video x-rays" );
	where = (char *) ft_memchr( buffer, 'x', 6 );
	if( where == NULL )
		printf( "'x' not found\n" );
	else 
		printf( "%s\n", where );
	where = (char *) ft_memchr( buffer, 'r', 9 );
    	if( where == NULL )
		printf( "'r' not found\n" );
	else
		printf( "%s\n", where );
	return(0);
}
*/
