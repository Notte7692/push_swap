/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nassimsalhi <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 10:49:19 by nassimsalhi       #+#    #+#             */
/*   Updated: 2023/01/24 14:31:59 by nassimsalhi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>

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

t_stack		*create_stack(int ac, char **av);
void		assign_index(t_stack *stack_a, int ac);

int			is_sorted(t_stack *stack);
void		sort_three(t_stack **stack);
void		sort(t_stack **stack_a, t_stack **stack_b);

int			get_lowest_index_position(t_stack **stack);
void		get_target_position(t_stack **stack_a, t_stack **stack_b);

void		get_cost(t_stack **stack_a, t_stack **stack_b);
void		do_cheapest_move(t_stack **stack_a, t_stack **stack_b);

void		do_move(t_stack **a, t_stack **b, int cost_a, int cost_b);

void		do_pa(t_stack **stack_a, t_stack **stack_b);
void		do_pb(t_stack **stack_a, t_stack **stack_b);
void		do_sa(t_stack **stack_a);
void		do_sb(t_stack **stack_b);
void		do_ss(t_stack **stack_a, t_stack **stack_b);
void		do_ra(t_stack **stack_a);
void		do_rb(t_stack **stack_b);
void		do_rr(t_stack **stack_a, t_stack **stack_b);
void		do_rrr(t_stack **stack_a, t_stack **stack_b);
void		do_rra(t_stack **stack_a);
void		do_rrb(t_stack **stack_b);

t_stack		*get_stack_bottom(t_stack *stack);
t_stack		*get_stack_before_bottom(t_stack *stack);
t_stack		*stack_new(int value);
void		stack_add_bottom(t_stack **stack, t_stack *new);
int			get_stack_size(t_stack	*stack);

void		free_stack(t_stack **stack);
long int	ft_atoi(const char *str);
void		ft_putstr(char *str);
int			nb_abs(int nb);

void		exit_error(t_stack **stack_a, t_stack **stack_b);

int			is_correct_input(char **av);
int			is_digit(char c);
int			is_sign(char c);
int			ft_cmp(const char *s1, const char *s2);

char		**ft_split(const char *s, char c);

size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);

#endif
