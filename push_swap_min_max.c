/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_min_max.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nucieda <nucieda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 03:56:11 by nucieda           #+#    #+#             */
/*   Updated: 2023/01/26 12:14:25 by nucieda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(t_stack *stack)
{
	int	i;
	int	index;
	int	min;
	int	size;

	i = 1;
	index = 0;
	min = stack->n[0];
	size = stack->s - 1;
	while (size--)
	{
		if (stack->n[i] < min)
		{
			min = stack->n[i];
			index = i;
		}
		i++;
	}
	return (index);
}

int	find_max(t_stack *stack)
{
	int	i;
	int	index;
	int	max;
	int	size;

	i = 1;
	index = 0;
	max = stack->n[0];
	size = stack->s - 1;
	while (size--)
	{
		if (stack->n[i] > max)
		{
			max = stack->n[i];
			index = i;
		}
		i++;
	}
	return (index);
}

void	num_to_top(t_stack *stack, int num_index, int s)
{
	if (num_index > stack->s / 2)
	{
		while (num_index++ != stack->s)
		{
			if (s == 1)
				rra(stack);
			else
				rrb(stack);
		}
	}
	else
	{
		while (num_index--)
		{
			if (s == 1)
				ra(stack);
			else
				rb(stack);
		}
	}
}
