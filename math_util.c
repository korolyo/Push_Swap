/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 12:00:30 by acollin           #+#    #+#             */
/*   Updated: 2021/11/18 19:36:58 by acollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int64_t	my_abs(int64_t value)
{
	if (value >= 0)
		return (value);
	else
		return ((-1) * value);
}

int	isMax(t_dlist *stack_a, int64_t max)
{
	t_dlist	*tmp;

	if (stack_a->value > max)
		return (0);
	tmp = stack_a->next;
	while (tmp != NULL)
	{
		if (tmp->value > max)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
