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

int	ft_sab(t_dlist **stack)
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
	return (0);
}

int	ft_pab(t_dlist **stack_a, t_dlist **stack_b)
{
	t_dlist	*first;
	t_dlist	*second;

	if (!(*stack_b->next))
		return (0);
	first = dlistnew(*stack_b->data);
	second = *stack_b;
	first->next = *stack_a;
	*stack_a = first;
	*stack_b = second->next;
	free(second);
	return (0);
}

int	ft_rab(t_dlist **stack)
{
	t_dlist	*temp;
	t_dlist *temp_last;
	t_dlist *st;

	st = *stack;
	if (!(st && st->next))
		return (0);
	temp = *stack;
	st = st->next;
	temp_last = st;
	while (temp_last->next != NULL)
		temp_last = temp_last->next;
	temp_last->next = temp;
	temp->next = NULL;
	*stack = st;
	return (0);
}

int	ft_rrab(t_dlist **stack)
{
	t_dlist *temp;
	t_dlist *temp_last;
	t_dlist *st;

	st = *stack;
	if (!(st && st->next))
		return (0);
	temp_last = st;
	while (temp_last->next)
	{
		temp = temp_last;
		temp_last = temp_last->next;
	}
	temp_last->next = st;
	temp->next = NULL;
	*stack = temp_last;
	return (0);
}
