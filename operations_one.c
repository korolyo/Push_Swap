
#include "push_swap.h"

void *ft_sab(t_dlist **stack)
{
	t_dlist temp;

	*stack_a->next->value = temp.value;
	*stack_a->next->value = *stack_a->value;
	*stack_a->value = temp.value;
}

void *ft_pab(t_dlist **stack_a, t_dlist **stack_b)
{
	t_dlist	*first;
	t_dlist	*second;

	if (stack_b->next == NULL)
		return ;
	first = dlistnew(*stack_b->data);
	second = *stack_b;
	first->next = *stack_a;
	*stack_a = first;
	*stack_b = second->next;
	free(second);
}

void *ft_rab(t_dlist **stack)
{
	t_dlist	*temp;

	temp = *stack;
}

void *ft_rrab(t_dlist **stack)
{
	;
}
