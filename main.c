/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nassimsalhi <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 10:31:13 by nassimsalhi       #+#    #+#             */
/*   Updated: 2023/01/24 14:31:21 by nassimsalhi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 Check if the stack is sorted
*/
int	is_sorted(t_stack *stack)
{
	while (stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

/*
 Choose the right method in function of the number of arguments provided
*/
static void	push_swap(t_stack **stack_a, t_stack **stack_b, int stack_size)
{
	if (stack_size == 2 && !is_sorted(*stack_a))
		do_sa(stack_a);
	else if (stack_size == 3)
		sort_three(stack_a);
	else if (stack_size > 3 && !is_sorted(*stack_a))
		sort(stack_a, stack_b);
}

static char	**parse_av(char *string, int *count)
{
	char	**tab;
	int		i;

	i = 0;
	tab = ft_split(string, ' ');
	while (tab[i])
	{
		i++;
	}
	*count = i;
	return (tab);
}

static void	run_push_swap(char **tab, int count)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		stack_size;

	stack_b = NULL;
	stack_a = create_stack(count, tab);
	stack_size = get_stack_size(stack_a);
	assign_index(stack_a, stack_size + 1);
	push_swap(&stack_a, &stack_b, stack_size);
	free_stack(&stack_a);
	free_stack(&stack_b);
}

/*
 Main function, check if th arguments are corrects.
 If that the case create stacks and choose the right sorting method.
 At the end free both stacks.
*/
int	main(int ac, char **av)
{
	char	**tab;
	int		count;

	if (ac < 2)
		return (0);
	if (ac == 2)
		tab = parse_av(av[1], &count);
	else
	{
		tab = &av[1];
		count = ac - 1;
	}
	if (!is_correct_input(tab))
		exit_error(NULL, NULL);
	run_push_swap(tab, count);
	return (0);
}
