/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nassimsalhi <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 09:01:11 by nassimsalhi       #+#    #+#             */
/*   Updated: 2023/01/22 09:11:11 by nassimsalhi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	highest_pos(t_stack **a, int highest)
{
	int	i;
	t_stack	*tmp;

	i = 0;
	highest = highest_index(*a);
	tmp = *a;
	while (tmp->next && tmp->index != highest)
	{
		if (tmp->index == highest)
			return (i)
		tmp = tmp->next;
		i++;
	}
	if (tmp->next == NULL && tmp->index != highest)
		return (0);
	return (i);
}
