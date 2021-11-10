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
				ft_pab(&data->stack_a, &data->stack_b);
			else
			{
				ft_pab(&data->stack_a, &data->stack_b);
				ft_rab(&data->stack_b);
			}
			print(data->stack_a);
			printf("\n");
			print(data->stack_b);
			printf("\n");
		}
		else if (count != 2)
		{
			ft_rab(&data->stack_a);
			count++;
		}
		else
			break ;
	}
}

void	score_to_elem(t_data *data, t_dlist *elem)
{
	int64_t	rotate_a;
	int64_t	rotate_b;

	rotate_a = 0;
	if (elem->value > data->stack_a->value)
		rotate_a = 0;
	rotate_b = 0;
	elem->score = my_abs(rotate_a) + my_abs(rotate_b);
}

void	push_to_a(t_data *data)
{
	int64_t	count;
	int64_t	rotate_a;
	int64_t	rotate_b;
	t_dlist	*b_elem;

	count_rotations_for_every_element;
	find_min_score;
	rotate stack_a;
	ft_pab(&min_score_elem, &data->stack_a);
//	b_elem = data->stack_b;
//	count = 0;
//	rotate_a = 0;
//	rotate_b = 0;
//	while (count < data->size_b)
//	{
//		score_to_elem(data, b_elem);
//		b_elem = b_elem->next;
//		count++;
//	}
//	stack_rotations(data, &rotate_a, &rotate_b);
//	ft_pab(&data->stack_b, &data->stack_a);
}

void	full_sort(t_data *data)
{
	int64_t	min;
	int64_t	med;
	int64_t	max;
	int64_t	*arr;

	arr = presorted_array(data, &min, &max);
	med = arr[(max - min)/ 2];
	printf("med - %lli\n", med);
	while (data->stack_a->value != med)
		ft_rab(&data->stack_a);
	push_to_b(data, min, med, max);
	if (data->stack_a->value == max)
		ft_rab(&data->stack_a);
	while (data->stack_b != NULL)
		push_to_a(data);
	final_rotations(data->stack_a);
}
