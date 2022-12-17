/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nucieda- <nucieda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 16:07:32 by nucieda-          #+#    #+#             */
/*   Updated: 2022/12/17 17:34:15 by nucieda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_stack a, t_stack b)
{
	int	i;

	if (b.nums[0])
	{
		i = a.size - 1;
		while (i > 0)
		{
			a.nums[i] = a.nums[i - 1];
			i--;
		}
		a.nums[0] = b.nums[0];
		while (i < b.size)
			b.nums[i] = b.nums[i + 1];
	}
}

void	push_b(t_stack a, t_stack b)
{
	int	i;

	if (a.nums[0])
	{
		i = b.size - 1;
		while (i > 0)
		{
			b.nums[i] = b.nums[i - 1];
			i--;
		}
		b.nums[0] = a.nums[0];
		while (i < a.size)
			a.nums[i] = a.nums[i + 1];
	}
}
