/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nucieda <nucieda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 15:02:06 by nucieda           #+#    #+#             */
/*   Updated: 2023/01/26 12:15:47 by nucieda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stack *a);
void	sort_small(t_stack *a, t_stack *b);

void	sort_small_stack(t_stack *a, t_stack *b)
{
	if (a->s == 3)
		sort_3(a);
	else if (a->s == 2)
		sa(a);
	else
		sort_small(a, b);
}

void	sort_3(t_stack *a)
{
	if (sorted(a))
		return ;
	if (a->n[0] < a->n[1])
	{
		rra(a);
		if (a->n[1] < a->n[0])
			sa(a);
	}
	else
	{
		if (a->n[0] > a->n[2])
		{
			if (a->n[1] > a->n[2])
			{
				sa(a);
				rra(a);
			}
			else
				ra(a);
		}
		else
			sa(a);
	}
}

void	sort_small(t_stack *a, t_stack *b)
{
	int	i;

	push_to_b(a, b, a->s - 3);
	sort_3(a);
	while (b->s)
	{
		i = 0;
		if (!(b->n[0] < a->n[0] && b->n[0] > a->n[a->s - 1]))
		{
			i++;
			while (!(b->n[0] < a->n[i] && b->n[0] > a->n[i - 1]) && i < a->s)
				i++;
		}
		if (i == a->s)
			num_to_top(a, find_min(a), 1);
		else if (i <= (a->s / 2))
			rotate_a(a, i);
		else
		{
			i = a->s - i;
			rrotate_a(a, i);
		}
		pb(a, b);
	}
	num_to_top(a, find_min(a), 1);
}
