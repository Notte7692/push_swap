/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 10:36:15 by nsalhi            #+#    #+#             */
/*   Updated: 2023/01/19 17:47:28 by nassimsalhi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <stddef.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}	t_stack;

int		arg_is_number(char *av);
int		is_digit(char c);
int		is_sign(char c);

int		ft_compare(char *s1, char *s2);
int		is_duplicate(char **av);
int		arg_is_zero(char *av);
int		is_correct_arg(char **av);

long int		ft_atoi(const char *str);
void	free_stack(t_stack **stack);
void	exit_error(t_stack **stack_a, t_stack **stack_b);
t_stack	*get_stack_bottom(t_stack *stack);
t_stack	*get_stack_before_bottom(t_stack *stack);
t_stack	*stack_new(int value);
void	stack_add_bottom(t_stack **stack, t_stack *new);
int		get_stack_size(t_stack *stack);
t_stack	*create_stack(int ac, char **av);
void	assign_index(t_stack *stack_a, int stack_size);

void	get_position(t_stack **stack);
void	assign_position(t_stack **stack);
int		get_lowest_index_position(t_stack **stack);
int		get_target(t_stack **a, int b_idx, int target_idx, int target_pos);
void	find_target_position(t_stack **a, t_stack **b);

void	do_pa(t_stack **stack_a, t_stack **stack_b);
void	do_pb(t_stack **stack_a, t_stack **stack_b);

void	do_rra(t_stack **stack_a);
void	do_rrb(t_stack **stack_b);
void	do_rrr(t_stack **stack_a, t_stack **stack_b);

void	do_ra(t_stack **stack_a);
void	do_rb(t_stack **stack_b);
void	do_rr(t_stack **stack_a, t_stack **stack_b);
int		highest_index(t_stack *stack);
int		is_sorted(t_stack *stack);
void	sort_short(t_stack **stak);

void	sort(t_stack **stack_a, t_stack **stack_b);

void	do_sa(t_stack **stack_a);
void	do_sb(t_stack **stack_b);
void	do_ss(t_stack **stack_a, t_stack **stack_b);
int		nb_abs(int nb);

void	do_move(t_stack **a, t_stack **b, int cost_a, int cost_b);
void	get_cost(t_stack **stack_a, t_stack **stack_b);
void	make_cheapest_move(t_stack **stack_a, t_stack **stack_b);

int	check_arg_int_max(char *av);

void	shift_stack_except_three(t_stack **stack_a, t_stack **stack_b);

#endif
