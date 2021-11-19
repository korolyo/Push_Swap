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

int isMax(t_dlist *stack_a, int64_t max)
{
    t_dlist *tmp;

    if (stack_a->value > max)
        return (0);
    tmp = stack_a->next;
    while (tmp != NULL)
    {
        if (tmp->value > max)
            return (0);
        tmp = tmp->next;
    }
    return (1);
}

void	sort_six(t_data *data, int64_t  min)
{
	while (data->size_b != 0)
	{
		if (data->stack_a->value > data->stack_b->value)
			pa(data, &data->stack_b, &data->stack_a);
		else if ((isMax(data->stack_a, data->stack_b->value)) == 1
            && data->stack_a->value == min)
			pa(data, &data->stack_b, &data->stack_a);
        ra(&data->stack_a);
	}
	while (!(is_sorted(data->stack_a)))
	{
		ra(&data->stack_a);
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

void	sort_three_a(t_dlist **stack)
{
	t_dlist	*tmp;

	get_score(stack);
	tmp = *stack;
	if (tmp->score == 1)
	{
		rra(stack);
		sa(stack);
	}
	else if (tmp->next->score == 2)
	{
		ra(stack);
		sa(stack);
	}
	else if (tmp->next->next->score == 3)
		sa(stack);
	else if (tmp->score == 2)
		rra(stack);
	else
		ra(stack);
}

void	sort_three_b(t_dlist **stack)
{
	t_dlist	*tmp;

	get_score(stack);
	tmp = *stack;
	if (tmp->score == 1)
	{
		rrb(stack);
		sb(stack);
	}
	else if (tmp->next->score == 2)
	{
		rb(stack);
		sb(stack);
	}
	else if (tmp->next->next->score == 3)
		sb(stack);
	else if (tmp->score == 2)
		rrb(stack);
	else
		rb(stack);
}

void	small_sort(t_data *data)
{
    t_dlist *tmp;
    int64_t min;

    tmp = data->stack_a;
    min = data->stack_a->value;
    while (tmp != NULL)
    {
        if (min > tmp->value)
            min = tmp->value;
        tmp = tmp->next;
    }
	while (data->size_a > 3)
		pb(data, &data->stack_a, &data->stack_b);
	if (data->size_a == 3 && is_sorted(data->stack_a) == 0)
		sort_three_a(&data->stack_a);
	if (data->size_a == 2)
		ra(&data->stack_a);
	if (data->size_b == 3)
	{
		if (is_sorted(data->stack_b) == 0)
			sort_three_b(&data->stack_b);
	}
	else if (data->size_b == 2 && is_sorted(data->stack_b) == 0)
		rb(&data->stack_b);
	if (data->size_b > 0)
		sort_six(data, min);
}
