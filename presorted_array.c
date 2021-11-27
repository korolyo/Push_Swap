/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presorted_array.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 12:00:30 by acollin           #+#    #+#             */
/*   Updated: 2021/10/09 12:00:40 by acollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int64_t	*bubble_sort(int64_t *arr, int64_t size_a)
{
	int64_t	i;
	int64_t	j;
	int64_t	tmp;

	i = 0;
	j = 0;
	while (i < size_a)
	{
		j = i + 1;
		while (j < size_a)
		{
			if (arr[i] > arr[j])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
			j++;
		}
		i++;
	}
	return (arr);
}

int64_t	mmm_values(t_data *data, int64_t *min, int64_t *max)
{
	t_dlist	*tmp;
	int64_t	count;

	count = 0;
	tmp = data->stack_a;
	while (tmp != NULL)
	{
		if (tmp->value > *max)
			*max = tmp->value;
		else if (tmp->value < *min)
			*min = tmp->value;
		count++;
		tmp = tmp->next;
	}
	return (count);
}

int64_t	*presort_ar(t_data *data, int64_t *min, int64_t *max, int64_t *med)
{
	int64_t	*arr;
	int64_t	count;
	t_dlist	*tmp;

	tmp = data->stack_a;
	count = 0;
	*max = tmp->value;
	*min = tmp->value;
	count = mmm_values(data, min, max);
	arr = ft_calloc(sizeof(int64_t), count);
	tmp = data->stack_a;
	count = 0;
	while (tmp != NULL)
	{
		arr[count] = tmp->value;
		count++;
		tmp = tmp->next;
	}
	arr = bubble_sort(arr, data->size_a);
	*med = arr[count / 2];
	return (arr);
}
