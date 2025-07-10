/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_operations_push.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 14:01:42 by anemet            #+#    #+#             */
/*   Updated: 2025/07/10 14:45:33 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// pushes the top element from one stack to another
// does nothing if the source stack is empty
// node_to_push = ...       // saves a pointer to the top node
// *stack_from = ...        // updates the source stack head
// node_to_push->next = ... // the moved node set to point to the dest top node
// *stack_to = ...          // updates the dest stack's head to the pushed node
void	push(t_stack **stack_from, t_stack **stack_to)
{
	t_stack	*node_to_push;

	if (!*stack_from)
		return ;
	node_to_push = *stack_from;
	*stack_from = (*stack_from)->next;
	node_to_push->next = *stack_to;
	*stack_to = node_to_push;
}

// takes the first element at the tob of b and puts it on top of a
// writes "pa\n" on STDOUT
void	pa(t_stack **a, t_stack **b)
{
	push(b, a);
	ft_putendl_fd("pa", 1);
}

// takes the first element at the tob of `a` and puts it on top of `b`
// writes "pb\n" on STDOUT
void	pb(t_stack **a, t_stack **b)
{
	push(a, b);
	ft_putendl_fd("pb", 1);
}
