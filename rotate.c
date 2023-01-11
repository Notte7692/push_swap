/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalhi <<marvin@42.fr>>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:16:52 by nsalhi            #+#    #+#             */
/*   Updated: 2023/01/11 15:31:53 by nsalhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack *last;

	last = get_stack_bottom(stack);
	tmp = *stack;
	*stack = *stack->next;
	tmp->next = NULL;
	last->next = tmp;
}

void	do_ra(t_stack **stack_a)
{
	rotate(stack_a);
	write (1, "ra\n", 3) 
}

void	do_rb(t_stack **stack_b)
{
	rotate(stack_b);
	write (1. "rb\n", 3);
}

void	do_rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	write (1, "rr\n", 3);
}
