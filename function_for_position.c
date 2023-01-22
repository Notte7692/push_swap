/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_for_position.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalhi <<marvin@42.fr>>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:20:50 by nsalhi            #+#    #+#             */
/*   Updated: 2023/01/10 16:58:44 by nsalhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Assign a position to each element of a stack
for exemple, stack :
value	 : 1 6 4 9
index	 : 0 2 1 3
position : 1 2 3 4
*/

void	get_position(t_stack **stack)
{
    t_stack    *tmp;
    int        i;

    tmp = *stack;
    i = 0;
    while (tmp)
    {
        tmp->pos = i;
        tmp = tmp->next;
        i++;
    }
}

/* Return the current position of the element with the lowest index
in the stack */
int	get_lowest_index_position(t_stack **stack)
{
    t_stack    *tmp;
    int        lowest_index;
    int        lowest_pos;

    tmp = *stack;
    lowest_index = INT_MAX;
    get_position(stack);
    lowest_pos = tmp->pos;
    while (tmp)
    {
        if (tmp->index < lowest_index)
        {
            lowest_index = tmp->index;
            lowest_pos = tmp->pos;
        }
        tmp = tmp->next;
    }
    return (lowest_pos);
}

/* Find the best target position for an element in the stack_b which index is
provided by b_idx. Primary check if the elements of the stack b can be place
somewhere at the start or between elements the stack_a, 
to do this we will check if an elements in stack_a as a bigger index than b_idx.
If it's not possible the function find the element with the lower index.*/
int	get_target(t_stack **a, int b_idx, int target_idx, int target_pos)
{
    t_stack    *tmp_a;

    tmp_a = *a;
    while (tmp_a)
    {
        if (tmp_a->index > b_idx && tmp_a->index < target_idx)
        {
            target_idx = tmp_a->index;
            target_pos = tmp_a->pos;
        }
        tmp_a = tmp_a->next;
    }
    if (target_idx != INT_MAX)
        return (target_pos);
    tmp_a = *a;
    while (tmp_a)
    {
        if (tmp_a->index < target_idx)
        {
            target_idx = tmp_a->index;
            target_pos = tmp_a->pos;
        }
        tmp_a = tmp_a->next;
    }
    return (target_pos);
}

/* attribute for each elemts in stack_a target_position
the target position is the information that is needed by each elements 
of stack_b to be sorted correctly*/
void	find_target_position(t_stack **a, t_stack **b)
{
    t_stack    *tmp_b;
    int        target_pos;

    tmp_b = *b;
    get_position(a);
    get_position(b);
    target_pos = 0;
    while (tmp_b)
    {
        target_pos = get_target(a, tmp_b->index, INT_MAX, target_pos);
        tmp_b->target_pos = target_pos;
        tmp_b = tmp_b->next;
    }
}
