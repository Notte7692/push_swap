/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nassimsalhi <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 10:40:08 by nassimsalhi       #+#    #+#             */
/*   Updated: 2023/01/23 10:41:14 by nassimsalhi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 Push all elements of the stack_a in the stack_b, except the three last ones.
 Push the smaller value (aka lower index) first, and the larger values after.
 This will help to gain efficiency when we sort
 */
static void	push_all_except_three(t_stack **stack_a, t_stack **stack_b)
{
	int	stack_size;
	int	pushed;
	int	i;

	stack_size = get_stack_size(*stack_a);
	pushed = 0;
	i = 0;
	while (stack_size > 6 && i < stack_size && pushed < stack_size / 2)
	{
		if ((*stack_a)->index <= stack_size / 2)
		{
			do_pb(stack_a, stack_b);
			pushed++;
		}
		else
			do_ra(stack_a);
		i++;
	}
	while (stack_size - pushed > 3)
	{
		do_pb(stack_a, stack_b);
		pushed++;
	}
}

/*
 When a majority of the stack is sorted we will rotate
 or reverse-rotate the stack to put the lowest index at
 the top position
 */
static void	shift_stack(t_stack **stack_a)
{
	int	lowest_pos;
	int	stack_size;

	stack_size = get_stack_size(*stack_a);
	lowest_pos = get_lowest_index_position(stack_a);
	if (lowest_pos > stack_size / 2)
	{
		while (lowest_pos < stack_size)
		{
			do_rra(stack_a);
			lowest_pos++;
		}
	}
	else
	{
		while (lowest_pos > 0)
		{
			do_ra(stack_a);
			lowest_pos--;
		}
	}
}

/*
 It's the algorithme that will sort the stacck with more
 than three elements.
 We will push every elements except three in stack_b.
 we will osrt this three elements, then we calculate the most
 efficient move.
 and then we eill shift the stack untill stack a is in order
 */
void	sort(t_stack **stack_a, t_stack **stack_b)
{
	push_all_except_three(stack_a, stack_b);
	sort_three(stack_a);
	while (*stack_b)
	{
		get_target_position(stack_a, stack_b);
		get_cost(stack_a, stack_b);
		do_cheapest_move(stack_a, stack_b);
	}
	if (!is_sorted(*stack_a))
		shift_stack(stack_a);
}
