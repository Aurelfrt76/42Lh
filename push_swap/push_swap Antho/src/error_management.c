#include <stdlib.h>
#include "error_management.h"
#include "../LIB/ft_printf.h"

void	exit_with_error(const char *err_msg)
{
	ft_printf("%s", err_msg);
	exit(1);
}