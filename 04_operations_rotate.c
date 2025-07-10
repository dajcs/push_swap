/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_operations_rotate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 15:00:11 by anemet            #+#    #+#             */
/*   Updated: 2025/07/10 15:39:16 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

// rotates forward the stack -- Shift up all elements, old first -> new last
// does nothing if the stack has 0 or 1 elements
// first_node = *stack // save the first node
// *stack = (*stack)->next // the new head of stack is the old second node
// last_node = ...         // find current (old) last node
// last_node->next = first_node  // link new last node to old first node
// first_node->next = NULL; to old first is the new last so its next = NULL
void rotate(t_stack **stack)
{
	t_stack *first_node;
	t_stack *last_node;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first_node = *stack;
	*stack = (*stack)->next;
	last_node = get_stack_bottom(*stack);
	last_node->next = first_node;
	first_node->next = NULL;
}


// ra - rotate a: the old last element in `a` will become the first
// writes "ra\n" on STDOUT
void	ra(t_stack **a)
{
	rotate(a);
	ft_putendl_fd("ra", 1);
}

// rb - rotate b: the old last element in `b` will become the first
// writes "rb\n" on STDOUT
void	rb(t_stack **b)
{
	rotate(b);
	ft_putendl_fd("rb", 1);
}

// rr - rotate a and b: do `ra` and `rb` at the same time
// writes "rr\n" on STDOUT
void	rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	ft_putendl_fd("rr", 1);
}
