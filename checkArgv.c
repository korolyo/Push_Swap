/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkArgv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 20:38:28 by acollin           #+#    #+#             */
/*   Updated: 2021/10/09 12:01:13 by acollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//void    single_arg(int argc, char **argv)
//{
//    int64_t count;
//    int64_t strlen;
//    char    **args;
//
//    args = ft_split(argv[count], ' ');
//    while ()
//
//    strlen = (int64_t)ft_strlen(argv[count]);
//    count = 0;
//
//
//}

void	multi_arg(int argc, char **argv, t_dlist **stack_a)
{
	int		i;
    int     count;
    int     num;
	int64_t	val;
    char    **args;
	t_dlist	*newnode;


	i = 1;
    while (i < argc)
    {
        count = 1;
        num = 0;
        args = ft_split(argv[i], ' ');
        while (args[num] != NULL)
            ++num;
        while (count < num)
        {
            val = ft_atol(args[count]);
            newnode = dlistnew(val);
            dlstadd_back(stack_a, newnode);
            count++;
        }
        free(args);
        i++;
    }
}

int	dupl_check(int argc, char **argv)
{
	int	i;
	int	j;
	int	count;

	i = 1;
	j = 0;
	count = 0;
	while (i < argc - 1)
	{
		j = i + 1;
		if (ft_atol(argv[i]) < ft_atol(argv[j]))
			count++;
		while (j < argc)
		{
			if (ft_atol(argv[i]) == ft_atol(argv[j])
				|| (ft_atol(argv[i]) < INT_MIN || ft_atol(argv[i]) > INT_MAX))
				error("Error");
			if (count == argc - 2)
				exit(EXIT_SUCCESS);
			j++;
		}
		i++;
	}
	return (0);
}

void	valid_check(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	if (argc < 2)
		exit(EXIT_SUCCESS);
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
		i++;
	}
}

void	check_argv(int argc, char **argv, t_data *data)
{
	valid_check(argc, argv);
	dupl_check(argc, argv);
	data->size_a = (uint64_t)argc - 1;
	if (argc > 2)
		multi_arg(argc, argv, &data->stack_a);
	else
		error("Error");
}
