#include "push_swap.h"

void	swap(t_list *stack_a)
{
	if (!stack_a)
		return ;
	stack_a->end->next = stack_a->head->next;
	stack_a->end->prev = stack_a->head;
	stack_a->head->prev = stack_a->head->next;
	stack_a->head->next = stack_a->head->next->next;
	stack_a->end->next->next = stack_a->head;
	stack_a->end->next->prev = stack_a->end;
	stack_a->head = stack_a->head->prev;
	write(1, "sa\n", 3);
}

void	push(int stack, t_list *stack_a, t_list *stack_b)
{
	if (stack == 'a')
	{
		ft_lstadd_front(stack_a, stack_b->head->content);
		stack_b->cur = stack_b->head;
		ft_lstdelone(stack_b, NULL);
	}
	if (stack == 'b')
	{
		ft_lstadd_front(stack_b, stack_a->head->content);
		stack_a->cur = stack_a->head;
		ft_lstdelone(stack_a, NULL);
	}
	if (stack == 'a' && stack_a)
		write(1, "pa\n", 3);
	else if (stack == 'b' && stack_b)
		write(1, "pb\n", 3);
}

void	reverse_rotate(int stack, t_list *stack_a, t_list *stack_b)
{
	if (stack == '&' || stack == 'a')
	{
		stack_a->head = stack_a->head->prev;
		stack_a->end = stack_a->end->prev;
	}
	if (stack == '&' || stack == 'b')
	{
		stack_b->head = stack_b->head->prev;
		stack_b->end = stack_b->end->prev;
	}
	if (stack == '&' && stack_a && stack_b)
		write(1, "rrr\n", 4);
	else if (stack == 'a' && stack_a)
		write(1, "rra\n", 4);
	else if (stack == 'b' && stack_b)
		write(1, "rrb\n", 4);
}

void	rotate(int stack, t_list *stack_a, t_list *stack_b)
{
	if ((stack == '&' || stack == 'a') && stack_a)
	{
		stack_a->head = stack_a->head->next;
		stack_a->end = stack_a->end->next;
	}
	if ((stack == '&' || stack == 'b') && stack_b)
	{
		stack_b->head = stack_b->head->next;
		stack_b->end = stack_b->end->next;
	}
	if (stack == '&' && stack_a && stack_b)
		write(1, "rr\n", 3);
	else if (stack == 'a' && stack_a)
		write(1, "ra\n", 3);
	else if (stack == 'b' && stack_b)
		write(1, "rb\n", 3);
}
