/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_min_max.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nucieda <nucieda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 03:56:11 by nucieda           #+#    #+#             */
/*   Updated: 2023/01/25 15:16:19 by nucieda          ###   ########.fr       */
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
	min = stack->nums[0];
	size = stack->size - 1;
	while (size--)
	{
		if(stack->nums[i] < min)
		{
			min = stack->nums[i];
			index = i;
		}
		i++;
	}
	return (index);
}

int	min_to_top(t_stack *stack, int	min_index, int s)
{
	int	count;

	count = 0;
	if (min_index > stack->size / 2)
	{
		while(min_index++ != stack->size)
			{
				if (s == 1)
					rra(stack);
				else
					rrb(stack);
				count++;
			}
		return (count);
	}
	else
	{
		while (min_index--)
		{
			if (s == 1)
				ra(stack);
			else
				rb(stack);
			count++;
		}
		return (count);
	}
}

int find_max(t_stack *stack)
{
	int	i;
	int	index;
	int	max;
	int	size;

	i = 1;
	index = 0;
	max = stack->nums[0];
	size = stack->size - 1;
	while (size--)
	{
		if(stack->nums[i] > max)
		{
			max = stack->nums[i];
			index = i;
		}
		i++;
	}
	return (index);
}

int	max_to_top(t_stack *stack, int	max_index, int s)
{
	int	count;

	count = 0;
	if (max_index > stack->size / 2)
	{
		while(max_index++ != stack->size)
			{
				if (s == 1)
					rra(stack);
				else
					rrb(stack);
				count++;
			}
		return (count);
	}
	else
	{
		while (max_index--)
		{
			if (s == 1)
				ra(stack);
			else
				rb(stack);
			count++;
		}
		return (count);
	}
}