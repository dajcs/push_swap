/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   07_sort_large.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 15:57:49 by anemet            #+#    #+#             */
/*   Updated: 2025/07/09 16:12:42 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

	stack_a_size - get_stack_size(*a);
	if (stack_a_size-- > 3 && !is_sorted(*a))
		pb(a, b);
	if (stack_a_size-- > 3 && !is_sorted(*a))
		pb(a, b);
	while (stack_a_size-- > 3 && !is_sorted(*a))
	{
		get_target_pos(a, b);
		get_cost(a, b);
		do_cheapest_move(a, b);
	}
	sort_three(a);
	while (*b)
	{
		get_target_pos(b, a);
		pa(a, b);
	}
	final_rotation(a);
}
