/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nucieda <nucieda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 16:07:32 by nucieda-          #+#    #+#             */
/*   Updated: 2023/01/26 12:15:17 by nucieda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *a, t_stack *b)
{
	int	i;

	if (a->s)
	{
		i = b->s;
		while (i > 0)
		{
			b->n[i] = b->n[i - 1];
			i--;
		}
		b->n[0] = a->n[0];
		while (i < a->s)
		{
			a->n[i] = a->n[i + 1];
			i++;
		}
		a->s--;
		b->s++;
		printf("pb\n");
	}
	else
		printf("pb failed with:\n");
}

void	pb(t_stack *a, t_stack *b)
{
	int	i;

	if (b->s)
	{
		i = a->s;
		while (i > 0)
		{
			a->n[i] = a->n[i - 1];
			i--;
		}
		a->n[0] = b->n[0];
		while (i < b->s)
		{
			b->n[i] = b->n[i + 1];
			i++;
		}
		b->s--;
		a->s++;
		printf("pa\n");
	}
	else
		printf("pa failed with:\n");
}
