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

uint32_t	multi_arg(int argc, char **argv, t_dlist **stack_a)
{
	int			i;
    int     	count;
    uint32_t	num;
	uint32_t	final;
	int64_t		val;
    char    	**args;
	t_dlist		*newnode;


	i = 1;
	final = 0;
    while (i < argc)
    {
        count = 0;
        num = 0;
        args = ft_split(argv[i], ' ');
        while (args[num] != NULL)
		{
//			printf("arg[%u] = %s\n", num, args[num]);
			num++;
		}
		final += num;
		valid_check((int)num, args);
//		printf("hello\n");
		while (count < (int)num)
        {
//			Delete
//			printf("stack_a -> ");
//			print(*stack_a);
//			printf("\n");
//			 =======================
            val = ft_atol(args[count]);
//			printf("val = %lld\n", val);
//			printf("count = %i\n", count);
            newnode = dlistnew(val);
            dlstadd_back(stack_a, newnode);
            count++;
        }
        free(args);
        i++;
    }
	return (final);
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

	i = 0;

	while (i < argc)
	{
		j = 0;
		while (j < (int)ft_strlen(argv[i]))
		{
//			printf("hello\n");
//			printf("argv[%d][%d] = %c\n", i, j, argv[i][j]);
//			printf("i = %d\n", i);
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
	if (argc < 2)
		exit(EXIT_SUCCESS);
//	dupl_check(argc, argv);
	data->size_a = multi_arg(argc, argv, &data->stack_a);
//	else
//		error("Error");
//	printf("size_a = %u\n", data->size_a);
}
