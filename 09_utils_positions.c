/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   09_utils_positions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 23:39:54 by anemet            #+#    #+#             */
/*   Updated: 2025/07/10 14:25:59 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// returns the node at the bottom of the stack
t_stack	*get_stack_bottom(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

// finds the position of the node with the largest index
// used by `get_target_pos` when the target is the largest index in B
int	get_highest_index_pos(t_stack **stack)
{
	t_stack	*tmp;
	int		highest_index;
	int		highest_pos;

	tmp = *stack;
	highest_index = INT_MIN;
	highest_pos = -1;
	while (tmp)
	{
		if (tmp->index > highest_index)
		{
			highest_index = tmp->index;
			highest_pos = tmp->pos;
		}
		tmp = tmp->next;
	}
	return (highest_pos);
}

// returns the number of nodes in the stack
int	get_stack_size(t_stack *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

// finds the position of the node with the smallest index
// used at the final rotation to bring the '0' index to the top
// used by `find_target_in_a` when Edge case: b_index is larger than
// all indexes in a => the target will be the lowest index in A
int	get_lowest_index_pos(t_stack **stack)
{
	t_stack	*tmp;
	int		lowest_index;
	int		lowest_pos;

	tmp = *stack;
	lowest_index = INT_MAX;
	lowest_pos = -1;
	while (tmp)
	{
		if (tmp->index < lowest_index)
		{
			lowest_index = tmp->index;
			lowest_pos = tmp->pos;
		}
		tmp = tmp->next;
	}
	return (lowest_pos);
}

// we want to push elements from A to B so that nodes are in reverse order in B
// target position in B: the node on top of which we're pushing the node from A
// this is the largest element in B that is smaller than the node in A
// if all nodes in B are bigger than node in A, target will be the largest in B
/* example:
               3 ---         >
                                21 ---------------------
               9 ---------   >
                                 8 --------
                                 6 ------
                    A                B
*/
void	get_target_pos(t_stack **a, t_stack **b)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;
	int		best_match_index;

	tmp_a = *a;
	while (tmp_a)
	{
		best_match_index = INT_MIN;
		tmp_b = *b;
		while (tmp_b)
		{
			if (tmp_b->index < tmp_a->index && tmp_b->index > best_match_index)
			{
				best_match_index = tmp_b->index;
				tmp_a->target_pos = tmp_b->pos;
			}
			tmp_b = tmp_b->next;
		}
		if (best_match_index == INT_MIN)
			tmp_a->target_pos = get_highest_index_pos(b);
		tmp_a = tmp_a->next;
	}
}
