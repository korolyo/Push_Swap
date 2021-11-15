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
	while (i < size_a - 2)
	{
		j = i + 1;
		while (j < size_a - 1)
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

int64_t	*presort_arr(t_data *data, int64_t *min, int64_t *max, int64_t *med)
{
	int64_t	*arr;
	int64_t	count;
//	int64_t	count1;
	t_dlist	*tmp;

	tmp = data->stack_a;
	count = 0;
	*max = tmp->value;
	while (tmp != NULL)
	{
		if (tmp->value > *max)
			*max = tmp->value;
		count++;
		tmp = tmp->next;
	}
	arr = ft_calloc(sizeof(int), count + 1);
	tmp = data->stack_a;
	count = 0;
	while (tmp != NULL)
	{
		arr[count] = tmp->value;
		count++;
		tmp = tmp->next;
	}
	arr = bubble_sort(arr, data->size_a);
//	count1 = 0;
//	while (count1 < count)
//	{
//		printf("%lld\n", arr[count1]);
//		count1++;
//	}
	*min = arr[0];
	*med = arr[count / 2];
	return (arr);
}
