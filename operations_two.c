/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_two.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 12:00:49 by acollin           #+#    #+#             */
/*   Updated: 2021/10/09 12:00:53 by acollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ra(t_dlist **stack)
{
	t_dlist	*temp;
	t_dlist	*temp_last;
	t_dlist	*st;

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
	ft_putstr_fd("ra\n", 1);
	return (0);
}

int	rb(t_dlist **stack)
{
	t_dlist	*temp;
	t_dlist	*temp_last;
	t_dlist	*st;

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
	ft_putstr_fd("rb\n", 1);
	return (0);
}

int	rra(t_dlist **stack)
{
	t_dlist	*temp;
	t_dlist	*temp_last;
	t_dlist	*st;

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
	ft_putstr_fd("rra\n", 1);
	return (0);
}

int	rrb(t_dlist **stack)
{
	t_dlist	*temp;
	t_dlist	*temp_last;
	t_dlist	*st;

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
	ft_putstr_fd("rrb\n", 1);
	return (0);
}