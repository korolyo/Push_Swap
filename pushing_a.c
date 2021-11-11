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

void	count_rotations_for_every_element(t_data *data, int64_t *rotate_a,
										  int64_t *rotate_b)
{
	t_dlist	*tmp_a;
	t_dlist *tmp_b;
	int64_t	count_a;
	int64_t	count_b;

	count_a = 0;
	count_b = 0;
	tmp_a = data->stack_a;
	tmp_b = data->stack_b;
	while (count_b < data->size_a)
	{
		tmp_a = data->stack_a;
		while (tmp_b->value > tmp_a->value)
		{
			*rotate_a++;
			tmp_a = tmp_a->next;
		}
		if ()
		count_b++;
	}
}

void	push_to_a(t_data *data)
{
	int64_t	count;
	int64_t	rotate_a;
	int64_t	rotate_b;
	t_dlist	*b_elem;

	while (count < data->size_b)
	{
		count_rotations_for_every_element(data, &rotate_a, &rotate_b);
		count++;
	}
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
