
#include "push_swap.h"

void *ft_sa(t_dlist *stack_a)
{
	t_dlist temp;

	stack_a->next->value = temp.value;
	stack_a->next->value = stack_a->value;
	stack_a->value = temp.value;
}

//void *ft_sb(t_dlist *stack_b)
//{
//	ft_putstr("sb\n");
//}
//
//void *ft_ss(t_dlist *stack_a, t_dlist *stack_b)
//{
//	ft_putstr("ss\n");
//}
//
//void *ft_pa(t_dlist *stack_a)
//{
//	ft_putstr("pa\n");
//}
//
//void *ft_pb(t_dlist *stack_b)
//{
//	ft_putstr("pb\n");
//}
//
//void *ft_ra(t_dlist *stack_a)
//{
//	ft_putstr("ra\n");
//}
//
//void *ft_rb(t_dlist *stack_b)
//{
//	ft_putstr("rb\n");
//}
//
//void *ft_rr(t_dlist *stack_a, t_dlist *stack_b)
//{
//	ft_putstr("rr\n");
//}
//
//void *ft_rra(t_dlist *stack_a)
//{
//	ft_putstr("rra\n");
//}
//
//void *ft_rrb(t_dlist *stack_b)
//{
//	ft_putstr("rrb\n");
//}
//
//void *ft_rrr(t_dlist *stack_a, t_dlist *stack_b)
//{
//
//	ft_putstr("rrr\n");
//}

int main(int argc, char **argv)
{
	t_dlist	*stack_a;
//	t_dlist	*stack_b;
	size_t  i;
	size_t  j;

	i = 0;
	j = 0;
	if (argc == 1)
		return (0);
	while (++i < (size_t)argc)
	{
		while (++j < ft_strlen(argv[i]))
		{
			if (ft_isdigit(argv[i][j]) != 0)
			{
				ft_putstr_fd("Error\n", 1);
				return (0);
			}
		}
		stack_a->value = ft_atoi(argv[i]);
		ft_lstadd_back(stack_a, stack_a);
	}
	return (0);
}
