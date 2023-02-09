/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nucieda <nucieda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 12:25:14 by nucieda           #+#    #+#             */
/*   Updated: 2023/01/26 12:26:07 by nucieda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_a(t_stack *a, t_stack *b, int s)
{
	while (s--)
		pb(a, b);
}

void	push_to_b(t_stack *a, t_stack *b, int s)
{
	while (s--)
		pa(a, b);
}

void	rotate_a(t_stack *a, int s)
{
	while (s--)
		ra(a);
}

void	rrotate_a(t_stack *a, int s)
{
	while (s--)
		rra(a);
}
