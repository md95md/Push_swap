/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaleeva <agaleeva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 16:25:46 by agaleeva          #+#    #+#             */
/*   Updated: 2024/08/22 18:56:25 by agaleeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
Function that swaps the positions of the top node
and second node of a stack
*/
static void	swap(t_stack_node **head)
{
	if (!*head || !(*head)->next)
		return ;
	*head = (*head)->next;
	(*head)->prev->prev = *head;
	(*head)->prev->next = (*head)->next;
	if ((*head)->next)
		(*head)->next->prev = (*head)->prev;
	(*head)->next = (*head)->prev;
	(*head)->prev = NULL;
}

//Swap the first two nodes of stack `a` and print the instruction
void	sa(t_stack_node	**a, bool print)
{
	swap(a);
	if (!print)
		ft_printf("sa\n");
}

//Swap the first two nodes of stack `b` and print the instruction
void	sb(t_stack_node **b, bool print)
{
	swap(b);
	if (!print)
		ft_printf("sb\n");
}

//Stimutaneously swap the first two nodes of the stack and print the instruction
void	ss(t_stack_node **a, t_stack_node **b, bool print)
{
	swap(a);
	swap(b);
	if (!print)
		ft_printf("ss\n");
}
