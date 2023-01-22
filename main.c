/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nassimsalhi <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 15:48:09 by nassimsalhi       #+#    #+#             */
/*   Updated: 2023/01/18 16:53:36 by nsalhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int    is_sorted(t_stack *stack)
{
    while (stack->next != NULL)
    {
        if (stack->value > stack->next->value)
            return (0);
        stack = stack->next;
    }
    return (1);
}


void    push_swap(t_stack **stack_a, t_stack **stack_b, int stack_size)
{
    if (stack_size == 2 && !is_sorted(*stack_a))
        do_sa(stack_a);
    else if (stack_size == 3)
    {
        sort_short(stack_a);
        printf("value = %d index = %d", (*stack_a)->value, (*stack_a)-> index);
    }
    else if (stack_size > 3 && !is_sorted(*stack_a))
    {
        sort(stack_a, stack_b);
        printf("value sort = %d index sort = %d", (*stack_a)->value, (*stack_a)-> index);
    }
}

int main(int ac, char **av)
{
    t_stack    *stack_a;
    t_stack    *stack_b;
    int        stack_size;

    if (ac < 2)
        return (0);
    if (!is_correct_arg(av))
        exit_error(NULL, NULL);
    stack_a = create_stack(ac, av);
    stack_b = NULL;
    stack_size = get_stack_size(stack_a);
    stack_size = get_stack_size(stack_a);
    assign_index(stack_a, stack_size + 1);
    push_swap(&stack_a, &stack_b, stack_size);
    while (stack_a)
    {
        printf("value = %d, index = %d\n", stack_a->value, stack_a->index);
        stack_a = stack_a->next;
    }
    free_stack(&stack_a);
    free_stack(&stack_b);
    return (0);
}
