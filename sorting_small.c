/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_small.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 12:00:30 by acollin           #+#    #+#             */
/*   Updated: 2021/10/09 12:00:40 by acollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_score(t_data *data)
{
	int64_t	first;
	int64_t	second;
	int64_t	third;

	first = data->stack_a->value;
	second = data->stack_a->next->value;
	third = data->stack_a->next->next->value;
	if (first < second && first < third)
		data->stack_a->score = 1;
	if ((first < second && first > third) ||
		(first > second && first < third))
		data->stack_a->score = 2;
	if ((second > first && second < third) ||
		(second < first && second > third))
		data->stack_a->next->score = 2;
	if (third > first && third > second)
		data->stack_a->next->next->score = 3;
}

void	sort_three(t_data *data)
{
    if (data->stack_a->score == 1)
    {
        ft_rrab(&data->stack_a);
        ft_sab(&data->stack_a);
    }
    else if (data->stack_a->next->score == 2)
    {
        ft_rab(&data->stack_a);
        ft_sab(&data->stack_a);
    }
    else if (data->stack_a->next->next->score == 3)
        ft_sab(&data->stack_a);
    else if (data->stack_a->score == 2)
        ft_rrab(&data->stack_a);
    else
        ft_rab(&data->stack_a);
}


void	small_sort(t_data *data)
{
	if (data->args == 2)
        ft_rab(&data->stack_a);
    if (data->args == 3)
	{
		get_score(data);
		sort_three(data);
	}
}