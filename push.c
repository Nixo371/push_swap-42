/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nucieda <nucieda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 16:07:32 by nucieda-          #+#    #+#             */
/*   Updated: 2023/01/24 12:19:49 by nucieda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *a, t_stack *b)
{
	int	i;

	if (a->size)
	{
		i = b->size;
		while (i > 0)
		{
			b->nums[i] = b->nums[i - 1];
			i--;
		}
		b->nums[0] = a->nums[0];
		while (i < a->size)
			{
				a->nums[i] = a->nums[i + 1];
				i++;
			}
		a->size--;
		b->size++;
		printf("pb\n");
	}
	else
	{
		printf("pb failed with:\n");
		print_stacks(*a, *b);
	}
}

void	pb(t_stack *a, t_stack *b)
{
	int	i;

	if (b->size)
	{
		i = a->size;
		while (i > 0)
		{
			a->nums[i] = a->nums[i - 1];
			i--;
		}
		a->nums[0] = b->nums[0];
		while (i < b->size)
			{
				b->nums[i] = b->nums[i + 1];
				i++;
			}
		b->size--;
		a->size++;
		printf("pa\n");
	}
	else
	{
		printf("pa failed with:\n");
		print_stacks(*a, *b);
	}
	
}
