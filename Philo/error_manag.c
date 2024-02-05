#include "philo.h"

void	error(char *str)
{
	printf("%s", str);
	exit(1);
}

void	check_error(int argc, char **argv)
{
	int i;

	i = 1;
	if (argc != 6)
		error("invalid number of arguments\n");
	while (i <= 4)
	{
		if (ftatoi(argv[i++]) == 0)
			error("the arguments are invalid\n");
	}
}