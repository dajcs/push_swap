/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 13:48:22 by anemet            #+#    #+#             */
/*   Updated: 2025/07/09 14:30:25 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// helper to check for non-numeric characters and duplicates
void	check_duplicates(t_stack *a)
{
	t_stack	*current;
	t_stack	*runner;

	current = a;
	while (current)
	{
		runner = current->next;
		while (runner)
		{
			if (current->value == runner->value)
				error_exit(&a, NULL);
			runner = runner->next;
		}
	}
}

// long int version of ft_atoi, helps to check for INT overflow
static long	ft_atol(const char *str)
{
	long	res;
	int		sign;
	int		i;

	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * sign);
}

// helper to add a new node to the back of the stack
void	add_node_back(t_stack **stack, int n)
{
	t_stack	*node;
	t_stack	*last;

	node = malloc(sizeof(t_stack));
	if (!node)
		error_exit(stack, NULL);
	node->value = n;
	node->next = NULL;
	if (!*stack)
	{
		*stack = node;
		return ;
	}
	last = get_stack_bottom(*stack);
	last->next = node;
}

// fills stack `a` from command line arguments
void	fill_stack_from_args(int argc, char **argv, t_stack **a)
{
	int		i;
	long	num;

	i = 1;
	while (i < argc)
	{
		if (!ft_strchr("-+0123456789 \t", argv[i][0]))
			error_exit(a, NULL);
		num = ft_atol(argv[i]);
		if (num > INT_MAX || num < INT_MIN)
			error_exit(a, NULL);
		i++;
	}
}

// top-level function to validate all inputs and initialize stack `a`
// handles both "1 2 3" and 1 2 3 argument styles
void	validate_and_parse_args(int argc, char **argv, t_stack **a)
{
	char	**split_args;
	int		i;

	if (argc == 2)
	{
		i = 0;
		split_args = ft_split(argv[1], ' ');
		while (split_args[i])
			i++;
		fill_stack_from_args(i + 1, split_args - 1, a);
		free_split(split_args);
	}
	else
	{
		fill_stack_from_args(argc, argv, a);
	}
	check_duplicates(*a);
}
