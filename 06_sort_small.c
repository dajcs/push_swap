/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06_sort_small.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 14:32:41 by anemet            #+#    #+#             */
/*   Updated: 2025/07/09 19:36:10 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// checks if a stack is sorted in ascending order
bool	is_sorted(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (false);
		stack = stack->next;
	}
	return (true);
}

// sorts a stack of three elements using a maximum of 2 operations
//   2 1     3 2 1      3 1        1 3 1          2 1
//   1 2     2 3 2      1 2        3 1 2          3 2
//   3 3     1 1 3      2 3        2 2 3          1 3
//   sa      sa         ra         sa            rra
//             rra                   ra
void	sort_three(t_stack **a)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->value;
	second = (*a)->next->value;
	third = (*a)->next->next->value;
	if (first > second && second < third && first < third)
		sa(a);
	else if (first > second && second > third)
	{
		sa(a);
		rra(a);
	}
	else if (first > second && second < third && first > third)
		ra(a);
	else if (first < second && second > third && first < third)
	{
		sa(a);
		ra(a);
	}
	else if (first < second && second > third && first > third)
		rra(a);
}

// main sorting dispatcher, depending on stack size 2, 3 or more
void	sort(t_stack **a, t_stack **b)
{
	int	size;

	size = get_stack_size(*a);
	if (is_sorted(*a))
		return ;
	if (size == 2)
		sa(a);
	else if (size == 3)
		sort_three(a);
	else
		push_swap_turk(a, b);
}
