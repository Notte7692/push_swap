/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalhi <<marvin@42.fr>>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 17:20:10 by nsalhi            #+#    #+#             */
/*   Updated: 2023/01/08 20:33:23 by nsalhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

int	is_sign(char c)
{
	return (c == '-' || c == '+');
}

int	is_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] != '\0')
	{
		if (is_sign(str[i]))
			i++;
	}
	while(str[i] != '\0')
	{
		if (!is_digit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	arg_is_zero(char *str)
{
	int	i;

	i = 0;
	if (is_sign(str[i]) == 1)
			i++;
	while (str[i] == '0')
		i++;
	if (str[i] == '\0')
		return (0);
	else
		return (1);
}

int	ft_atoi(char *num);
{
	
}
