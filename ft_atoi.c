/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nucieda- <nucieda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 16:21:00 by nucieda-          #+#    #+#             */
/*   Updated: 2021/12/20 02:01:09 by nucieda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	ft_atoi(const char *ptr)
{
	int	i;
	int	num;
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
