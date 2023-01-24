/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nassimsalhi <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 10:14:58 by nassimsalhi       #+#    #+#             */
/*   Updated: 2023/01/23 17:33:29 by nassimsalhi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
  Reverse-rotate both stacks until one of them is in the right position.
 The cost will be negative since the elements are in the second half
 of the stacks.
 When one of the cost = 0 it means that the stack has been rotated as
 far as possible, and the element in the firs position is correctly set.
 */
static void	rev_rotate_both(t_stack **a, t_stack **b,
					int *cost_a, int *cost_b)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		(*cost_a)++;
		(*cost_b)++;
		do_rrr(a, b);
	}
}

/*
 Rotate both stacks  until one of them is in the right position.
 The cost will be positive since the elements are
 in the fisrt half of the stack.
 When one of the cost = 0 it means that the stack has been rotated,
 as far as possible, and the element in the first position is correctly set.
 */
static void	rotate_both(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		(*cost_a)--;
		(*cost_b)--;
		do_rr(a, b);
	}
}

/*
 Rotates stack until it is in position, if the elementt
 is in the 2nd half the
 cost is negative and we do a reverse-rotate,
 else it's positive and we will do a rotate.
 */
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

/*
 Same logic as for the previous function but with the b stack.
 */
static void	rotate_b(t_stack **b, int *cost)
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
 This function chooses wich move to do to get the elemtn of stack_b to the
 correct position in the stack_a.
 if the cost to move the elements are the same the same operation will be
 applied to both.
 Else we will do the best operation for each element (rotate or reverse_rotate)
 */
void	do_move(t_stack **a, t_stack **b, int cost_a, int cost_b)
{
	if (cost_a < 0 && cost_b < 0)
		rev_rotate_both(a, b, &cost_a, &cost_b);
	else if (cost_a > 0 && cost_b > 0)
		rotate_both(a, b, &cost_a, &cost_b);
	rotate_a(a, &cost_a);
	rotate_b(b, &cost_b);
	do_pa(a, b);
}
