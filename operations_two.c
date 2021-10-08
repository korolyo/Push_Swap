
#include "push_swap.h"

void *ft_ss(t_dlist **stack_a, t_dlist **stack_b)
{
	ft_sab(*stack_a);
	ft_sab(*stack_b);
}

void *ft_rr(t_dlist **stack_a, t_dlist **stack_b)
{
	ft_rab(*stack_a);
	ft_rab(*stack_b);
}

void *ft_rrr(t_dlist **stack_a, t_dlist **stack_b)
{
	ft_rrab(*stack_a);
	ft_rrab(*stack_b);
}
