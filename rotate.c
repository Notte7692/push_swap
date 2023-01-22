/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalhi <<marvin@42.fr>>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:16:52 by nsalhi            #+#    #+#             */
/*   Updated: 2023/01/13 18:10:11 by nassimsalhi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack **stack)
{
    t_stack    *tmp;
    t_stack    *tail;

    tmp = *stack;
    *stack = (*stack)->next;
    tail = get_stack_bottom(*stack);
    tmp->next = NULL;
    tail->next = tmp;
}

void	do_ra(t_stack **stack_a)
{
	rotate(stack_a);
	write (1, "ra\n", 3);
}

void	do_rb(t_stack **stack_b)
{
	rotate(stack_b);
	write (1, "rb\n", 3);
}

void	do_rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	write (1, "rr\n", 3);
}
