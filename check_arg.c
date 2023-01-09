/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalhi <<marvin@42.fr>>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 17:19:34 by nsalhi            #+#    #+#             */
/*   Updated: 2023/01/09 10:12:35 by nsalhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_compare(char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (s1[i] == '+')
		i++;
	if (s2[j] == '+')
		j++;
	while (s1[i] != '\0' && s2[j] != '\0' && s1[i] == s2[j])
	{
		i++;
		j++;
	}
	if (s1[i] == '\0' && s2[j] == '\0')
		return (1);
	return (0);
}

int	is_duplicate(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 1;
		while (av[j])
		{
			if ( j != i && ft_compare(av[i], av[j]) == 1)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	arg_is_valid(char **av)
{
	int	i;
	int	nb_zero;

	i = 1;
	nb_zero = 0;
	while (av[i])
	{
		if (!is_number(av[i]))
			return (0);
		if (arg_is_zero(av[i]) == 1)
			nb_zero += 1;
		i++;
	}
	if (nb_zero > 1)
		return (0);
	if (is_duplicate(av))
		return (0);
	return (1);
}
