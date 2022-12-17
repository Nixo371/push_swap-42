/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nucieda- <nucieda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 16:07:25 by nucieda-          #+#    #+#             */
/*   Updated: 2022/12/17 17:41:52 by nucieda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack stack)
{
	int	buf;
	int	i;

	i = 0;
	buf = stack.nums[0];
	while (i < stack.size - 1)
	{
		stack.nums[i] = stack.nums[i + 1];
		i++;
	}
	stack.nums[i] = buf;
}

void	rotate_r(t_stack a, t_stack b)
{
	rotate(a);
	rotate(b);
}
