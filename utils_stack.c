/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:35:18 by nsalhi            #+#    #+#             */
/*   Updated: 2023/01/04 16:36:25 by nsalhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*return the last element of a stack*/
t_stack	*get_stack_bottom(t_stack *stack)
{
    while (stack && stack->next != NULL)
        stack = stack->next;
    return (stack);
}

t_stack	*get_stack_before_bottom(t_stack *stack)
{
    while (stack && stack->next && stack->next->next != NULL)
        stack = stack->next;
    return (stack);
}


/*create a new element in a stack, end return it*/
t_stack	*stack_new(int value)
{
    t_stack    *new;

    new = malloc(sizeof * new);
    if (!new)
        return (NULL);
    new->value = value;
    new->index = 0;
    new->pos = -1;
    new->target_pos = -1;
    new->cost_a = -1;
    new->cost_b = -1;
    new->next = NULL;
    return (new);
}

/*add a new ellement at the bottom of a stack*/
void	stack_add_bottom(t_stack **stack, t_stack *new)
{
    t_stack    *tail;

    if (!new)
        return ;
    if (!*stack)
    {
        *stack = new;
        return ;
    }
    tail = get_stack_bottom(*stack);
    tail->next = new;
}

/* return he number of element in a stack*/
int	get_stack_size(t_stack *stack)
{
    int    size;

    size = 0;
    if (!stack)
        return (0);
    while (stack)
    {
        stack = stack->next;
        size++;
    }
    return (size);
}
