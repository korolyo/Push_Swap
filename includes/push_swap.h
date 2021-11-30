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

typedef struct s_dlist	t_dlist;
typedef struct s_data	t_data;

struct		s_dlist
{
	int64_t	value;
	int64_t	score;
	t_dlist	*next;
	t_dlist	*prev;
};

struct		s_data
{
	t_dlist	*stack_a;
	t_dlist	*stack_b;
	int64_t	size_a;
	int64_t	size_b;
};

// PARSE INPUT
t_dlist	*dlistnew(int64_t data);
void	dlstadd_back(t_dlist **stack, t_dlist *newnode);
void	check_argv(int argc, const char **argv, t_data *data);
int		dupl_check(t_data *data);
void	valid_check(int argc, const char **argv);
void	args_trans(t_dlist **stack_a, char **args, int64_t	num);
int64_t	multi_arg(int argc, const char **argv, t_dlist **stack_a);
int64_t	single_arg(const char *str, t_dlist **stack_a);
void	init_data(t_data *data);
void	error(char *errMsg);
int		is_sorted(t_dlist *stack);
int64_t	my_abs(int64_t value);

// MAIN OPERATIONS
int		rotate(t_dlist **stack);
int		reverse_rotate(t_dlist **stack);
int		sa(t_dlist **stack);
int		sb(t_dlist **stack);
int		pa(t_data *data, t_dlist **stack_from, t_dlist **stack_to);
int		pb(t_data *data, t_dlist **stack_from, t_dlist **stack_to);
int		ra(t_dlist **stack_a);
int		rb(t_dlist **stack_b);
int		rra(t_dlist **stack_a);
int		rrb(t_dlist **stack_b);
int		ss(t_dlist **stack_a, t_dlist **stack_b);
int		rr(t_dlist **stack_a, t_dlist **stack_b);
int		rrr(t_dlist **stack_a, t_dlist **stack_b);

// SMALL SORT
void	sorting(t_data *data);
void	small_sort(t_data *data);
void	get_score(t_dlist **stack);
void	sort_three_a(t_dlist **stack);
void	sort_three_b(t_dlist **stack);
void	sort_six(t_data *data, int64_t min);
int		isMax(t_dlist *stack_a, int64_t max);

// FULL SORT
void	full_sort(t_data *data);
int64_t	*presort_ar(t_data *data, int64_t *min, int64_t *max, int64_t *med);
int64_t	mmm_values(t_data *data, int64_t *min, int64_t *max);
int64_t	*bubble_sort(int64_t *arr, int64_t size_a);
void	find_median(int64_t *arr, int64_t *med, int64_t min, int64_t max);
void	push_to_b(t_data *data, int64_t min, int64_t med, int64_t max);
void	push_to_a(t_data *data);
void	find_b_score(t_data *data, t_dlist *curr, int64_t count);
int64_t	a_rotations(t_data *data, int64_t value);
t_dlist	*find_bmin_score(t_data *data, int64_t *position);

// ROTATIONS
void	rotate_stacks(t_data *data, t_dlist *bmin, int64_t position);
void	stack_rotations(t_data *data, int64_t rotate_a, int64_t rotate_b);
void	paired_rotate(t_data *data, int64_t *rotate_a, int64_t *rotate_b);
void	lone_rotations(t_data *data, int64_t *rotate_a, int64_t *rotate_b);
int64_t	find_rotations_to_elem(t_dlist *stack, uint32_t size, int64_t min);
void	final_rotations(t_dlist **stack_a);

#endif
