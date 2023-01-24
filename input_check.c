/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nassimsalhi <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 10:20:40 by nassimsalhi       #+#    #+#             */
/*   Updated: 2023/01/24 14:33:40 by nassimsalhi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 Check if the arg provided is a number
 */
static int	arg_is_number(char *av)
{
	int	i;

	i = 0;
	if (is_sign(av[i]) && av[i + 1] != '\0')
		i++;
	while (av[i] && is_digit(av[i]))
		i++;
	if (av[i] != '\0' && !is_digit(av[i]))
		return (0);
	return (1);
}

/*
 Check if we have a duplicate arg in the arg list provide
 by the user.
 */
static int	have_duplicates(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[i])
	{
		j = 0;
		while (av[j])
		{
			if (j != i && ft_cmp(av[i], av[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

/*
 verify if an arg provided is a 0
 */
static int	arg_is_zero(char *av)
{
	int	i;

	i = 0;
	if (is_sign(av[i]))
		i++;
	while (av[i] && av[i] == '0')
		i++;
	if (av[i] != '\0')
		return (0);
	return (1);
}

/*
 Check if the arguments provided respect the rules:
 -No duplicate
 -Only numbers
 */
int	is_correct_input(char **av)
{
	int	i;
	int	nb_zero;

	nb_zero = 0;
	i = 0;
	while (av[i])
	{
		if (!arg_is_number(av[i]))
			return (0);
		nb_zero += arg_is_zero(av[i]);
		i++;
	}
	if (nb_zero > 1)
		return (0);
	if (have_duplicates(av))
		return (0);
	return (1);
}
