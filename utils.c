/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:30:16 by nsalhi            #+#    #+#             */
/*   Updated: 2023/01/10 18:43:30 by nsalhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long int	ft_atoi(const char *str)
{
	int	i;
	int	num;
	int	sign;

	i = 0;
	num = 0;
	sign = 1;
	if (str[i] != 0)
	{
		while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
			i++;
		if (str[i] == '+' || str[i] == '-')
		{
			if (str[i] == '-')
				sign *= -1;
			i++;
		}
		while (str[i] >= '0' && str[i] <= '9')
		{
			num = num * 10 + (str[i] - '0');
			i++;
		}
	}
	return (num * sign);
}

/* Write an error message on the standard output after freeing the stacks*/
void	exit_error(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_a == NULL || *stack_a != NULL)
		free_stack(stack_a);
	if (stack_b == NULL || *stack_b != NULL)
		free_stack(stack_b);
	write (2, "Error\n", 6);
	exit (1);
}

/* free ech element in a given stack and sets the stack pointer to NULL*/
void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !*stack)
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	stack = NULL;
}

int	nb_abs(int nb)
{
	if (nb < 0)
        return (nb * -1);
	return (nb);
}
