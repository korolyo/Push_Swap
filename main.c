/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 20:38:28 by acollin           #+#    #+#             */
/*   Updated: 2021/10/09 12:01:13 by acollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	dlstadd_back(t_dlist **stack, t_dlist *newnode)
{
	t_dlist	*final;

	if (!stack && !newnode)
		return (0);
	if (!(*stack))
	{
		*stack = newnode;
		return (0);
	}
	final = *stack;
	while (final->next != NULL)
		final = final->next;
	final->next = newnode;
	newnode->prev = final;
	return (0);
}

t_dlist	*ft_dlistnew(int data)
{
	t_dlist	*tmp;

	tmp = (t_dlist *) ft_calloc(sizeof (t_dlist), 1);
	if (NULL == tmp)
		return (NULL);
	tmp->data = data;
	tmp->score = 0;
	tmp->next = NULL;
	tmp->prev = NULL;
	return ((t_dlist *)tmp);
}

int main(int argc, char **argv)
{
	t_dlist	*stack_a;
	t_dlist	*stack_b;
	t_data	data;
	int 	i;

	i = 0;
	if (!(checkArgv(argv, argc, &stack_a)))
		exit (0);
	stack_b = NULL;
	if (data.args <= 6)
		sorting_small(&stack_a, &stack_b);
	else
		sorting(&stack_a, &stack_b);
	print_operations();
	return (0);
}
