/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nucieda <nucieda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 15:56:20 by nucieda-          #+#    #+#             */
/*   Updated: 2023/03/06 10:43:21 by nucieda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stddef.h>
# include "libft/libft.h"

typedef struct s_stack
{
	int	*n;
	int	s;
}	t_stack;

void	print_stacks(t_stack a, t_stack b);

void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);

void	sa(t_stack *stack);
void	sb(t_stack *stack);
void	swap(t_stack *stack);
void	ss(t_stack *a, t_stack *b);

void	ra(t_stack *stack);
void	rb(t_stack *stack);
void	rotate(t_stack *stack);
void	rotate_r(t_stack *a, t_stack *b);

void	rra(t_stack *stack);
void	rrb(t_stack *stack);
void	reverse_rotate(t_stack *stack);
void	rrr(t_stack *a, t_stack *b);

int		ft_atoi(const char *ptr);

int		find_min(t_stack *stack);
int		find_max(t_stack *stack);
void	num_to_top(t_stack *stack, int num_index, int s);
void	merge_stacks(t_stack *a, t_stack *b, int size);
void	push_to_a(t_stack *a, t_stack *b, int size);
void	push_to_b(t_stack *a, t_stack *b, int size);
void	rotate_a(t_stack *a, int size);
void	rrotate_a(t_stack *a, int size);

int		sorted(t_stack *stack);
int		repeat(t_stack *stack);
int		error_check(t_stack *a, char **argv);
int		numbers(char **argv);
void	pick_sort(t_stack *a, t_stack *b, int size);

void	sort_small_stack(t_stack *a, t_stack *b);
void	sort_big_stack(t_stack *a, t_stack *b);

#endif