/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nucieda- <nucieda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 17:43:41 by nucieda-          #+#    #+#             */
/*   Updated: 2022/12/17 17:50:22 by nucieda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stacks(t_stack a, t_stack b)
{
	int	width;
	int	height;

	width = 11;
	height = a.size;
	if (b.size > height)
		height = b.size;
}