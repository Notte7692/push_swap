/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nassimsalhi <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:17:15 by nassimsalhi       #+#    #+#             */
/*   Updated: 2023/01/17 14:43:40 by nsalhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* reverse rotates the two stacks until one of them is in the right position
the cost is negative because each elements is in the bottom half of
their stacks.
*/
static void	rev_rotate_stacks(t_stack **a, t_stack **b, 
									int *cost_a, int *cost_b)
{
    while (*cost_a < 0 && *cost_b < 0)
        {
            (*cost_a)++;
            (*cost_b)++;
            do_rrr(a, b);
        }
}

/* Rotates the two stack until one of them is in the right position.
the cost is positive because each elements is in the upper half of their stacks.
when cost = 0, the stack has been rotated as far as possible and 
the top poition is correct.
*/
static void    rotate_both(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
    while (*cost_a > 0 && *cost_b > 0)
    {
        (*cost_a)--;
        (*cost_b)--;
        do_rr(a, b);
    }
}

/* Rotate the stack_a until it is in the right position) */
static void	rotate_a(t_stack **a, int *cost)
{
    while (*cost)
        {
            if (*cost > 0)
            {
                do_ra(a);
                (*cost)--;
            }
            else if (*cost < 0)
            {
                do_rra(a);
                (*cost)++;
            }
        }
}

/* Rotate the stack_b until it is in the good position*/
static void	rotate_b(t_stack **b,int *cost)
{
    while (*cost)
        {
            if (*cost > 0)
            {
                do_rb(b);
                (*cost)--;
            }
            else if (*cost < 0)
            {
                do_rrb(b);
                (*cost)++;
            }
        }
}

/* 
	select the best move to get the element of the b stack at the right
posion in the a stack.
	if the cost for each stack is negative or positive they rotate in
the same direction, else they rotate sepatetly.
*/
void	do_move(t_stack **a, t_stack **b, int cost_a, int cost_b)
{
    if (cost_a < 0 && cost_b < 0)
            rev_rotate_stacks(a, b, &cost_a, &cost_b);
        else if (cost_a > 0 && cost_b > 0)
            rotate_both(a, b, &cost_a, &cost_b);
        rotate_a(a, &cost_a);
        rotate_b(b, &cost_b);
        do_pa(a, b);
}
