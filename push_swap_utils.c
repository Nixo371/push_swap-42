/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nucieda <nucieda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 16:09:16 by nucieda           #+#    #+#             */
/*   Updated: 2023/03/06 16:09:57 by nucieda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sorted(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack->s - 1 > i)
	{
		if (stack->n[i] > stack->n[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	repeat(t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < stack->s)
	{
		while (j < stack->s)
		{
			if (stack->n[i] == stack->n[j])
				return (1);
			j++;
		}
		i++;
		j = i + 1;
	}
	return (0);
}

int numbers(char **argv)
{
	int i;
	int j;

	i = 1;
	j = 0;
	while(argv[i])
	{
		while (argv[i][j])
		{
			if (!(ft_isdigit(argv[i][j]) || argv[i][j] == '-'))
				return (1);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

int	error_check(t_stack *a, char **argv)
{
	if (repeat(a) || numbers(argv))
	{
		ft_putstr_fd("Error\n", STDOUT_FILENO);
		return (0);
	}
	if (sorted(a))
		return (0);
	return (0);
}

