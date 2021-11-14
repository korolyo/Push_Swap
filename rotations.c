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
	while (*rotate_a > 0)
	{
		ra(&data->stack_a);
		(*rotate_a)--;
	}
	while (*rotate_b > 0)
	{
		rb(&data->stack_b);
		(*rotate_a)--;
	}
	while (*rotate_a < 0)
	{
		ra(&data->stack_a);
		(*rotate_a)++;
	}
	while (*rotate_b < 0)
	{
		rb(&data->stack_b);
		(*rotate_b)++;
	}
}

void	stack_rotations(t_data *data, int64_t *rotate_a,  int64_t *rotate_b)
{
	paired_rotations(data, rotate_a, rotate_b);
	lone_rotations(data, rotate_a, rotate_b);
}

void	final_rotations(t_dlist *stack_a)
{
//	t_dlist	*tmp_head;
//
//	tmp_head = stack_a;
//	while (tmp_head != NULL)
//		tmp_head = tmp_head->next;
	while (is_sorted(stack_a) == 0)
	{
		ra(&stack_a);
	}
}
