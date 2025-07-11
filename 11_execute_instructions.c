/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   11_execute_instructions.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 13:24:05 by anemet            #+#    #+#             */
/*   Updated: 2025/07/11 13:45:23 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// helper to handle push and swap instructions by checker
// returns true if an instruction was matched and executed, false otherwise
bool	execute_push_swap(t_stack **a, t_stack **b, char *line)
{
	if (ft_strncmp(line, "sa\n", 3) == 0)
		swap(a);
	else if (ft_strncmp(line, "sb\n", 3) == 0)
		swap(b);
	else if (ft_strncmp(line, "ss\n", 3) == 0)
	{
		swap(a);
		swap(b);
	}
	else if (ft_strncmp(line, "pa\n", 3) == 0)
		push(b, a);
	else if (ft_strncmp(line, "pb\n", 3) == 0)
		push(a, b);
	else
		return (false);
	return (true);
}

// helper to handle rotation and reverse-rotation instructions by checker
// returns true if an instruction was matched and executed, false otherwise
bool	execute_rotations(t_stack **a, t_stack **b, char *line)
{
	if (ft_strncmp(line, "ra\n", 3) == 0)
		rotate(a);
	else if (ft_strncmp(line, "rb\n", 3) == 0)
		rotate(b);
	else if (ft_strncmp(line, "rr\n", 3) == 0)
	{
		rotate(a);
		rotate(b);
	}
	else if (ft_strncmp(line, "rra\n", 4) == 0)
		rev_rotate(a);
	else if (ft_strncmp(line, "rrb\n", 4) == 0)
		rev_rotate(b);
	else if (ft_strncmp(line, "rrr\n", 4) == 0)
	{
		rev_rotate(a);
		rev_rotate(b);
	}
	else
		return (false);
	return (true);
}

// main operation dispatcher function
// if neither helper function (push_swap/rotation) executes => it is an error
void	execute_instruction(t_stack **a, t_stack **b, char *line)
{
	if (execute_push_swap(a, b, line))
		return ;
	if (execute_rotations(a, b, line))
		return ;
	free(line);
	error_exit(a, b);
}

// reads lines from STDIN and executes them
void	read_and_execute(t_stack **a, t_stack **b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		execute_instruction(a, b, line);
		free(line);
		line = get_next_line(0);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (1);
	validate_and_parse_args(argc, argv, &stack_a);
	read_and_execute(&stack_a, &stack_b);
	if (is_sorted(stack_a) && get_stack_size(stack_b) == 0)
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
