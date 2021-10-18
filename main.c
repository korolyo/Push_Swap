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

//t_dlist	*ft_dlistnew(int data)
//{
//	t_dlist	*tmp;
//
//	tmp = (t_dlist *) ft_calloc(sizeof (t_dlist), 1);
//	if (NULL == tmp)
//		return (NULL);
//	tmp->data = data;
//	tmp->score = 0;
//	tmp->next = NULL;
//	tmp->prev = NULL;
//	return ((t_dlist *)tmp);
//}

void    init_data(t_data *data)
{
    data->stack_a = NULL;
    data->stack_b = NULL;
}

int main(int argc, char **argv)
{
	t_data	data;

    init_data(&data);
    checkArgv(argc, argv, &data);
//    sorting(&data);
//    print_cmd();
//    clear_data(&data);
    exit(EXIT_SUCCESS);
}
