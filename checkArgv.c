/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkArgv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 20:38:28 by acollin           #+#    #+#             */
/*   Updated: 2021/11/18 19:36:41 by acollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	args_trans(t_dlist **stack_a, char **args, int64_t	num)
{
	t_dlist	*newnode;
	int64_t	count;
	int64_t	val;

	count = 0;
	val = 0;
	while (count < num)
	{
		val = ft_atol(args[count]);
		newnode = dlistnew(val);
		dlstadd_back(stack_a, newnode);
		count++;
	}
}

int64_t	multi_arg(int argc, char **argv, t_dlist **stack_a)
{
	int		i;
	int64_t	num;
	int64_t	final;
	char	**args;

	i = 1;
	final = 0;
	while (i < argc)
	{
		num = 0;
		args = ft_split(argv[i], ' ');
		while (args[num] != NULL)
			num++;
		final += num;
		valid_check((int)num, args);
		args_trans(stack_a, args, num);
		free(args);
		i++;
	}
	return (final);
}

void	valid_check(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (i < argc)
	{
		j = 0;
		while (j < (int)ft_strlen(argv[i]))
		{
			if (argv[i][j] == '-')
				j++;
			if (!ft_isdigit(argv[i][j]))
				error("Error");
			j++;
		}
		if (ft_atol(argv[i]) > INT_MAX || ft_atol(argv[i]) < INT_MIN)
			error("Error");
		i++;
	}
}

int	dupl_check(t_data *data)
{
	int		i;
	int		j;
	t_dlist	*tmp_a;
	t_dlist	*tmp_b;

	i = 0;
	tmp_a = data->stack_a;
	while (i < data->size_a - 1)
	{
		tmp_b = tmp_a->next;
		j = i + 1;
		while (j < data->size_a)
		{
			if (tmp_a->value == tmp_b->value)
				error("Error");
			tmp_b = tmp_b->next;
			j++;
		}
		tmp_a = tmp_a->next;
		i++;
	}
	return (0);
}

void	check_argv(int argc, char **argv, t_data *data)
{
	if (argc < 2)
		exit(EXIT_SUCCESS);
	data->size_a = multi_arg(argc, argv, &data->stack_a);
	dupl_check(data);
}
