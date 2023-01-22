/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_inputs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalhi <<marvin@42.fr>>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 18:14:08 by nsalhi            #+#    #+#             */
/*   Updated: 2023/01/03 15:22:31 by nsalhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"
/*Check if we have duplicate in arg, return 1 if it find a duplicate,
return 0 if not */
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
			if (j != i && ft_compare(av[i], av[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

/*Check if arg is 0 return 1 if false 0 if true)*/
int	arg_is_zero(char *av)
{
	int	i;

	i = 0;
	if (is_sign(av[i]) == 1)
		i++;
	while (av[i] && av[i] == '0')
		i++;
	if (av[i] != '\0')
		return (1);
	return (0);
}

/*check if the argument input is correct return 1 if true 0 if false*/
int	is_correct_arg(char **av)
{
	int	i;
	int	nb_zero;

	i = 1;
	nb_zero = 0;
	while (av[i])
	{
		if (!arg_is_number(av[i]))
		{
			return (0);
		}
		if (!check_arg_int_max(av[i]))
			return (0);
		if (arg_is_zero(av[i]) == 0)
			nb_zero += 1;
		i++;
	}
	if (nb_zero > 1)
		return (0);
	if (is_duplicate(av))
		return (0);
	return (1);
}
