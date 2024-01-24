/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afromont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:33:05 by afromont          #+#    #+#             */
/*   Updated: 2024/01/23 12:10:37 by afromont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# define INT_MAX	2147483647
# define INT_MIN	-2147483648

typedef struct s_count
{
	int	i;
	int	j;
}	t_count;

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}	t_stack;

/* ****************** stack ******************** */

t_stack	*new_stack(void);

t_stack	*push_stack(t_stack *st, int n);

t_stack	*clear_stack(t_stack *st);

void	print_stack(t_stack *st);

int		is_empty_stack(t_stack *st);

/* ************** stack_inst ****************** */
void	st_swap(t_stack **st, char stp);

void	st_push(t_stack **std, t_stack **sts, char stp);

void	st_rotate(t_stack **st, char stp);

void	st_rev_rotate(t_stack **st, char stp);

/* ************** utils ************ */

void	ftgesterror(int argc, char *argv[]);

void	exit_with_error(const char *err_msg);

long	ft_atoi(const char *str);

/* **************** algo ******************* */

void	two_args(t_stack **st);

void	three_args(t_stack **st);

void	four_args(t_stack **sta, t_stack **stb);

void	five_args(t_stack **sta, t_stack **stb);

void	radx(t_stack **sta, t_stack **stb);

void	select_push(t_stack **sta, t_stack **stb, int num);

int		is_bigger_than_stack(int value, t_stack *st);

int		is_best_option(int va, int vb, t_stack *st);

int		is_sorted(t_stack *st);

int		stlen(t_stack *st, int i);

#endif
