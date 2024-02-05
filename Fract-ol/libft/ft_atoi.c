/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afromont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 09:02:29 by afromont          #+#    #+#             */
/*   Updated: 2023/10/23 09:28:22 by afromont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *ptr)
{
	int	j;
	int	i;
	int	k;

	j = 0;
	i = 1;
	k = 0;
	while ((*ptr >= 9 && *ptr <= 13) || *ptr == 32)
		ptr++;
	if (*ptr == '-')
		i = -1;
	while (*ptr == '+' || *ptr == '-')
	{
		ptr++;
		j++;
	}
	if (j >= 2)
		return (0);
	while (*ptr >= 48 && *ptr <= 57)
	{
		k = k * 10 + (*ptr - '0');
		ptr++;
	}
	return (k * i);
}
/*
int main (void)
{
  printf("%d", ft_atoi("    -1245qwerwqe"));
  return (0);
}
*/
