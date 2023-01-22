/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalhi <<marvin@42.fr>>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 18:36:24 by nsalhi            #+#    #+#             */
/*   Updated: 2023/01/13 18:12:46 by nassimsalhi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void    do_swap(t_stack *stack)
{
    int    tmp;

    if (stack == NULL || stack->next == NULL)
        return ;
    tmp = stack->value;
    stack->value = stack->next->value;
    stack->next->value = tmp;
    tmp = stack->index;
    stack->index = stack->next->index;
    stack->next->index = tmp;
}

void	do_sa(t_stack **stack_a)
{
	do_swap(*stack_a);
	write (1, "sa\n", 3);
}

void	do_sb(t_stack **stack_b)
{
	do_swap(*stack_b);
	write(1, "sb\n", 3);
}

void	do_ss(t_stack **stack_a, t_stack **stack_b)
{
	do_swap(*stack_a);
	do_swap(*stack_b);
	write(1, "ss\n", 3);
}
