/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaleeva <agaleeva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 17:39:28 by agaleeva          #+#    #+#             */
/*   Updated: 2024/07/26 17:39:28 by agaleeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*If 'bool' value is "false", the function prints the name of operation
to the output.*/
void	rr(t_stack_node **a, t_stack_node **b, bool print)
{
	rotate(a);
	rotate(b);
	if (!print)
		ft_printf("rr\n");
}

/*If either cheapest_node and target_node on the top of the stack,
we dont want to rotate them.
The function checks if current 'top' node is not the 'cheapest_node'
and not the 'target_node'. Then it refreshes current positions of all
the nodes after the rr() operation.*/
void	rotate_both(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest_node)
{
	while (*b != cheapest_node->target_node && *a != cheapest_node)
		rr(a, b, false);
	current_index(*a);
	current_index(*b);
}
