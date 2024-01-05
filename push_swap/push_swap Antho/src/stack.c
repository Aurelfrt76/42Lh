#include <stdlib.h>
#include "error_management.h"
#include "stack.h"
#include "utils.h"
#include "../LIB/ft_printf.h"

t_stack	*new_stack(void)
{
	return (NULL);
}

int		is_empty_stack(t_stack *st)
{
	if (!st)
		return (1);
	return (0);
}

void	print_stack(t_stack *st)
{
	if (is_empty_stack(st))
	{
		ft_printf("Stack is empty");
		return ;
	}
	while(!is_empty_stack(st))
	{
		ft_printf("[%d]\n", st->value);
		st = st->next;
	}
}

t_stack	*push_stack(t_stack *st, int n)
{
	t_stack	*new_el;
	
	new_el = malloc(sizeof(t_stack));
	if (!new_el)
		exit_with_error("Allocation Failure !");
	new_el->value = n;
	new_el->next = st;
	return (new_el);
}

t_stack	*clear_stack(t_stack *st)
{
	t_stack	*buff;
	
	if (is_empty_stack(st))
		return (new_stack());
	buff = st->next;
	free(st);
	return (clear_stack(buff));
}