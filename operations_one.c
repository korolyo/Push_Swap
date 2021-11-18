/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_one.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 12:00:30 by acollin           #+#    #+#             */
/*   Updated: 2021/10/09 12:00:40 by acollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sa(t_dlist **stack)
{
	t_dlist	*first_node;
	t_dlist	*second_node;

	first_node = *stack;
	if (!(first_node && first_node->next))
		return (0);
	second_node = first_node->next;
	first_node->next = second_node->next;
	second_node->next = first_node;
	*stack = second_node;
	ft_putstr_fd("sa\n", 1);
	return (0);
}

int	sb(t_dlist **stack)
{
	t_dlist	*first_node;
	t_dlist	*second_node;

	first_node = *stack;
	if (!(first_node && first_node->next))
		return (0);
	second_node = first_node->next;
	first_node->next = second_node->next;
	second_node->next = first_node;
	*stack = second_node;
	ft_putstr_fd("sb\n", 1);
	return (0);
}

int	pa(t_data *data, t_dlist **stack_from, t_dlist **stack_to)
{
	t_dlist	*tmp;

	tmp = NULL;
	if (*stack_from == NULL || stack_from == NULL)
		return (0);
	if ((*stack_from)->next != NULL)
	{
		tmp = (*stack_from)->next;
		tmp->prev = NULL;
	}
	if (*stack_to == NULL)
	{
		(*stack_from)->next = NULL;
		(*stack_from)->prev = NULL;
	}
	else
		(*stack_from)->next = *stack_to;
	*stack_to = *stack_from;
	*stack_from = tmp;
	(data->size_b)--;
	(data->size_a)++;
	ft_putstr_fd("pa\n", 1);
	return (0);
}

int	pb(t_data *data, t_dlist **stack_from, t_dlist **stack_to)
{
	t_dlist	*tmp;

	tmp = NULL;
	if (*stack_from == NULL || stack_from == NULL)
		return (0);
	if ((*stack_from)->next != NULL)
	{
		tmp = (*stack_from)->next;
		tmp->prev = NULL;
	}
	if (*stack_to == NULL)
	{
		(*stack_from)->next = NULL;
		(*stack_from)->prev = NULL;
	}
	else
		(*stack_from)->next = *stack_to;
	*stack_to = *stack_from;
	*stack_from = tmp;
	(data->size_a)--;
	(data->size_b)++;
	ft_putstr_fd("pb\n", 1);
	return (0);
}
