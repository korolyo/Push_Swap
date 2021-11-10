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

int64_t	*presorted_array(t_data *data, int64_t *min, int64_t *max)
{
	int64_t	*arr;
	int64_t	len;
	t_dlist	*tmp;

	tmp = data->stack_a;
	len = 0;
	*min = tmp->value;
	*max = tmp->value;
	while (tmp != NULL)
	{
		if (tmp->value > *max)
			*max = tmp->value;
		if (tmp->value < *min)
			*min = tmp->value;
		tmp = tmp->next;
	}
	arr = ft_calloc(sizeof(int), (len + 1));
	tmp = data->stack_a;
	while (tmp != NULL)
	{
		arr[len] = tmp->value;
		tmp = tmp->next;
		len++;
	}
	arr = bubble_sort(arr, data->size_a);
	return (arr);
}
