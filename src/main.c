/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaleeva <agaleeva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 17:39:21 by agaleeva          #+#    #+#             */
/*   Updated: 2024/07/26 17:39:21 by agaleeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	append_node(t_stack_node **stack, int n)
{
	t_stack_node	*node;
	t_stack_node	*last_node;

	if (!stack)
		return ;
	node = malloc(sizeof(t_stack_node));
	if (!node)
		return ;
	node->next = NULL;
	node->nbr = n;
	if (!(*stack))
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_last(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

void	cmd_nb_into_stack(t_stack_node **a, char **split_av)
{
	long	n;
	int		i;
	bool	overflow;

	i = -1;
	n = 0;
	overflow = false;
	while (split_av[++i])
	{
		if (error_syntax(split_av[i]))
		{
			printf("syntax_error");
			free_args(split_av);
			free_stack_print_errors(a);
		}
		n = ft_atol(split_av[i], &overflow);
		if (overflow || error_duplicate(*a, (int)n)
			|| n > INT_MAX || n < INT_MIN)
		{
			free_args(split_av);
			free_stack_print_errors(a);
		}
		append_node(a, (int)n);
	}
	free_args(split_av);
}

void	free_args(char **av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		free(av[i]);
		i++;
	}
	free(av);
}

static void	handle_split_av(char *arg, t_stack_node **a)
{
	char	**split_av;
	int		j;

	j = 0;
	split_av = ft_split(arg, ' ');
	if (!split_av)
	{
		free_stack(a);
		write(2, "Error\n", 6);
		exit(1);
	}
	while (split_av[j])
	{
		if (error_syntax(split_av[j]))
		{
			free_args(split_av);
			free_stack(a);
			write(2, "Error\n", 6);
			exit(1);
		}
		j++;
	}
	cmd_nb_into_stack(a, split_av);
}

static bool	parse_arg_done(int ac, char **av, t_stack_node **a)
{
	int		i;

	i = 1;
	while (i < ac)
	{
		handle_split_av(av[i], a);
		i++;
	}
	return (true);
}

// The Turk Algorithm
int	main(int argc, char **argv)
{
	t_stack_node *a;
	t_stack_node *b;

	a = NULL;
	b = NULL;
	if ((argc == 1) || (argc == 2 && !argv[1][0]))
		return (1);
	if (argc == 2)
		argv = ft_split2(argv[1], ' ');
	if (argc == 1 || (argc == 2 && !argv[1][0] && argv[1][0] >= '0' && argv[1][0] <= '9'))
		return (false);
	if (!parse_arg_done(argc, argv, &a))
		return (1);
	init_stack_a(&a, argv + 1);
	if (!stack_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a, false);
		else if (stack_len(a) == 3)
			sort_three(&a);
		else
			sort_stacks(&a, &b);
	}
	free_stack(&a);
	return (0);
}
