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

int64_t	single_arg(const char *str, t_dlist **stack_a)
{
    size_t	str_pos;
    size_t	str_len;
    int64_t final;
    int64_t	count;
    t_dlist	*newnode;

    str_pos = 0;
    count = 0;
    str_len = ft_strlen(str);
    while (str_pos < str_len)
    {
        final = ft_atol(str + str_pos);
        newnode = dlistnew(final);
        dlstadd_back(stack_a, newnode);
        while ((str[str_pos] == '-' || ft_isdigit(str[str_pos]))
               && str_pos < str_len)
            ++str_pos;
        while (str[str_pos] == ' ' && str_pos < str_len)
            ++str_pos;
        ++count;
    }
    return (count);
}

int64_t	multi_arg(int argc, const char **argv, t_dlist **stack_a)
{
	int		i;
	int64_t	final;
    t_dlist	*newnode;

	i = 1;
	final = 0;
	while (i < argc)
	{
        final = ft_atol(argv[i]);
        newnode = dlistnew(final);
        dlstadd_back(stack_a, newnode);
		i++;
	}
	return (i - 1);
}

//void	args_trans(t_dlist **stack_a, char **args, int64_t	num)
//{
//	t_dlist	*newnode;
//	int64_t	count;
//	int64_t	val;
//
//	count = 0;
//	val = 0;
//	while (count < num)
//	{
//		val = ft_atol(args[count]);
//		newnode = dlistnew(val);
//		dlstadd_back(stack_a, newnode);
//		count++;
//	}

void	valid_check(int argc, const char **argv)
{
    int	arg;
    size_t	count;
    size_t	str_len;

    arg = 1;
    while (arg < argc)
    {
        count = 0;
        str_len = ft_strlen(argv[arg]);
        if (str_len == 0)
            error("Error");
        while (count < str_len)
        {
            if ((!(ft_isdigit(argv[arg][count])) && argv[arg][count] != '-'
                 && !((argv[arg][count] == ' ') && (argc == 2)))
                || ((argv[arg][count + 1] == '\0'
                     || argv[arg][count + 1] == ' ') && argv[arg][count] == '-')
                || (count > 0 && (argv[arg][count] == '-'
                                  && argv[arg][count - 1] != ' ')))
                error("Error");
            ++count;
        }
        ++arg;
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

void	check_argv(int argc, const char **argv, t_data *data)
{
    valid_check(argc, argv);
	if (argc < 2)
		exit(EXIT_SUCCESS);
    else if (argc == 2)
        data->size_a = single_arg(argv[1], &data->stack_a);
    else if (argc > 2)
	    data->size_a = multi_arg(argc, argv, &data->stack_a);
	dupl_check(data);
}
