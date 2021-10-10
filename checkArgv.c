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

int	checkDuplicates(int argc, char **argv)
{
	int  i;
	int  j;

	i = 0;
	j = 0;
	while (i < argc -1)
	{
		j = i + 1;
		while (++j < argc - 1)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (0);
		}
		i++;
	}
	return (1);
}

int	checkArgv(char **argv, int argc, t_dlist **stack_a)
{
	int		i;
	int		j;
	char	*args;
	t_dlist	*newnode;

	i = 1;
	j = 0;
	if (argc < 2 || !(checkDuplicates(argc, argv)))
		return (0);
	while (i < argc)
	{
		j = 0;
		while ((j < (int)ft_strlen(argv[i])))
		{
			if (argv[i][j] == ' ')
				;
			else if (ft_isdigit(argv[i][j]) == 0)
			{
				ft_putstr_fd("Error\n", 1);
				return (0);
			}
			args = *ft_split(argv[i], ' ');
			*stack_a = ft_dlistnew(ft_atoi(argv[i]));
			newnode = ft_dlistnew(ft_atoi(argv[i]));
			dlstadd_back(stack_a, newnode);
			j++;
		}
		i++;
	}
	return (1);
}
