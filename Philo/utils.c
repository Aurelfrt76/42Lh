/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afromont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 14:11:37 by afromont          #+#    #+#             */
/*   Updated: 2024/02/07 14:11:44 by afromont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

t_philo init_list(size_t nbphilo)
{
        t_philo *head;
        t_philo *new_node;
        t_philo *current;
        size_t i;

        head = NULL;
        while(i++ < nbphilo)
        {
                pthread_create(&list.id_philo, NULL, test, NULL);
                *new_node = create_node(list.id_philo);
                if (head == NULL)
                        head = new_node;
                else
                {
                        *current = *head;
                        while (current->list.next != NULL)
                                *current = *current->list.next;
                        *current->list.next = *new_node;
                }
        }
        return (*head);
}

t_philo create_node(t_philo tid)
{
        t_philo new_node;

        tid = list.id_philo;
        new_node = malloc(sizeof(t_philo));
        if (new_node == NULL)
                error("error malloc node");
        new_node.list.id_philo = list.id_philo;
        new_node.list.next = NULL;
        return (new_node);
}

void *test(void *arg)
{
	(void)arg;
	printf("\n");
	usleep (1000);
	return(0);
}
