#include "philo.h"

size_t     ftatoi(const char *ptr)
{
        int     j;
        int     i;
        int     k;

        j = 0;
        i = 1;
        k = 0;
        if (*ptr == '-')
                return (0);
        while (*ptr == '+')
        {
                ptr++;
                j++;
        }
        if (j >= 2)
                return (0);
        while (*ptr >= '0' && *ptr <= '9')
        {
                k = k * 10 + (*ptr - '0');
                ptr++;
        }
        return (k * i);
}
