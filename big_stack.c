/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nucieda <nucieda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 00:04:09 by nucieda           #+#    #+#             */
/*   Updated: 2023/01/25 15:14:43 by nucieda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//! try to get it to work with ANY stack size (not just powers of 2)

int	sort_big_stack(t_stack *a, t_stack *b)
{
	int	count;
	int	iterations;
	int	elements;
	int	i;

	count = (a->size / 133) + 1;
	iterations = 2;
	while (count--)
		iterations *= 2;
	elements = a->size / iterations;
	i = iterations;
	while (i--) //sort [elements] stacks with pick sort, then shuffle the sorted stack to the bottom
	{
		count += push_to_b(a, b, elements);
		count += pick_sort_reverse(b, a, elements);
		count += rotate_a(a, elements);
	}
	push_to_b(a, b, a->size % iterations);
	while (iterations >= 2) //merge stacks together, making sure the first stack doesn't rotate
	{
		count += push_to_b(a, b, elements);
		count += merge_stacks(a, b, elements);
		i = (iterations / 2) - 1;
		while (i--)
		{
			count += rrotate_a(a, elements);
			count += push_to_b(a, b, elements);
			count += merge_stacks(a, b, elements);
		}
		iterations /= 2; //half the stacks
		elements *= 2; //twice the size
	}
	if (!sorted(a)) //final rotation cuz sometimes it doesnt want to play nice
		ra(a);
	count++;
	while (b->size) //go through the a stack and insert the extra bits from b smallest->biggest
	{
		count += min_to_top(b, find_min(b), 0);
		while (b->nums[0] > a->nums[0] && b->nums[0] < a->nums[find_max(a)]) //rotate until you find the spot it goes in
			{
				ra(a);
				count++;
			}
		if (b->nums[0] > a->nums[find_max(a)]) //if its the biggest one, put it in correctly
			{
				max_to_top(a, find_max(a), 1);
				ra(a);
			}
		pb(a, b);
		count++;
	}
	min_to_top(a, find_min(a), 1); //orient it correctly
	
	return (count);
}

int	merge_stacks(t_stack *a, t_stack *b, int size)
{
	int	s;
	int	e;
	int	av_size;
	int count;

	s = 0;
	e = 0;
	av_size = 0;
	while (!s)
	{
		if (a->nums[a->size - 1 - av_size] < a->nums[a->size - 2 - av_size]) //find the size of each "stack"
			s = size;
		av_size++;
	}
	while (s) // rotate through the stack, inserting elements one by one
	{
		if ((b->nums[0] > a->nums[a->size - 1]) || e == av_size || (sorted(a) && e)) 
		// e is for when the smallest value is in stack b, so it will insert it at the end (it counts and compares to stack size)
		// sorted(a) is so the very last extra goes in correctly
			{
				pb(a, b);
				s--;
			}
		else
			{
				rra(a);
				e++;
			}
		count++;
	}
	count += av_size - e;
	while (e++ < av_size) //rotate list all the way through the "stack"
		rra(a);
	return (count);
}

int	push_to_a(t_stack *a, t_stack *b, int size)
{
	int	s;

	s = size;
	while (s--)
		pb(a, b);
	return (size);
}

int	push_to_b(t_stack *a, t_stack *b, int size)
{
	int	s;

	s = size;
	while (s--)
		pa(a, b);
	return (size);
}

int	rotate_a(t_stack *a, int size)
{
	int	s;
	s = size;
	while (s--)
		ra(a);
	return (size);
}

int	rrotate_a(t_stack *a, int size)
{
	int	s;
	s = size;
	while (s--)
		rra(a);
	return (size);
}