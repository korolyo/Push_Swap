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

int64_t my_abs(int64_t value)
{
    if (value >= 0)
        return (value);
    else
        return ((-1) * value);
}

void	push_to_b(t_data *data, int64_t min, int64_t med, int64_t max)
{
    t_dlist *head;
    int     count;

    count = 0;
    head = data->stack_a;
	while(42)
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

void score_to_elem(t_data *data, t_dlist *elem)
{
    int64_t rotations_a;
    int64_t rotations_b;

    if (elem->val > data->stack_a->val)
    rotations_a = 0;
    rotations_b = 0;
    elem->score = my_abs(rotations_a) + my_abs(rotations_b);
}

void push_to_a(t_data *data)
{
    int64_t count;
    int64_t rotate_a;
    int64_t rotate_b;
    t_dlist *b_elem;

    b_elem = data->stack_b;
    count = 0;
    while (count < data->size_b)
    {
        scores_to_elem(data, b_elem);
        b_elem = b_elem->next;
        count++;
    }
//    stack_rotations(data, rotate_a, rotate_b);
    ft_pab(&data->stack_b, &data->stack_a);
}
//
//void	stack_rotations(t_data *data, int64_t rotate_a,  int64_t rotate_b)
//{
//    paired_rotations(data, rotate_a, rotate_b);
//    lone_rotations(data, rotate_a, rotate_b);
//}

int64_t *bubble_sort(int64_t *arr, int64_t size_a)
{
    int64_t i;
    int64_t j;
    int64_t tmp;

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
	int64_t *arr;
	int64_t len;
    t_dlist  *tmp;

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

void	full_sort(t_data *data)
{
	int64_t	min;
	int64_t	med;
	int64_t	max;
	int64_t	*arr;

	arr = presorted_array(data, &min, &max);
    med = arr[max / 2];
    printf("med - %lli\n", med);
    while (data->stack_a->value != med)
        ft_rab(&data->stack_a);
	push_to_b(data, min, med, max);
    if (data->stack_a->value == max)
        ft_rab(&data->stack_a);
    while (data->stack_b != NULL)
        push_to_a(data);
//	stack_rotations(data);
}
