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
	if (argc <= 6)
	{
		if (ftatoi(argv[1]) >= 200)
			error("Error\nThe number of philosophers is greater than 200");
		if (argc == 5)
		{
			while (i++ <= 4)
			{
				if (ftatoi(argv[i]) == 0)
					error("Error\nthe arguments are invalid\n");
			}
		}
		else if (argc == 6)
		{
			while (i++ <= 5)
			{
				if (ftatoi(argv[i]) == 0)
					error("Error\nthe arguments are invalid\n");
			}
		}
	}
	else
		error("Error\nInvalid number of arguments");
}