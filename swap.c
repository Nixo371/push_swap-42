/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nucieda- <nucieda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 16:07:01 by nucieda-          #+#    #+#             */
/*   Updated: 2022/12/17 16:46:41 by nucieda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack stack)
{
	int	buf;

	buf = stack.nums[0];
	stack.nums[0] = stack.nums[1];
	stack.nums[1] = buf;
}

void	swap_b(t_stack stack)
{
	int	buf;

	buf = stack.nums[0];
	stack.nums[0] = stack.nums[1];
	stack.nums[1] = buf;
}

void	swap_s(t_stack a, t_stack b)
{
	swap_a(a);
	swap_a(b);
}
