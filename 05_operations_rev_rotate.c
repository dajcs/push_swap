/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_operations_rev_rotate.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 15:40:53 by anemet            #+#    #+#             */
/*   Updated: 2025/07/10 16:06:57 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

// returns the node just before the bottom of the stack
t_stack *get_stack_before_bottom(t_stack *stack)
{
	if (!stack || !stack->next)
		return (NULL);
	while (stack->next->next)
		stack = stack->next;
	return stack;
}

// rotates reverse the stack -- Shift down all elements, old last -> new first
// does nothing if the stack has 0 or 1 elements
// get current last_node and before_last_node
// set before_last_node->next = NULL (new last node)
// last_node->next = *stack // old last_node now points to old first node
// *stack = last_node // update head of stack to point to old last (new first)
void	rev_rotate(t_stack **stack)
{
	t_stack	*last_node;
	t_stack *before_last_node;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	last_node = get_stack_bottom(*stack);
	before_last_node = get_stack_before_bottom(*stack);
	before_last_node->next = NULL;
	last_node->next = *stack;
	*stack = last_node;
}

// rra - reverse rotate a: the old last element in `a` will become the first
// writes "rra\n" on STDOUT
void	rra(t_stack **a)
{
	rev_rotate(a);
	ft_putendl_fd("rra", 1);
}

// rrb - reverse rotate b: the old last element in `b` will become the first
// writes "rrb\n" on STDOUT
void	rrb(t_stack **b)
{
	rev_rotate(b);
	ft_putendl_fd("rrb", 1);
}

// rrr - reverse rotate a and b: do `rra` and `rrb` at the same time
// writes "rrr\n" on STDOUT
void	rrr(t_stack **a, t_stack **b)
{
	rev_rotate(a);
	rev_rotate(b);
	ft_putendl_fd("rrr", 1);
}
