/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nucieda- <nucieda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 16:07:14 by nucieda-          #+#    #+#             */
/*   Updated: 2022/12/17 17:43:18 by nucieda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_stack stack)
{
	int	buf;
	int	i;

	i = stack.size - 1;
	buf = stack.nums[i];
	while (i > 0)
	{
		stack.nums[i] = stack.nums[i - 1];
		i--;
	}
	stack.nums[i] = buf;
}

void	reverse_rotate_r(t_stack a, t_stack b)
{
	reverse_rotate(a);
	reverse_rotate(b);
}
