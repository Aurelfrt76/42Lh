#include "philo.h"

int     ftatoi(const char *ptr)
{
        int     j;
        int     i;
        int     k;

        j = 0;
        i = 1;
        k = 0;
        if (*ptr == '-')
                return (0);
        while (*ptr == '+' || *ptr == '-')
        {
                ptr++;
                j++;
        }
        if (j >= 2)
                return (0);
        while (*ptr >= 48 && *ptr <= 57)
        {
                k = k * 10 + (*ptr - '0');
                ptr++;
        }
        return (k * i);
}
