/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 12:00:30 by acollin           #+#    #+#             */
/*   Updated: 2021/10/09 12:00:40 by acollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_b(t_data *data, int64_t min, int64_t med, int64_t max)
{
	t_dlist	*head;
	int		count;

	count = 0;
	head = data->stack_a;
	while (42)
	{
		if (data->stack_a->value != min && data->stack_a->value != max)
		{
			if (data->stack_a->value < med)
				pb(data, &data->stack_a, &data->stack_b);
			else
			{
				pb(data, &data->stack_a, &data->stack_b);
				rb(&data->stack_b);
			}
		}
		else if (count != 2)
		{
			ra(&data->stack_a);
			count++;
		}
		else
			break ;
	}
}

int64_t	find_rotations_to_elem(t_dlist *stack, uint32_t size, int64_t min)
{
	int64_t	count;
	t_dlist	*tmp;

	if (stack->value == min)
		return (0);
	count = 1;
	tmp = stack->next;
	while (tmp != NULL)
	{
		if (tmp->value == min)
			break ;
		tmp = tmp->next;
		++count;
	}
	if (count < size - count)
		return (count);
	return (count - size);
}

void	full_sort(t_data *data)
{
	int64_t	min;
	int64_t	med;
	int64_t	max;
	int64_t	*arr;
	int64_t	rotate_a;

	arr = presort_ar(data, &min, &max, &med);
	while (data->stack_a->value != med)
		ra(&data->stack_a);
	push_to_b(data, min, med, max);
	if (data->stack_a->value == max)
		ra(&data->stack_a);
	while (data->stack_b != NULL)
	{
		push_to_a(data);
	}
	rotate_a = find_rotations_to_elem(data->stack_a, data->size_a, min);
	stack_rotations(data, rotate_a, 0);
}
