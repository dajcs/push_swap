/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_stack_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 09:54:58 by anemet            #+#    #+#             */
/*   Updated: 2025/07/10 11:26:18 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// iterates through the stack and updates the `pos` members of each node
// the top node has pos = 0, the next pos = 1, .... up to N-1
void	update_positions(t_stack *a, t_stack *b)
{
	int	i;

	i = 0;
	while (a)
	{
		a->pos = i;
		a = a->next;
		i++;
	}
	i = 0;
	while (b)
	{
		b->pos = i;
		b = b->next;
		i++;
	}
}

// assigns a simplified sorted index to each node in the stack
// this transforms the raw values like [-10, 50, 2] into [1, 2, 0]
// this will simplify all subsequent sorting logic
void	assign_index(t_stack *stack_a, int stack_size)
{
	t_stack	*current;
	t_stack	*highest_node;
	int		highest_value;
	int		i;

	i = stack_size - 1;
	while (i >= 0)
	{
		current = stack_a;
		highest_value = INT_MIN;
		highest_node = NULL;
		while (current)
		{
			if (current->value > highest_value && current->index == -1)
			{
				highest_value = current->value;
				highest_node = current;
			}
			current = current->next;
			if (highest_node != NULL)
				highest_node->index = i;
		}
	}
}

// creates a new node and adds it to the back of the stack
// index initialized to -1, will be set by `assign_index()`
// pos initialized to -1, will be updated regularly by `update_positions()`
void	add_node(t_stack **stack, int n)
{
	t_stack	*new_node;
	t_stack	*last_node;

	if (!stack)
		return ;
	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		error_exit(stack, NULL);
	new_node->value = n;
	new_node->index = -1;
	new_node->pos = -1;
	new_node->target_pos = -1;
	new_node->cost_a = -1;
	new_node->cost_b = -1;
	new_node->next = NULL;
	if (!*stack)
		*stack = new_node;
	else
	{
		last_node = get_stack_bottom(*stack);
		last_node->next = new_node;
	}
}
