/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pick_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nucieda <nucieda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:14:18 by nucieda           #+#    #+#             */
/*   Updated: 2023/01/25 15:16:14 by nucieda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pick_sort(t_stack *a, t_stack *b, int size)
{
	int	count;
	int push_count;
	int	min_index;

	count = 0;
	push_count = 0;
	print_stacks(*a, *b);
	while(size-- && a->size)
	{
		min_index = find_min(a);
		count += min_to_top(a, min_index, 1);
		pa(a, b);
		count++;
		push_count++;
		print_stacks(*a, *b);
	}
	while(push_count--)
	{
		pb(a, b);
		count++;
		print_stacks(*a, *b);
	}
	return (count);
}

int	pick_sort_reverse(t_stack *b, t_stack *a, int size)
{
	int	count;

	count = 0;
	print_stacks(*a, *b);
	while(size-- && b->size)
	{
		count += max_to_top(b, find_max(b), 0);
		pb(a, b);
		count++;
		print_stacks(*a, *b);
	}
	/*
	while(push_count--)
	{
		pa(a, b);
		count++;
		print_stacks(*a, *b);
	}
	*/
	return (count);
}