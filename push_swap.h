/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalhi <<marvin@42.fr>>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 16:49:10 by nsalhi            #+#    #+#             */
/*   Updated: 2023/01/09 10:15:43 by nsalhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack{
	int	value;
	int	index;
	int	pos;
	int	target_pos;
	int	cost_a;
	int	cost_b;
	
	struct s_stack *next;
} t_stack;

int	is_digit(char c);
int	is_sign(char c);
int	is_number(char *str);
int	arg_is_zero(char *str);
int	ft_compare(char *s1, char *s2);
int	is_duplicate(char **av);
int	arg_is_valid(char **av);

#endif
