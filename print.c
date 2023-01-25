/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nucieda <nucieda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 17:43:41 by nucieda-          #+#    #+#             */
/*   Updated: 2023/01/25 10:19:21 by nucieda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_number(int number);

int	printer = 0;

void	print_stacks(t_stack a, t_stack b)
{
	int	height;
	int i;

	if (!printer)
		return;
	height = a.size;
	if (b.size > height)
		height = b.size;
	i = 0;
	while (i < height)
	{
		if (a.size <= i)
			printf("     -     ");
		else
			print_number(a.nums[i]);
		printf("\t");
		if (b.size <= i)
			printf("     -     ");
		else
			print_number(b.nums[i]);
		printf("\n");
		i++;
	}
	printf("-----------\t-----------\n");
	printf("     a     \t     b     \n");
	printf("\n\n");
}

void	print_number(int number)
{
	int	spaces;
	int	div;

	spaces = 11;
	div = 1;
	while(number / div)
	{
		div *= 10;
		spaces--;
	}
	if (number <= 0)
		spaces--;
	if (spaces % 2)
		{
			printf(" ");
			spaces--;
		}
	spaces /= 2;
	div = spaces;
	while (spaces-- > 0)
		printf(" ");
	printf("%d", number);
	while (div-- > 0)
		printf(" ");
}