/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nucieda <nucieda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 15:54:38 by nucieda-          #+#    #+#             */
/*   Updated: 2023/03/06 10:47:51 by nucieda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		i;

	i = -1;
	if (argc <= 2)
		return (0);
	else
	{
		a = malloc(sizeof(t_stack));
		b = malloc(sizeof(t_stack));
		a->n = calloc(argc - 1, sizeof(int));
		b->n = calloc(argc - 1, sizeof(int));
		a->s = argc - 1;
		b->s = 0;
		while (++i < a->s)
			a->n[i] = ft_atoi(argv[i + 1]);
		if (repeat(a) || sorted(a) || numbers(argv))
			return (error_check(a, argv));
		if (argc <= 6)
			sort_small_stack(a, b);
		else
			sort_big_stack(a, b);
	}
	return (0);
}

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