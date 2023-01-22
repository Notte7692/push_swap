/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 11:30:50 by nsalhi            #+#    #+#             */
/*   Updated: 2023/01/04 18:24:27 by nsalhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Fill a stack with the povided values, if nb is not in the integer range
exit the program*/
t_stack	*create_stack(int ac, char **av)
{
	t_stack		*stack_a;
	long int	nb;
	int			i;

	i = 1;
	while (i < ac)
	{
		if (!check_arg_int_max(av[i]))
			exit_error(&stack_a, NULL);;
		nb = ft_atoi(av[i]);
		if (i == 1)
			stack_a = stack_new((int)nb);
		else
			stack_add_bottom(&stack_a, stack_new((int)nb));
		i++;
	}
	return (stack_a);
}

/*Put an index on each value of the stack_a from the min number 
to the max number, this will permit to check if our number are 
in the right order*/
void	assign_index(t_stack *stack_a, int stack_size)
{
    t_stack    *ptr;
    t_stack    *highest;
    int        value;

    while (--stack_size > 0)
    {
        ptr = stack_a;
        value = INT_MIN;
        highest = NULL;
        while (ptr)
        {
            if (ptr->value == INT_MIN && ptr->index == 0)
                ptr->index = 1;
            if (ptr->value > value && ptr->index == 0)
            {
                value = ptr->value;
                highest = ptr;
                ptr = stack_a;
            }
            else
                ptr = ptr->next;
        }
        if (highest != NULL)
            highest->index = stack_size;
        }
}
