/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalhi <<marvin@42.fr>>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 18:36:24 by nsalhi            #+#    #+#             */
/*   Updated: 2023/01/11 18:53:53 by nsalhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_swap(t_stack **stack)
{
	t_stack *tmp_first;
	t_stack	*tmp_second;

	if (stack == NULL || stack->next == NULL)
		return;
	tmp_fisrt = *stack;
	tmp_second = (*stack)->next;
	*stack = tmp_second;
	(*stack)->next = tmp_second->next;
}

void	do_sa(t_stack **stack_a)
{
	do_swap(stack_a);
	write (1, "sa\n", 3);
}

void	do_sb(t_stack **stack_b)
{
	do_swap(stack_b)
	write(1, "sb\n", 3);
}

void	do_ss(t_stack **stack_a, t_stack **stack_b)
{
	do_swap(stack_a);
	do_swap(stack_b);
	write(1, "ss\n", 3)
}
