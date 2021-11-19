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
//	printf("rotate_a in rotate_stacks = %lld\n", rotate_a);
    if (position < data->size_b - position)
        rotate_b = position;
    else
        rotate_b = position - data->size_b;
//	printf("rotate_b in rotate_stacks = %lld\n", rotate_b);
    stack_rotations(data, &rotate_a, &rotate_b);
}

t_dlist	*find_bmin_score(t_data *data, int64_t *position)
{
	t_dlist *tmp_b;
	t_dlist *bmin;
    int64_t count;

	*position = 0;
    count = 1;
	tmp_b = data->stack_b->next;
	bmin = data->stack_b;
	while (count < data->size_b - 1)
	{
//		printf("indide bmin\n");
		if (tmp_b->score < tmp_b->next->score)
        {
            *position = count;
            bmin = tmp_b;
        }
		tmp_b = tmp_b->next;
		count++;
	}
	return (bmin);
}

int64_t a_rotations(t_data *data, int64_t value)
{
    t_dlist *tmp;
    t_dlist *last;
    int64_t count;

    count = 0;
    tmp = data->stack_a;
    last = data->stack_a;
    while (last->next != NULL)
        last = last->next;
    while ((value > tmp->value || last->value > value) && tmp->next != NULL)
    {
		last = tmp;
		tmp = tmp->next;
        count++;
    }
//	printf("count in a_rot = %lld\n", count);
//	printf("size_a = %u\n", data->size_a);
//	printf("size_b = %u\n", data->size_b);
    if (count < data->size_a - count)
        return (count);
    return (count - data->size_a);
}

void	find_b_score(t_data *data, t_dlist *curr, int64_t count)
{
    int64_t rotate_a;
    int64_t rotate_b;

	count = 0;
    rotate_a = a_rotations(data, curr->value);
//	printf("rotate_a in find_b_score = %lld\n", rotate_a);
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
}

void	push_to_a(t_data *data)
{
	int64_t	count;
    int64_t position;
	t_dlist	*curr_elem;
	t_dlist *bmin;

	count = 0;
	curr_elem = data->stack_b;
//	//Delete
//	printf("stack_a -> ");
//	print(data->stack_a);
//	printf("\n");
//	printf("stack_b -> ");
//	print(data->stack_b);
//	printf("\n");
//	// =======================
	while (count < data->size_b)
	{
		find_b_score(data, curr_elem, count);
		count++;
		curr_elem = curr_elem->next;
//		printf("%lld\n", count);
	}
//	printf("before bmin\n");
	bmin = find_bmin_score(data, &position);
//	printf("after bmin\n");
	rotate_stacks(data, bmin, position);
    pa(data, &data->stack_b, &data->stack_a);
}
