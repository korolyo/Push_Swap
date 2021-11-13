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

void	find_b_score(t_data *data, t_dlist *curr, int64_t *rotate_a,
			int64_t *rotate_b)
{
	t_dlist	*tmp_a;
	t_dlist *tmp_b;

	tmp_a = data->stack_a;
	tmp_b = data->stack_b;
	while (tmp_b)
	{
		if (curr->value == tmp_a->value)
			break ;
		(*rotate_b)++;
		tmp_b = tmp->next;

	}
}

void	push_to_a(t_data *data)
{
	int64_t	count;
	int64_t	rotate_a;
	int64_t	rotate_b;
	t_dlist	*curr_elem;

	rotate_a = 0;
	rotate_b = 0;
	curr_elem = data->stack_b;
	while (count < data->size_b)
	{
		count_rotations_for_every_element(data, &curr_elem, &rotate_a,
										  &rotate_b);
		curr_elem = curr_elem->next;
		count++;
	}
	find_bmin_score;
	rotate stacks;
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
