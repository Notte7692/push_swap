/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nassimsalhi <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 10:37:19 by nassimsalhi       #+#    #+#             */
/*   Updated: 2023/01/23 11:01:30 by nassimsalhi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 Reverse-rotate the stack the last lement is sent to the top
 */
static void	rev_rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*bottom;
	t_stack	*before_bottom;

	bottom = get_stack_bottom(*stack);
	before_bottom = get_stack_before_bottom(*stack);
	tmp = *stack;
	*stack = bottom;
	(*stack)->next = tmp;
	before_bottom->next = NULL;
}

void	do_rra(t_stack **stack_a)
{
	rev_rotate(stack_a);
	ft_putstr("rra\n");
}

void	do_rrb(t_stack **stack_b)
{
	rev_rotate(stack_b);
	ft_putstr("rrb\n");
}

void	do_rrr(t_stack **stack_a, t_stack **stack_b)
{
	rev_rotate(stack_a);
	rev_rotate(stack_b);
	ft_putstr("rrr\n");
}
