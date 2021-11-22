/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 12:00:30 by acollin           #+#    #+#             */
/*   Updated: 2021/10/09 12:00:40 by acollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	paired_rotations(t_data *data, int64_t *rotate_a, int64_t *rotate_b)
{
	while (*rotate_a > 0 && *rotate_b > 0)
	{
		rr(&data->stack_a, &data->stack_b);
		(*rotate_a)--;
		(*rotate_b)--;
	}
	while (*rotate_a < 0 && *rotate_b < 0)
	{
		rrr(&data->stack_a, &data->stack_b);
		(*rotate_a)++;
		(*rotate_b)++;
	}
}

void	lone_rotations(t_data *data, int64_t *rotate_a, int64_t *rotate_b)
{
	while (*rotate_b < 0)
	{
		reverse_rotate(&data->stack_b);
		(*rotate_b)++;
		ft_putstr_fd("rrb\n", 1);
	}
	while (*rotate_b > 0)
	{
		rotate(&data->stack_b);
		(*rotate_b)--;
		ft_putstr_fd("rb\n", 1);
	}
	while (*rotate_a < 0)
	{
		reverse_rotate(&data->stack_a);
		(*rotate_a)++;
		ft_putstr_fd("rra\n", 1);
	}
	while (*rotate_a > 0)
	{
		rotate(&data->stack_a);
		(*rotate_a)--;
		ft_putstr_fd("ra\n", 1);
	}
}

void	stack_rotations(t_data *data, int64_t rotate_a, int64_t rotate_b)
{
	paired_rotations(data, &rotate_a, &rotate_b);
	lone_rotations(data, &rotate_a, &rotate_b);
}
