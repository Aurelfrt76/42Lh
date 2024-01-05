#ifndef STACK_H
# define STACK_H

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}	t_stack;

t_stack	*new_stack(void);
t_stack	*push_stack(t_stack *st, int n);
t_stack	*clear_stack(t_stack *st);
void	print_stack(t_stack *st);
int		is_stack_clear(t_stack *st);

#endif