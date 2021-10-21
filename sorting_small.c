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

void sort_three(t_data *data)
{
    if (data->stack_a->value == 1)
    {
        ft_rrab(&data->stack_a);
        ft_sab(&data->stack_a);
    }
    else if (data->stack_a->next->value == 2)
    {
        ft_rab(&data->stack_a);
        ft_sab(&data->stack_a);
    }
    else if (data->stack_a->next->next->value == 3)
        ft_sab(&data->stack_a);
    else if (data->stack_a->value == 2)
        ft_rrab(&data->stack_a);
    else
        ft_rab(&data->stack_a);
}

void	small_sort(t_data *data)
{
	if (data->args == 2)
        ft_rab(&data->stack_a);
    if (data->args == 3)
       sort_three(data);
}