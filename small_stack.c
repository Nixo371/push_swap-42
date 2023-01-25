/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nucieda <nucieda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 15:02:06 by nucieda           #+#    #+#             */
/*   Updated: 2023/01/25 11:42:59 by nucieda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_3(t_stack *a);
int	sort_small(t_stack *a, t_stack *b);

int	sort_small_stack(t_stack *a, t_stack *b)
{
	int count;

	if (a->size == 3)
		count = sort_3(a);
	else if (a->size == 2)
		sa(a);
	else
		count = sort_small(a, b);
	return (count);
}

int	sort_3(t_stack *a)
{
	int count;

	count = 0;
	if (sorted(a))
		return (0);
	if (a->nums[0] < a->nums[1]) // 0, 2, x
		{
			rra(a);
			count++;
			if (a->nums[1] < a->nums[0]) // 0, 2, 1
			{
				sa(a);
				count++;
			}
		}
	else // 2, 0, x
	{
		if (a->nums[0] > a->nums[2]) // 2, 0, -1/1
		{
			if (a->nums[1] > a->nums[2]) // 2, 0, -1
			{
				sa(a);
				rra(a);
				count++;
			}
			else // 2, 0, 1
				ra(a);
		}
		else // 2, 0, 3
			sa(a);
		count++;
	}
	return (count);
}

int	sort_small(t_stack *a, t_stack *b)
{
	int	count;
	int	i;

	count = a->size - 3;
	while (a->size > 3)
		pa(a, b);
	count += sort_3(a);
	while (b->size)
	{
		//print_stacks(*a, *b);
		i = 0;
		if (!(b->nums[0] < a->nums[0] && b->nums[0] > a->nums[a->size - 1]))
		{
			i++;
			while (!(b->nums[0] < a->nums[i] && b->nums[0] > a->nums[i - 1]) && i < a->size)
				i++;
		}
		if (i == a->size)
		{
			count += min_to_top(a, find_min(a), 1);
			pb(a, b);
			count += 2;
		}
		else if (i <= (a->size / 2))
		{
			count += (i + 1);
			while (i--)
				ra(a);
			pb(a, b);
		}
		else
		{
			i = a->size - i;
			count += (i + 1);
			while (i-- > 0)
				rra(a);
			pb(a, b);
		}			
	}
	if (!sorted(a))
	{
		i = find_min(a);
		count += min_to_top(a, i, 1);
	}
	return(count);
}
