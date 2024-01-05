#include "stack.h"
#include <stdlib.h>

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack *stack_b;
	t_stack	*firststacka;
	int	i;
	
	i = 1;
	if (argc < 2)
		exit_with_error("error invalid number of arguments\n");

	while (argv[i])
	{
		if (ft_atoi(argv[i]) != 0 || argv[i][0] == '0')
		{
			ft_lstnew(stack_a->value = ft_atoi(argv[i]));
			ft_lstadd_front(stack_a->value, stack_a->next->value);
		}
		else
			exit_with_error("error the argument is not valid\n") // est-il possible dafficher l'argument qui pose soucis ?
		i++;
	}
	if (dbarg(firststacka) == 1)
		exit_with_error("error duplicate argument\n")
	// envoyer le 1er noeud de stack_a ou de sa copie dans la fonction int	stackaistried(t_stack lst); pour controle si les arguments sont trie et si le retour de la fonction est 0 alors la liste est trie dans ce cas afficher la stack a
	print_stack(st);
	clear_stack(st);
	return (0);
}

// pour copier la chaine dans une autre liste on peut utiliser ft_listiter avec la fonction memcpy?
// ajout de la fonction ft_atoi dans le dossier lib donc penser a refaire le .h et makefile lib pourquoi pas integrer la lib au complet ?