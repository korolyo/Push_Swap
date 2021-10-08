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
	uint64_t	value;
	uint64_t	score;
	t_dlist		*next;
	t_dlist		*prev;
};

t_dlist	*dlistnew(int value);
void	dlstadd_back(t_dlist **stack, t_dlist *newnode);
void	*ft_sab(t_dlist **stack);
void	*ft_pab(t_dlist **stack_a, t_dlist **stack_b);
void	*ft_rab(t_dlist **stack);
void	*ft_rrab(t_dlist **stack);
void	*ft_ss(t_dlist **stack_a, t_dlist **stack_b);
void	*ft_rr(t_dlist **stack_a, t_dlist **stack_b);
void	*ft_rrr(t_dlist **stack_a, t_dlist **stack_b);

#endif
