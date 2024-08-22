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

static void	rotate(t_stack_node **stack) //Define a function that rotates the stack's top node to the bottom of the stack
{
	t_stack_node	*last_node; //To store a pointer to the last node of a stack

	if (!*stack || !(*stack)->next) //Check if the stack is empty, or if there's one node
		return ;
	last_node = find_last(*stack); 
	last_node->next = *stack; //Assign to the last node, its `next` attribute as the top node, effectively setting the current top node as the last node
	*stack = (*stack)->next; //Assign to the pointer of the top node, the node after it (second from the top)
	(*stack)->prev = NULL; //Complete setting the current top node by detaching it from its previous top node
	last_node->next->prev = last_node; //Reconnect the second node's prev pointer to point to what was previously the last node in the stack
	last_node->next->next = NULL; //Assign to the `next` attribute of the current last node, `NULL` effectively setting it as the current last node, and properly null terminating the stack
}

/*
If 'bool' value is "false", the function prints the name of operation
to the output.
*/
void	rr(t_stack_node **a, t_stack_node **b, bool print)
{
	rotate(a);
	rotate(b);
	if (!print)
		ft_printf("rr\n");
}

// Rotate the top node of stack `b` to the bottom of the stack and print the instruction
void	rb(t_stack_node **b, bool print)
{
	rotate(b);
	if (!print)
		ft_printf("rb\n");
}

// Rotate the top node of stack `a` to the bottom of the stack and print the instruction
void	ra(t_stack_node **a, bool print)
{
	rotate(a);
	if (!print)
		ft_printf("ra\n");
}

