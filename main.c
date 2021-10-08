/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 20:38:28 by acollin           #+#    #+#             */
/*   Updated: 2021/10/06 20:38:37 by acollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	dlstadd_back(t_dlist **stack, t_dlist *newnode)
{
	t_dlist	*final;

	if (!stack && !newnode)
		return ;
	if (!(*stack))
	{
		*stack = newnode;
		return ;
	}
	final = *stack;
	while (final->next != NULL)
		final = final->next;
	final->next = newnode;
	newnode->prev = final;
}

t_dlist	*dlistnew(int value)
{
	t_dlist	*tmp;

	tmp = (t_dlist *) ft_calloc(sizeof (t_dlist), 1);
	if (NULL == tmp)
		return (NULL);
	tmp->value = value;
	tmp->score = 0;
	tmp->next = NULL;
	tmp->prev = NULL;
	return ((t_dlist *)tmp);
}

int main(int argc, char **argv)
{
	t_dlist	*stack_a;
//	t_dlist	*stack_b;
	t_dlist *newnode;
	size_t  i;
	size_t  j;

	i = 0;
	j = 0;
	if (argc == 1)
		return (0);
	while (++i < (size_t)argc)
	{
		while (++j < ft_strlen(argv[i]) || argv[i][j] != ' ')
		{
			if (ft_isdigit(argv[i][j]) != 0)
			{
				ft_putstr_fd("Error\n", 1);
				return (0);
			}
		}
		newnode = dlistnew(ft_atoi(argv[i]));
		dlstadd_back(&stack_a, newnode);
	}
	return (0);
}
