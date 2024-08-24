/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaleeva <agaleeva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 17:39:48 by agaleeva          #+#    #+#             */
/*   Updated: 2024/07/26 17:39:48 by agaleeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(const char *str, bool *overflow)
{
	long	sign;
	long	result;

	*overflow = false;
	sign = 1;
	result = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		if (result > (LONG_MAX - (*str - '0')) / 10)
		{
			*overflow = true;
			return (0);
		}
		result = result * 10 + *str - '0';
		str++;
	}
	return (sign * result);
}

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

void	init_stack_a(t_stack_node **a, char **argv)
{
	long	n;
	int		i;
	bool	overflow;

	i = 0;
	while (argv[i])
	{
		if (error_syntax(argv[i]))
			free_stack_print_errors(a);
		n = ft_atol(argv[i], &overflow);
		if (n < INT_MIN || n > INT_MAX || n < LLONG_MIN
			|| n > LLONG_MAX || overflow)
			free_stack_print_errors(a);
		if (error_duplicate(*a, (int)n))
			free_stack_print_errors(a);
		append_node(a, (int)n);
		i++;
	}
}

/* This function does ra, rb, rra, rrb opetations
until the 'node' is on top */
void	prep_for_push(t_stack_node **stack,
						t_stack_node *top_node, char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_median)
				ra(stack, false);
			else
				rra(stack, false);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_median)
				rb(stack, false);
			else
				rrb(stack, false);
		}
	}
}

t_stack_node	*get_cheapest(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}
