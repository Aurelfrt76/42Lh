#include "philo.h"

void	error(char *str)
{
	printf("%s", str);
	exit(1);
}

int	check_error(int argc, char **argv)
{
	int i;

	i = 1;
	if (ftatoi(argv[1]) >= 200)
			error("Error\nThe number of philosophers is greater than 200");
	if (argc == 5)
	{
		while (i <= 4)
		{
			if (ftatoi(argv[i]) == 0)
				error("Error\nthe arguments are invalid\n");
			i++;
		}
	}
	else if (argc == 6)
	{
		while (i <= 5)
		{
			if (ftatoi(argv[i]) == 0)
				error("Error\nthe arguments are invalid\n");
			i++;
		}
	}
	else
		error("Error\nInvalid number of arguments");
	return (0);
}