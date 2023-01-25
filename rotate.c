/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nucieda <nucieda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 16:07:25 by nucieda-          #+#    #+#             */
/*   Updated: 2022/12/26 14:14:50 by nucieda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *stack)
{
	int	buf;
	int	i;

	i = 0;
	buf = stack->nums[0];
	while (i < stack->size - 1)
	{
		stack->nums[i] = stack->nums[i + 1];
		i++;
	}
	stack->nums[i] = buf;
	printf("ra\n");
}

void	rb(t_stack *stack)
{
	int	buf;
	int	i;

	i = 0;
	buf = stack->nums[0];
	while (i < stack->size - 1)
	{
		stack->nums[i] = stack->nums[i + 1];
		i++;
	}
	stack->nums[i] = buf;
	printf("rb\n");
}

void	rotate(t_stack *stack)
{
	int	buf;
	int	i;

	i = 0;
	buf = stack->nums[0];
	while (i < stack->size - 1)
	{
		stack->nums[i] = stack->nums[i + 1];
		i++;
	}
	stack->nums[i] = buf;
}

void	rr(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
	printf("rr\n");
}
