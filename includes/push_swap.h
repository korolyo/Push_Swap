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

# define SMALL_STACK 6

# include "libft.h"
# include <stdint.h>
# include <stdlib.h>
# include <limits.h>
//DELETE
# include <stdio.h>									//DELETE

typedef struct s_dlist	t_dlist;
typedef struct s_data	t_data;

struct		s_dlist
{
	int64_t	value;
	int64_t	score;
	t_dlist	*next;
	t_dlist	*prev;
};

struct	s_data
{
	t_dlist		*stack_a;
	t_dlist		*stack_b;
	uint32_t	size_a;
	uint32_t	size_b;
};

t_dlist	*dlistnew(int64_t data);
void	dlstadd_back(t_dlist **stack, t_dlist *newnode);
void	check_argv(int argc, char **argv, t_data *data);
int		dupl_check(int argc, char **argv);
void	valid_check(int argc, char **argv);
void	multi_arg(int argc, char **argv, t_dlist **stack_a);
int		ft_sab(t_dlist **stack);
int		ft_pab(t_dlist **stack_from, t_dlist **stack_to);
int		ft_rab(t_dlist **stack);
int		ft_rrab(t_dlist **stack);
int		ft_ss(t_dlist **stack_a, t_dlist **stack_b);
int		ft_rr(t_dlist **stack_a, t_dlist **stack_b);
int		ft_rrr(t_dlist **stack_a, t_dlist **stack_b);
void	sorting(t_data *data);
void	small_sort(t_data *data);
void	get_score(t_dlist **stack);
void	sort_three(t_dlist **stack);
void	sort_six(t_data *data);
void	full_sort(t_data *data);
int64_t *presorted_array(t_data *data, int64_t *min, int64_t *max);
int64_t *bubble_sort(int64_t *arr, int64_t size_a);
void	find_median(int64_t *arr, int64_t *med, int64_t min, int64_t max);
void	push_to_b(t_data *data, int64_t min, int64_t med, int64_t max);
void	give_scores(t_data *data);
void	stack_rotations(t_data *data, int64_t rotate_a,  int64_t rotate_b);
void	init_data(t_data *data);
void	error(char *errMsg);
int		is_sorted(t_dlist *stack);
int64_t my_abs(int64_t value);
//dont forget to delete
void	print(t_dlist *stack);

#endif
