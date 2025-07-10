/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_operations_swap.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 14:23:30 by anemet            #+#    #+#             */
/*   Updated: 2025/07/10 14:38:06 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// swaps the first two elements of a stack
// does nothing if the stack has 0 or 1 elements
void	swap(t_stack **stack)
{
	t_stack	*first_node;
	t_stack	*second_node;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first_node = *stack;
	second_node = (*stack)->next;
	first_node->next = second_node->next;
	second_node->next = first_node;
	*stack = second_node;
}

// sa - swap a: Swaps the first 2 elements at the top of `a`
// writes "sa\n" on STDOUT
void	sa(t_stack **a)
{
	swap(a);
	ft_putendl_fd("sa", 1);
}

// sb - swap b: Swaps the first 2 elements at the top of `b`
// writes "sa\n" on STDOUT
void	sb(t_stack **b)
{
	swap(b);
	ft_putendl_fd("sb", 1);
}

// ss - swap a & b: do `sa` and `sb` at the same time
// writes "ss\n" on STDOUT
void	ss(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
	ft_putendl_fd("ss", 1);
}
