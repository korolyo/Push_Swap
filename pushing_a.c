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

void	rotate_stacks(t_data *data, t_dlist *bmin)
{
	t_dlist	*tmp_a;
	t_dlist *tmp_b;
	int64_t	count;
	int64_t	*rotate_a;
	int64_t	*rotate_b;

	tmp_b = data->stack_b;
	tmp_a = data->stack_a;
	count = 0;
	rotate_a = 0;
	rotate_b = 0;
	while (count < data->size_b)
	{
		if (bmin->score == tmp_b->score)
			break ;
		tmp_b = tmp_b->next;
		count++;
	}
	if (count <= data->size_b - count)
		*rotate_b = count;
	else if (count > data->size_b - count)
		*rotate_b = count - data->size_b;
	count = 0;
	while (bmin->value > tmp_a->value)
	{
		if (count <= data->size_a - count)
			*rotate_a = count;
		else if (count > data->size_a - count)
			*rotate_a = count - data->size_a;
		tmp_a = tmp_a->next;
		count++;
	}
	stack_rotations(data, rotate_a, rotate_b);
}

t_dlist	*find_bmin_score(t_data *data)
{
	t_dlist *tmp_b;
	t_dlist *bmin;
	int64_t count;

	count = 0;
	tmp_b = data->stack_b;
	bmin = data->stack_b;
	while (count < data->size_b)
	{
		if (tmp_b->score < tmp_b->next->score)
			bmin = tmp_b;
		tmp_b = tmp_b->next;
		count++;
	}
	return (bmin);
}

void	find_b_score(t_data *data, t_dlist *curr, int64_t *rotate_a)
{
	t_dlist	*tmp_a;
	t_dlist *tmp_b;
	int64_t	count;

	count = 0;
	tmp_a = data->stack_a;
	tmp_b = data->stack_b;
	while (curr->value > tmp_a->value)
	{
		if (count <= data->size_a - count)
			*rotate_a = count;
		else if (count > data->size_a - count)
			*rotate_a = count - data->size_a;
		tmp_a = tmp_a->next;
		count++;
	}
	count = 0;
	while (count < data->size_b)
	{
		if (curr->value == data->stack_b->value)
		{
			if (count <= data->size_b - count)
				data->stack_b->score = count + my_abs(*rotate_a);
			else if (count > data->size_b - count)
				data->stack_b->score = count - data->size_b + my_abs(*rotate_a);
		}
		count++;
		data->stack_b = data->stack_b->next;
	}
	data->stack_b = tmp_b;
}

void	push_to_a(t_data *data)
{
	int64_t	count;
	int64_t	rotate_a;
	int64_t	rotate_b;
	t_dlist	*curr_elem;
	t_dlist *bmin;

	rotate_a = 0;
	rotate_b = 0;
	count = 0;
	curr_elem = data->stack_b;
	while (count < data->size_b)
	{
		printf("check11");
		find_b_score(data, curr_elem, &rotate_a);
		curr_elem = curr_elem->next;
		count++;
		rotate_a = 0;
		rotate_b = 0;
	}
	bmin = find_bmin_score(data);
//	rotate_stacks(data, bmin);
	ft_pab(&data->stack_b, &data->stack_a);
//	data->size_b--;
//	data->size_a++;
}
