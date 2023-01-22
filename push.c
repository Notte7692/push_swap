/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalhi <<marvin@42.fr>>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 12:15:01 by nsalhi            #+#    #+#             */
/*   Updated: 2023/01/17 15:00:48 by nsalhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack **src, t_stack **dest)
{
    t_stack    *tmp;

    if (*src == NULL)
        return ;
    tmp = (*src)->next;
    (*src)->next = *dest;
    *dest = *src;
    *src = tmp;
}


/* Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty*/
void	do_pa(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_b, stack_a);
	write (1, "pa\n", 3);
}

/* Take the first element at the top of a and put it at the top of b.
Do nothing if a is empty*/
void	do_pb(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_a, stack_b);
	write (1, "pb\n", 3);
}
