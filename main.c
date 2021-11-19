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

t_dlist	*dlistnew(int64_t data)
{
	t_dlist	*tmp;

	tmp = (t_dlist *) ft_calloc(sizeof (t_dlist), 1);
	if (NULL == tmp)
		return (NULL);
	tmp->value = data;
	tmp->score = 0;
	tmp->next = NULL;
	tmp->prev = NULL;
	return ((t_dlist *)tmp);
}

void	init_data(t_data *data)
{
	data->stack_a = NULL;
	data->stack_b = NULL;
	data->size_a = 0;
	data->size_b = 0;
}

//DONT FORGET TO DELETE=========================
void	print(t_dlist *stack)
{
	t_dlist	*tmp;

	tmp = stack;
	while (tmp)
	{
		printf("%lli <-> ", tmp->value);
		tmp = tmp->next;
	}
}
//==============================================
int	main(int argc, char **argv)
{
	t_data	data;

	init_data(&data);
	check_argv(argc, argv, &data);
	sorting(&data);
	exit(EXIT_SUCCESS);
}
