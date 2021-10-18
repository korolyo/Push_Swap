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

char	*split_args(char **number, char **argv, int i, int k)
{
	number = *ft_split(argv[i], ' ');
}

int	dupl_check(int argc, char **argv)
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
			if (ft_atol(argv[i]) == ft_atol(argv[j]))
				return (0);
		}
		i++;
	}
	return (1);
}

void valid_check(int argc, char **argv)
{
    int i;
    int j;

    j = 0;
    i = 1;
    if (argc < 2)
        eroor(EXIT_SUCCESS);
    while (i < argc)
    {
        j = 0;
        while (j < ft_strlen(argv[i]))
        {
            if (!ft_isdigit(argv[i][j]) || (argv[i][j] == ' ' && (argv[i][j + 1] == ' ') || )
                error;
        }
    }
}

void	checkArgv(char **argv, int argc, t_data *data)
{
    valid_check(argc, argv);
    dupl_check(argc, argv);
    if (argc == 2)
        single_arg(argc, argv, &data);
    else if (argc > 2)
        multi_arg(argc, argv, &data);
    else
        error;
}
