/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 11:44:45 by anemet            #+#    #+#             */
/*   Updated: 2025/07/10 14:25:59 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <limits.h>
# include <stdbool.h>

/*
@ struct s_stack -> t_stack --> a node in the stack
  - value     : the value of the node
  - index     : the final sorted index of the node (0 for smallest, ....N-1)
  - pos       : the current position of the node in the current stack
  - target_pos: the position of the node it should be pushed in the other stack
  - cost_a    : the cost to move this node to the top of stack A
  - cost_b    : the cost to move its target to the top of stack B
  - *next     : Pointer to the next node in the stack
*/
typedef struct s_stack
{
	int				value;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}					t_stack;

/* 00_parsing.c */
void				validate_and_parse_args(int argc, char **argv, t_stack **a);

/* 01_stack_init.c */
void				update_positions(t_stack *a, t_stack *b);
void				add_node(t_stack **stack, int n);
void				assign_index(t_stack *stack_a, int stack_size);

/* 02_operations_push.c */
void				pa(t_stack **a, t_stack **b);
void				pb(t_stack **a, t_stack **b);

/* 03_operations_swap.c */
void				sa(t_stack **a);
void				sb(t_stack **b);
void				ss(t_stack **a, t_stack **b);

/* 04_operations_rotate.c */
void				ra(t_stack **a);
void				rb(t_stack **b);
void				rr(t_stack **a, t_stack **b);

/* 05_operations_rev_rotate.c */
void				rra(t_stack **a);
void				rrb(t_stack **b);
void				rrr(t_stack **a, t_stack **b);

/* 06_sort_small.c */
bool				is_sorted(t_stack *stack);
void				sort_three(t_stack **a);
void				sort(t_stack **a, t_stack **b);

/* 07_sort_large.c (Turk Alrgorithm)*/
void				push_swap_turk(t_stack **a, t_stack **b);

/* 08_cost.c */
void				get_cost(t_stack **a, t_stack **b);
void				do_cheapest_move(t_stack **a, t_stack **b);

/* 09_utils_positions.c */
int					get_lowest_index_pos(t_stack **stack);
void				get_target_pos(t_stack **a, t_stack **b);
int					get_stack_size(t_stack *stack);
t_stack				*get_stack_bottom(t_stack *stack);
// t_stack				*get_stack_before_bottom(t_stack *stack);

/* 10_utils_free.c */
void				free_stack(t_stack **stack);
void				free_split(char **split_args);
void				error_exit(t_stack **a, t_stack **b);

#endif
