/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_inputs-utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 10:13:28 by nsalhi            #+#    #+#             */
/*   Updated: 2023/01/18 11:06:47 by nsalhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
/* Check if the character is a digit, Return 1 if true, 0 if false*/
int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

/* Check if the charcater is a sign, Return 1 if truei, 0 if false */
int	is_sign(char c)
{
	return (c == '+' || c == '-');
}

/* Check if the number pass in arguments are digiti,
return 1 if true, 0 if false*/
int	arg_is_number(char *av)
{
	int	i;

	i = 0;
	if ((is_sign(av[i]) == 1) && av[i + 1] != '\0')
	{
		i++;
	}
	while (av[i] && is_digit(av[i]))
		i++;
	if (av[i] != '\0' && !is_digit(av[i]))
		return (0);
	return (1);
}

/* Check if we have a number both time,
 return 0 if we have a double else return the differnce value */
int	ft_compare(char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = i;
	if (s1[i] == '+')
	{
		if (s2[j] != '+')
			i++;
	}
	else
	{
		if (s2[j] == '+')
			j++;
	}
	while (s1[i] != '\0' && s2[j] != '\0' && s1[i] == s2[j])
	{
		i++;
		j++;
	}
	return (s1[i] - s2[j]);
}

int	ft_strlen(char *str)
{
	int	i;
	
	i = 0;
	while(str[i] != '\0')
	{
		i++;
	}
	return (i);
}

static int	check_nb_max(char *av, int i, long int max)
{
	long int	nb;

	nb = 0;
	while (av[i] != '\0')
	{
		nb = (nb * 10) + (av[i] - '0');
		if (nb > max)		
			return (0);
		i++;
	}
	return (1);
}


int	check_arg_int_max(char *av)
{
	int		len;
	int		i;
	long int	max;
	
	i = 0;
	max = INT_MAX;
	len = ft_strlen(av);
	if (len > 11 || (len == 11 && is_sign(av[0]) == 0))
		return (0);
	if (av[0] == '+' || av[0] == '-')
	{
		if (av[0] == '-')
			max = INT_MAX + (long)1;
		i++;
	}
	if (len == 10 || (len == 11 && is_sign(av[0]) == 1))
	{
		return(check_nb_max(av, i, max));	
	}
	return (1);
}
