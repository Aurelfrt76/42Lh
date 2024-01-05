#include "utils.h"
int	dbarg(t_stack lst)
{
	t_stack *tmp;

	tmp = lst;
	while (lst->data != NULL)
	{
		if (lst->value != lst->next->value)
			lst = lst->next;
		else 
			return (1);
	}
	lst = tmp;
	return (0);
}

int	stackaistried(t_stack lst)
{
	t_stack tmp;

	tmp = lst;
	while (lst->data != NULL)
	{
		if (lst->value < lst->next->value)
			lst = lst->next;
		else 
			return (1);
	}
	lst = tmp;
	return (0);
}
