/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   08_cost.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 19:40:20 by anemet            #+#    #+#             */
/*   Updated: 2025/07/11 20:46:10 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// return the minimum of two integers
int	min(int x, int y)
{
	if (x < y)
		return (x);
	else
		return (y);
}

// the last few lines from the function `do_rotate(a, b, cheapest)`
void	do_similar_loops_for_b(t_stack **b, t_stack *cheapest)
{
	while (cheapest->cost_b < 0)
	{
		rrb(b);
		cheapest->cost_b++;
	}
	while (cheapest->cost_b > 0)
	{
		rb(b);
		cheapest->cost_b--;
	}
}

// Executes the combined cheapest rotational moves
void	do_rotate(t_stack **a, t_stack **b, t_stack *cheapest)
{
	while (cheapest->cost_b < 0 && cheapest->cost_a < 0)
	{
		rrr(a, b);
		cheapest->cost_a++;
		cheapest->cost_b++;
	}
	while (cheapest->cost_b > 0 && cheapest->cost_a > 0)
	{
		rr(a, b);
		cheapest->cost_a--;
		cheapest->cost_b--;
	}
	while (cheapest->cost_a < 0)
	{
		rra(a);
		cheapest->cost_a++;
	}
	while (cheapest->cost_a > 0)
	{
		ra(a);
		cheapest->cost_a--;
	}
	do_similar_loops_for_b(b, cheapest);
}

// finds the node in A with the lowest move cost and executes the move
// if cost_a and cost_b have different signs => cost = |cost_a| + |cost_b|
// else cost = diff + common = |cost_a - cost_b| + min(|cost_a|, |cost_b|)
void	do_cheapest_move(t_stack **a, t_stack **b)
{
	t_stack	*current;
	t_stack	*cheapest_node;
	int		cheapest_cost;
	int		cost;

	current = *a;
	cheapest_cost = INT_MAX;
	while (current)
	{
		if (current->cost_a * current->cost_b <= 0)
			cost = abs(current->cost_a) + abs(current->cost_b);
		else
			cost = abs(current->cost_a - current->cost_b)
				+ min(abs(current->cost_a), abs(current->cost_b));
		if (cost < cheapest_cost)
		{
			cheapest_cost = cost;
			cheapest_node = current;
		}
		current = current->next;
	}
	do_rotate(a, b, cheapest_node);
	pb(a, b);
}

// calculates the cost to move each element of A to the top
//                       ... and its target in B to the top
// Cost in A: positive for ra, negative for rra
// Cost in B: positive for rb, negative for rrb
void	get_cost(t_stack **a, t_stack **b)
{
	t_stack	*current_a;
	t_stack	*current_b;
	int		size_a;
	int		size_b;

	current_a = *a;
	current_b = *b;
	size_a = get_stack_size(current_a);
	size_b = get_stack_size(current_b);
	while (current_a)
	{
		if (current_a->pos <= size_a / 2)
			current_a->cost_a = current_a->pos;
		else
			current_a->cost_a = current_a->pos - size_a;
		if (current_a->target_pos <= size_b / 2)
			current_a->cost_b = current_a->target_pos;
		else
			current_a->cost_b = current_a->target_pos - size_b;
		current_a = current_a->next;
	}
}
