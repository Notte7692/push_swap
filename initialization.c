/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 10:34:53 by nsalhi            #+#    #+#             */
/*   Updated: 2023/01/09 11:39:22 by nsalhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack **stack)
{
	t_stack *tmp;
	
	if (!stack || !*stack)
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

void	exit_error(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_a == NULL && *stack_a != NULL)
		free_stack(stack_a);
	if (stack_b == NULL && *stack_b != NULL)
		free_stack(stack_b);
	write (1, "error\n", 6);
	exit (1);
}

t_stack *stack_new(int value)
{
	t_stack	*new;

	new = malloc(sizeof *new);
	if (!new)
		return (NULL);
	new->value = value;
	new->index = 0;
	new->pos = -1;
	new->cost_a = -1;
	new->cost_b = -1;
	new->next = NULL;
	
	return(new);
}

t_stack *get_bottom(t_stack *stack)
{
	while (stack->next != NULL)
		stack = stack->next;
	return (stack);
}

void stack_add_bottom(t_stack **stack, t_stack *new)
{
	t_stack *last;
	
	last = *stack;
	if (!new)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	last = get_bottom(*stack);
	last->next = new;
}

t_stack	*create_stack(int ac,char **av)
{
	int	i;
	long int	nb;
	t_stack *stack_a;

	i = 1;
	nb = 0;
	while (i < ac)
	{
		nb = ft_atoi(av[i]);
		if ( nb < INT_MIN || nb > INT_MAX)
		{
			exit_error;
		}
		if ( i == 1)
			stack_a = stack_new((int)nb);
		else
			stack_a = stack_add_bottom((int)nb);
	}
	return (stack_a);
}

int main(int argc, char **argv)
{
    t_stack *stack_a = create_stack(argc, argv);
    t_stack *current = stack_a;
    while (current != NULL)
    {
        printf("%d\n", current->value);
        current = current->next;
    }
    return 0;
}


