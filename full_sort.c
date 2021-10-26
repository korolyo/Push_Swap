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

void	find_min_max_mid(t_data *data, int64_t *min, int64_t *med, int64_t *max)
{
	min = &data->stack_a->value;
	med = &data->stack_a->value;
	max = &data->stack_a->value;
	while (data->stack_a->next != NULL)
	{
		if (&data->stack_a->value > max)
			max = &data->stack_a->value;
		if (&data->stack_a->value < min)
			min = &data->stack_a->value;
		data->stack_a = data->stack_a->next;
	}
}

void	find_median(t_data *data)
{
	while (data->stack_a->next != NULL)
	{

		data->stack_a = data->stack_a->next;
	}
}

void	push_to_st_b(t_data *data, int64_t *min, int64_t *med, int64_t *max)
{
	while(data->stack_a->next != NULL)
	{
		if (data->stack_a->value < med)
			ft_pab(&data->stack_a, &data->stack_b);
		else
		{
			ft_pab(&data->stack_a, &data->stack_b);
			ft_rab(&data->stack_b);
		}
	}
}

void	give_scores(t_data *data)
{
	data->stack_a->score = 0;
}

void	final_rotations(t_data *data)
{
	ft_ra(&data->stack_a);
}

void	full_sort(t_data *data)
{
	int64_t	min;
	int64_t	med;
	int64_t	max;

	find_min_max_mid(data, &min, &med, &max);
	push_to_st_b(data, &min, &med, &max);
	give_scores(data);
	final_rotations(data);
}
