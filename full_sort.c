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
				pb(&data->stack_a, &data->stack_b);
			else
			{
				pb(&data->stack_a, &data->stack_b);
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

void	full_sort(t_data *data)
{
	int64_t	min;
	int64_t	med;
	int64_t	max;
	int64_t	*arr;

	arr = presorted_array(data, &min, &max);
	med = arr[(max - min)/ 2];
	while (data->stack_a->value != med)
		ra(&data->stack_a);
	push_to_b(data, min, med, max);
	if (data->stack_a->value == max)
		ra(&data->stack_a);
	while (data->stack_b != NULL)
		push_to_a(data);
	printf("stack_a -> ");
	print(data->stack_a);
	printf("\n");
//	ra(&data->stack_a);
//	ra(&data->stack_a);
	final_rotations(data->stack_a);
}
