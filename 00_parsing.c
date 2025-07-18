/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 13:48:22 by anemet            #+#    #+#             */
/*   Updated: 2025/07/14 12:04:00 by anemet           ###   ########.fr       */
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
		current = current->next;
	}
}

// long int version of ft_atoi, helps to check for INT overflow
static long	ft_atol(const char *str)
{
	long	res;
	int		sign;
	int		i;

	i = 0;
	res = 0;
	sign = 1;
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

// fills stack `a` from command line arguments
bool	fill_stack_from_args(int argc, char **argv, t_stack **a)
{
	int		i;
	long	num;

	i = 1;
	while (i < argc)
	{
		if (!argv[i][0] || !ft_strchr("-+0123456789 \t", argv[i][0]))
			return (false);
		num = ft_atol(argv[i]);
		if (num > INT_MAX || num < INT_MIN)
			return (false);
		add_node(a, (int)num);
		i++;
	}
	return (true);
}

// top-level function to validate all inputs and initialize stack `a`
// handles both "1 2 3" and 1 2 3 argument styles
void	validate_and_parse_args(int argc, char **argv, t_stack **a)
{
	char	**split_arg1;
	int		i;

	if (argc == 2)
	{
		i = 0;
		split_arg1 = ft_split(argv[1], ' ');
		while (split_arg1[i])
			i++;
		if (fill_stack_from_args(i + 1, split_arg1 - 1, a))
			free_split(split_arg1);
		else
		{
			free_split(split_arg1);
			error_exit(a, NULL);
		}
	}
	else if (!fill_stack_from_args(argc, argv, a))
		error_exit(a, NULL);
	check_duplicates(*a);
}
