/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nucieda <nucieda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 15:54:38 by nucieda-          #+#    #+#             */
/*   Updated: 2023/01/25 15:06:20 by nucieda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//! big_stack.c!!!

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		i;

	i = -1;
	if (argc == 2)
	{
		//printf("Solo hay un numero\n");
		return (0);
	}
	else if (argc == 1)
		return(0);
	else
	{
		a = malloc(sizeof(t_stack));
		b = malloc(sizeof(t_stack));
		a->nums = calloc(argc - 1, sizeof(int));
		b->nums = calloc(argc - 1, sizeof(int));

		a->size = argc - 1;
		b->size = 0;
		while(++i < a->size)
			a->nums[i] = ft_atoi(argv[i + 1]);
		if (sorted(a))
		{
			//printf("It is already sorted\n");
			return (0);
		}
		else if (repeat(a))
		{
			//printf("no repeats\n");
			return (0);
		}
		if (argc <= 6)
			i = sort_small_stack(a, b);
		else
			i = sort_big_stack(a, b);
		//printf("%d iterations\n", i);
		//print_stacks(*a, *b);
		//if (sorted(a))
		//	printf("ez\n");
	}
	return (0);
}

int	sorted(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack->size - 1 > i)
	{
		if (stack->nums[i] > stack->nums[i + 1])
				return(0);
		i++;
	}
	return(1);
}

int	repeat(t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	j = 1;

	while (i < stack->size)
	{
		while (j < stack->size)
		{
			if (stack->nums[i] == stack->nums[j])
				return (1);
			j++;
		}
		i++;
		j = i + 1;
	}
	return (0);
}