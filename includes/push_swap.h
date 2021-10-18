/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 20:41:28 by acollin           #+#    #+#             */
/*   Updated: 2021/10/06 20:42:12 by acollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdint.h>
# include <stdlib.h>
# include <limits.h>

# include <stdio.h>

typedef struct s_dlist t_dlist;
typedef struct s_data t_data;

struct	s_dlist
{
	uint64_t	data;
	uint64_t	score;
	t_dlist		*next;
	t_dlist		*prev;
};

struct	s_data
{
    t_dlist     *stack_a;
    t_dlist     *stack_b;
//	uint64_t	args;
};

t_dlist	*dlistnew(int data);
void	dlstadd_back(t_dlist **stack, t_dlist *newnode);
void	checkArgv(int argc, char **argv, t_data *data);
int		dupl_check(int argc, char **argv);
void	valid_check(int argc, char **argv);
void	multi_arg(int argc, char **argv, t_dlist **stack_a);
int		ft_sab(t_dlist **stack);
int		ft_pab(t_dlist **stack_a, t_dlist **stack_b);
int		ft_rab(t_dlist **stack);
int		ft_rrab(t_dlist **stack);
int		ft_ss(t_dlist **stack_a, t_dlist **stack_b);
int		ft_rr(t_dlist **stack_a, t_dlist **stack_b);
int		ft_rrr(t_dlist **stack_a, t_dlist **stack_b);
void	sorting_small(t_dlist **stack_a, t_dlist **stack_b);
void	sorting(t_dlist **stack_a, t_dlist **stack_b);
void    init_data(t_data *data);
void	error(char *errMsg);

//dont forget to delete
void	print(t_dlist *stack);


#endif
