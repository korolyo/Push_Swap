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

void	rotate_stacks(t_data *data, t_dlist *bmin, int64_t position)
{
	int64_t	rotate_a;
	int64_t	rotate_b;

	rotate_a = a_rotations(data, bmin->value);
	if (position < data->size_b - position)
		rotate_b = position;
	else
		rotate_b = position - data->size_b;
	stack_rotations(data, rotate_a, rotate_b);
	pa(data, &data->stack_b, &data->stack_a);
}

t_dlist	*find_bmin_score(t_data *data, int64_t *position)
{
	t_dlist	*tmp_b;
	t_dlist	*bmin;
	int64_t	count;

	*position = 0;
	count = 1;
	bmin = data->stack_b;
	tmp_b = data->stack_b->next;
	while (count < data->size_b)
	{
		if (tmp_b->score < bmin->score)
		{
			*position = count;
			bmin = tmp_b;
		}
		tmp_b = tmp_b->next;
		count++;
	}
	return (bmin);
}

int64_t	a_rotations(t_data *data, int64_t value)
{
	t_dlist	*tmp;
	t_dlist	*last;
	int64_t	count;

	count = 0;
	tmp = data->stack_a;
	last = data->stack_a;
	while (last->next != NULL)
		last = last->next;
	while ((value > tmp->value || last->value > value) && tmp)
	{
//		printf("tmp->value = %lld\n", tmp->value);
//		printf("check a rot\n");
		last = tmp;
		tmp = tmp->next;
		++count;
	}
//	printf("count = %lld\n", count);
	if (count < data->size_a - count - 1)
		return (count);
	return (count - data->size_a);
}

void	find_b_score(t_data *data, t_dlist *curr, int64_t count)
{
	int64_t	rotate_a;
	int64_t	rotate_b;

	rotate_a = a_rotations(data, curr->value);
	if (count < data->size_b - count)
		rotate_b = count;
	else
		rotate_b = count - data->size_b;
	if ((rotate_a > 0 && rotate_b > 0)
		|| (rotate_a < 0 && rotate_b < 0))
	{
		if (my_abs(rotate_a) > my_abs(rotate_b))
			curr->score = my_abs(rotate_a);
		else
			curr->score = my_abs(rotate_b);
	}
	else
		curr->score = my_abs(rotate_a) + my_abs(rotate_b);
//	printf("current->score = %lld\n", curr->score);
}

void	push_to_a(t_data *data)
{
	int64_t	count;
	int64_t	position;
	t_dlist	*curr_elem;
	t_dlist	*bmin;

	count = 0;
	curr_elem = data->stack_b;
	while (count < data->size_b)
	{
		find_b_score(data, curr_elem, count);
		curr_elem = curr_elem->next;
		count++;
	}
	bmin = find_bmin_score(data, &position);
	rotate_stacks(data, bmin, position);
}
