/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:18:25 by nsalhi            #+#    #+#             */
/*   Updated: 2023/01/16 14:02:16 by nassimsalhi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* calcul the cost of moving each elements of stack_b into the
correct positioni in stack_a.
	cost_b represents the cost of getting the element to the top of stack_b
	cost_a represents the cost of getting to the right position in stack_a
*/
void	get_cost(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;
	int		size_a;
	int		size_b;

	tmp_a = *stack_a;
	tmp_b = *stack_b;
	size_a = get_stack_size(tmp_a);
	size_b = get_stack_size(tmp_b);
	while (tmp_b)
	{
		tmp_b->cost_b = tmp_b->pos;
		if (tmp_b->pos > (size_b / 2))
			tmp_b->cost_b = (size_b - tmp_b->pos) * -1;
		tmp_b->cost_a = tmp_a->pos;
		if (tmp_b->target_pos > (size_a / 2))
			tmp_b->cost_a = (size_a - tmp_b->target_pos) * -1;
		tmp_b = tmp_b->next;
	}
}

/*This function calcul and do the move with the cheapest cost
	It takes an element from stack_b and put it at the correct position
	in stack_a.
*/
void	make_cheapest_move(t_stack **stack_a, t_stack **stack_b)
{
    t_stack    *tmp;
        int        cheapest;
        int        cost_a;
        int        cost_b;

        tmp = *stack_b;
        cheapest = INT_MAX;
        while (tmp)
        {
            if (nb_abs(tmp->cost_a) + nb_abs(tmp->cost_b) < nb_abs(cheapest))
            {
                cheapest = nb_abs(tmp->cost_b) + nb_abs(tmp->cost_a);
                cost_a = tmp->cost_a;
                cost_b = tmp->cost_b;
            }
            tmp = tmp->next;
        }
        do_move(stack_a, stack_b, cost_a, cost_b);
}
