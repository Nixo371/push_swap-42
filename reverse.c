/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nucieda <nucieda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 16:07:14 by nucieda-          #+#    #+#             */
/*   Updated: 2023/01/28 16:31:22 by nucieda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *stack)
{
	int	buf;
	int	i;

	i = stack->s - 1;
	buf = stack->n[i];
	while (i > 0)
	{
		stack->n[i] = stack->n[i - 1];
		i--;
	}
	stack->n[i] = buf;
	printf("rra\n");
}

void	rrb(t_stack *stack)
{
	int	buf;
	int	i;

	i = stack->s - 1;
	buf = stack->n[i];
	while (i > 0)
	{
		stack->n[i] = stack->n[i - 1];
		i--;
	}
	stack->n[i] = buf;
	printf("rrb\n");
}

void	reverse_rotate(t_stack *stack)
{
	int	buf;
	int	i;

	i = stack->s - 1;
	buf = stack->n[i];
	while (i > 0)
	{
		stack->n[i] = stack->n[i - 1];
		i--;
	}
	stack->n[i] = buf;
}

void	reverse_rotate_r(t_stack *a, t_stack *b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	printf("rrr\n");
}
