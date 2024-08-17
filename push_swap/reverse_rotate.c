/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaleeva <agaleeva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 19:09:11 by agaleeva          #+#    #+#             */
/*   Updated: 2024/08/17 19:09:47 by agaleeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrb(t_stack_node **b, bool print)
{
	rotate_reverse(b);
	if (!print)
		ft_printf("rrb\n");
}

void	rra(t_stack_node **a, bool print)
{
	rotate_reverse(a);
	if (!print)
		ft_printf("rra\n");
}

void    rrr(t_stack_node **a, t_stack_node **b, bool print)
{
    rotate_reverse(a);
    rotate_reverse(b);
    if (!print)
        ft_printf("rrr\n");
}
