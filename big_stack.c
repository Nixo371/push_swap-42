/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nucieda <nucieda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 00:04:09 by nucieda           #+#    #+#             */
/*   Updated: 2023/01/28 16:53:10 by nucieda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		calculate_stack_size(t_stack *stack);
void	sort_stacks(t_stack *a, t_stack *b, int elements, int iterations);
void	fix_stack(t_stack *a, t_stack *b);

void	sort_big_stack(t_stack *a, t_stack *b)
{
	int	iterations;
	int	elements;
	int	i;

	i = (a->s / 133) + 1;
	iterations = 2;
	while (i--)
		iterations *= 2;
	elements = a->s / iterations;
	i = iterations;
	while (i--)
	{
		push_to_b(a, b, elements);
		pick_sort(b, a, elements);
		rotate_a(a, elements);
	}
	push_to_b(a, b, a->s % iterations);
	sort_stacks(a, b, elements, iterations);
	fix_stack(a, b);
}

void	sort_stacks(t_stack *a, t_stack *b, int elements, int iterations)
{
	int	i;

	i = 0;
	while (iterations >= 2)
	{
		push_to_b(a, b, elements);
		merge_stacks(a, b, elements);
		i = (iterations / 2) - 1;
		while (i--)
		{
			rrotate_a(a, elements);
			push_to_b(a, b, elements);
			merge_stacks(a, b, elements);
		}
		iterations /= 2;
		elements *= 2;
	}
}

void	fix_stack(t_stack *a, t_stack *b)
{
	if (!sorted(a))
		ra(a);
	while (b->s)
	{
		num_to_top(b, find_min(b), 0);
		while (b->n[0] > a->n[0] && b->n[0] < a->n[find_max(a)])
			ra(a);
		if (b->n[0] > a->n[find_max(a)])
		{
			num_to_top(a, find_max(a), 1);
			ra(a);
		}
		pb(a, b);
	}
	num_to_top(a, find_min(a), 1);
}

void	merge_stacks(t_stack *a, t_stack *b, int size)
{
	int	e;
	int	av_size;

	e = 0;
	av_size = calculate_stack_size(a);
	while (size)
	{
		if ((b->n[0] > a->n[a->s - 1]) || e == av_size || (sorted(a) && e))
		{
			pb(a, b);
			size--;
		}
		else
		{
			rra(a);
			e++;
		}
	}
	while (e++ < av_size)
		rra(a);
}

int	calculate_stack_size(t_stack *stack)
{
	int	s;
	int	ssize;

	s = 0;
	ssize = 0;
	while (!s)
	{
		if (stack->n[stack->s - 1 - ssize] < stack->n[stack->s - 2 - ssize])
			s = 1;
		ssize++;
	}
	return (ssize);
}
