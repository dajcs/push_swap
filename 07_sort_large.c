/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   07_sort_large.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 15:57:49 by anemet            #+#    #+#             */
/*   Updated: 2025/07/10 13:28:20 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// rotate A untile the target position is at the top
// used before pushing an element from B back to A
// if target is in the first half, rotate up (ra)
// otherwise rotate down (rra)
void	rotate_a_to_target(t_stack **a, int target_pos)
{
	int	size_a;

	size_a = get_stack_size(*a);
	if (target_pos == 0)
		return ;
	if (target_pos <= size_a / 2)
	{
		while (target_pos > 0)
		{
			ra(a);
			target_pos--;
		}
	}
	else
	{
		while (target_pos < size_a)
		{
			rra(a);
			target_pos++;
		}
	}
}

// calculates the target position in stack A for the top element of B
// we use the inverse of the logic used for A->B
// get the smallest index in A that is still larger than B's top node index
// Edge case: if b_index is larger than everything in A, target is the smallest
/* example:
								<   ----------------- 21
			6 ------
								<   --------- 9
			10 ----------
			17 -----------------
					A                B
*/

int	find_target_in_a(t_stack *a, int b_index)
{
	t_stack	*current_a;
	int		target_index;
	int		target_pos;

	current_a = a;
	target_index = INT_MAX;
	target_pos = -1;
	while (current_a)
	{
		if (current_a->index > b_index && current_a->index < target_index)
		{
			target_index = current_a->index;
			target_pos = current_a->pos;
		}
		current_a = current_a->next;
	}
	if (target_index == INT_MAX)
		return (get_lowest_index_pos(&a));
	return (target_pos);
}

// after the main sort rotates A until the smallest element is at top
void	final_rotation(t_stack **a)
{
	int	lowest_pos;
	int	stack_size;

	stack_size = get_stack_size(*a);
	lowest_pos = get_lowest_index_pos(a);
	if (lowest_pos > stack_size / 2)
	{
		while (lowest_pos < stack_size)
		{
			rra(a);
			lowest_pos++;
		}
	}
	else
	{
		while (lowest_pos > 0)
		{
			ra(a);
			lowest_pos--;
		}
	}
}

// the main sorting algorith for stacks larger than 3
void	push_swap_turk(t_stack **a, t_stack **b)
{
	int	stack_a_size;
	int	target_pos;

	stack_a_size - get_stack_size(*a);
	if (stack_a_size-- > 3 && !is_sorted(*a))
		pb(a, b);
	if (stack_a_size-- > 3 && !is_sorted(*a))
		pb(a, b);
	while (stack_a_size-- > 3 && !is_sorted(*a))
	{
		update_positions(*a, *b);
		get_target_pos(a, b);
		get_cost(a, b);
		do_cheapest_move(a, b);
	}
	sort_three(a);
	while (*b)
	{
		update_positions(*a, *b);
		target_pos = find_target_in_a(*a, (*b)->index);
		rotate_a_to_target(a, target_pos);
		pa(a, b);
	}
	update_positions(*a, *b);
	final_rotation(a);
}
