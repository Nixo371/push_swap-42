/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nucieda <nucieda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 16:07:25 by nucieda-          #+#    #+#             */
/*   Updated: 2023/01/28 16:30:33 by nucieda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *stack)
{
	int	buf;
	int	i;

	i = 0;
	buf = stack->n[0];
	while (i < stack->s - 1)
	{
		stack->n[i] = stack->n[i + 1];
		i++;
	}
	stack->n[i] = buf;
	printf("ra\n");
}

void	rb(t_stack *stack)
{
	int	buf;
	int	i;

	i = 0;
	buf = stack->n[0];
	while (i < stack->s - 1)
	{
		stack->n[i] = stack->n[i + 1];
		i++;
	}
	stack->n[i] = buf;
	printf("rb\n");
}

void	rotate(t_stack *stack)
{
	int	buf;
	int	i;

	i = 0;
	buf = stack->n[0];
	while (i < stack->s - 1)
	{
		stack->n[i] = stack->n[i + 1];
		i++;
	}
	stack->n[i] = buf;
}

void	rr(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
	printf("rr\n");
}
