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

int	ra(t_dlist **stack_a)
{
	rotate(stack_a);
	ft_putstr_fd("ra\n", 1);
	return (0);
}

int	rb(t_dlist **stack_b)
{
	rotate(stack_b);
	ft_putstr_fd("rb\n", 1);
	return (0);
}

int	rra(t_dlist **stack_a)
{
	reverse_rotate(stack_a);
	ft_putstr_fd("rra\n", 1);
	return (0);
}

int	rrb(t_dlist **stack_b)
{
	reverse_rotate(stack_b);
	ft_putstr_fd("rrb\n", 1);
	return (0);
}
