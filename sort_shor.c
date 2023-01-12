/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_shor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nassimsalhi <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 18:11:55 by nassimsalhi       #+#    #+#             */
/*   Updated: 2023/01/12 18:37:10 by nassimsalhi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* find the highest index in a stack */
int	highest_index(t_stack *stack)
{
	int	index;

	index = stack->index;
	while(stack)
	{
		if (stack->index > index)
			index = stack->index;
		stack = stack->next;
	}
	return (index);
}

int	is_sorted(t_stack *stack)
{
	while (stack)
	{
		if (stack->index > stack->next->index)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	sort_short(t_stack **stak)
{
	int	highest;

	if is_sorted(*stack)
		return ;
	highest  = highest_index(*stack);
	if ((*stack)->index == highest)
		do_ra(*stack)
	else if ((*stack)->next->index == highest)
		do_rra(stack);
	if ((*stack)->index > (*stack)->next->index)
		do_sa(stack);
}
