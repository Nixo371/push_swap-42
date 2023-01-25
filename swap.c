/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nucieda <nucieda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 16:07:01 by nucieda-          #+#    #+#             */
/*   Updated: 2022/12/26 14:18:03 by nucieda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *stack)
{
	int	buf;
	if (stack->size <= 1)
		return;
	buf = stack->nums[0];
	stack->nums[0] = stack->nums[1];
	stack->nums[1] = buf;
	printf("sa\n");
}

void	sb(t_stack *stack)
{
	int	buf;
	if (stack->size <= 1)
		return;
	buf = stack->nums[0];
	stack->nums[0] = stack->nums[1];
	stack->nums[1] = buf;
	printf("sa\n");
}

void	swap(t_stack *stack)
{
	int	buf;
	if (stack->size <= 1)
		return;
	buf = stack->nums[0];
	stack->nums[0] = stack->nums[1];
	stack->nums[1] = buf;
}

void	ss(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
	printf("ss\n");
}
