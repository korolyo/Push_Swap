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
//sort six - not working
void	sort_six(t_data *data)
{
//	printf("%lld\n", data->stack_b->score);
	print(data->stack_b);
	printf("\n");
	while (data->size_b != 0)
	{
		if ((data->stack_a->value > data->stack_b->value))
		{
			ft_pab(&data->stack_b, &data->stack_a);
			data->size_b--;
			data->size_a++;
		}
		else
			ft_rab(&data->stack_a);
	}
}

void	get_score(t_dlist **stack)
{
	int64_t	first;
	int64_t	second;
	int64_t	third;

	first = (*stack)->value;
	second = (*stack)->next->value;
	third = (*stack)->next->next->value;
	if (first < second && first < third)
		(*stack)->score = 1;
	if ((first < second && first > third) || \
		(first > second && first < third))
		(*stack)->score = 2;
	if ((second > first && second < third) || \
		(second < first && second > third))
		(*stack)->next->score = 2;
	if (third > first && third > second)
		(*stack)->next->next->score = 3;
}

void	sort_three(t_dlist **stack)
{
	t_dlist	*tmp;

	get_score(stack);
	tmp = *stack;
	if (tmp->score == 1)
	{
		ft_rrab(stack);
		ft_sab(stack);
	}
	else if (tmp->next->score == 2)
	{
		ft_rab(stack);
		ft_sab(stack);
	}
	else if (tmp->next->next->score == 3)
		ft_sab(stack);
	else if (tmp->score == 2)
		ft_rrab(stack);
	else
		ft_rab(stack);
}

void	small_sort(t_data *data)
{
	while (data->size_a > 3)
	{
		ft_pab(&data->stack_a, &data->stack_b);
		data->size_a--;
		data->size_b++;
	}
	if (data->size_a == 3)
		sort_three(&data->stack_a);
	if (data->size_a == 2)
		ft_rab(&data->stack_a);
	if (data->size_b == 3)
	{
		if (is_sorted(data->stack_b) == 0)
			sort_three(&data->stack_b);
	}
	else if (data->size_b == 2 && is_sorted(data->stack_b) == 0)
		ft_rab(&data->stack_b);
	if (data->size_b > 0)
		sort_six(data);
//	printf("ot\n");
}
