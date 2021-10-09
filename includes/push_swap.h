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

typedef struct s_dlist t_dlist;

struct	s_dlist
{
	uint64_t	data;
	uint64_t	score;
	t_dlist		*next;
	t_dlist		*prev;
};

t_dlist	*dlistnew(int data);
int		dlstadd_back(t_dlist **stack, t_dlist *newnode);
int		ft_sab(t_dlist **stack);
int		ft_pab(t_dlist **stack_a, t_dlist **stack_b);
int		ft_rab(t_dlist **stack);
int		ft_rrab(t_dlist **stack);
int		ft_ss(t_dlist **stack_a, t_dlist **stack_b);
int		ft_rr(t_dlist **stack_a, t_dlist **stack_b);
int		ft_rrr(t_dlist **stack_a, t_dlist **stack_b);

#endif
