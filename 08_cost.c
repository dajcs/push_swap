/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   08_cost.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 19:40:20 by anemet            #+#    #+#             */
/*   Updated: 2025/07/09 20:51:08 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_similar_loops_for_b(t_stack **a, t_stack **b, t_stack *cheapest)
{
	while (cheapest->cost_b < 0)
	{
		rra(b);
		cheapest->cost_b++;
	}
	while (cheapest->cost_b > 0)
	{
		ra(a);
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
	do_similar_loops_for_b(a, b, cheapest);
}

// finds the node in A with the lowest move cost and executes the move
void	do_cheapsest_move(t_stack **a, t_stack **b)
{
	t_stack	*current;
	t_stack	*cheapest_node;
	long	cheapest_cost;
	long	cost;

	current = *a;
	cheapest_cost = LONG_MAX;
	while (current)
	{
		cost = abs(current->cost_a) + abs(current->cost_b);
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

// calcualtes the cost to move each element of A to the top
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
