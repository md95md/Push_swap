/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 19:54:00 by marvin            #+#    #+#             */
/*   Updated: 2024/07/22 19:54:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>
#include "../libft/libft.h"

typedef struct s_stack_node
{
	int					nbr;
	int					index;
	int 				push_cost;
	bool				above_median;
	bool 				cheapest;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
	struct s_stack_node	*target_node;
}	t_stack_node;

// Handle error


// Stack initiation
bool	stack_sorted(t_stack_node *stack);

// Nodes initation
void	init_nodes_a(t_stack_node *a, t_stack_node *b);

// Stack utils


// Commands
void	rotate_both(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest_node);

// Algorihm
void    sort_three(t_stack_node **a);


void	prep_for_push(t_stack_node **stack, t_stack_node *top_node, char stack_name);

#endif
