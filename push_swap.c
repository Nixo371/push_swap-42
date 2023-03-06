/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nucieda <nucieda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 15:54:38 by nucieda-          #+#    #+#             */
/*   Updated: 2023/03/06 16:34:31 by nucieda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	
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
		if (!make_stack(a, argv))
			return (0);
		if (repeat(a) || sorted(a) || numbers(argv))
			return (error_check(a, argv));
		if (argc <= 6)
			sort_small_stack(a, b);
		else
			sort_big_stack(a, b);
	}
	return (0);
}

static int	ft_calculate(char n)
{
	char	*base;
	int		i;

	base = "0123456789";
	i = 0;
	while (n != base[i])
	{
		i++;
	}
	return (i);
}

long int	ft_long_atoi(const char *ptr)
{
	int	i;
	long int	num;
	int	neg;

	i = 0;
	num = 0;
	neg = 1;
	while (ptr[i] == ' ' || (ptr[i] >= 9 && ptr[i] <= 13))
		i++;
	if (ptr[i] == '+')
		i++;
	else if (ptr[i] == '-')
	{
		neg *= -1;
		i++;
	}
	while (ptr[i] != '\0')
	{
		if (ptr[i] < '0' || ptr[i] > '9')
			return (num * neg);
		num = (num * 10) + ft_calculate(ptr[i]);
		i++;
	}
	return (num * neg);
}

int make_stack(t_stack *a, char **argv)
{
	int 		i;
	long int	input;

	i = -1;
	while (++i < a->s)
	{
		input = ft_long_atoi(argv[i + 1]);
		if (input > INT_MAX || input < INT_MIN)
		{
			ft_putstr_fd("Error\n", STDOUT_FILENO);
			return (0);
		}
		a->n[i] = input;	
	}
	return (1);
}