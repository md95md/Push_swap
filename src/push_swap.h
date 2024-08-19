/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaleeva <agaleeva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 17:38:58 by agaleeva          #+#    #+#             */
/*   Updated: 2024/07/26 17:38:58 by agaleeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>
#include "../libft/libft.h"
#include "../includes/ft_printf.h"

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
int	error_syntax(char *str_n);
int	error_duplicate(t_stack_node *a, int n);
void	free_stack(t_stack_node **stack);
void	free_stack_print_errors(t_stack_node **a);

// Stack initiation
bool			stack_sorted(t_stack_node *stack);
void			init_stack_a(t_stack_node **a, char **argv);
t_stack_node	*get_cheapest(t_stack_node *stack);

// Stack utils
int				stack_len(t_stack_node *stack);
char			**ft_split2(char const *s, char c);
t_stack_node	*find_last(t_stack_node *stack);
t_stack_node	*find_max(t_stack_node *stack);
t_stack_node	*find_min(t_stack_node *stack);

// Rotation
void	rr(t_stack_node **a, t_stack_node **b, bool print);
static void	rev_rotate(t_stack_node **stack);
void	rotate_both(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest_node);
static void	rev_rotate_both(t_stack_node **a,
								t_stack_node **b,
								t_stack_node *cheapest_node);
void	rotate(t_stack_node **stack);
void	rra(t_stack_node **a, bool print);
void	rb(t_stack_node **b, bool print);
void	rrb(t_stack_node **b, bool print);
void	ra(t_stack_node **a, bool print);
void	rrr(t_stack_node **a, t_stack_node **b, bool print);
void	pb(t_stack_node **b, t_stack_node **a, bool print);
void	pa(t_stack_node **a, t_stack_node **b, bool print);

// Nodes initation
void	init_nodes_a(t_stack_node *a, t_stack_node *b);
void	init_nodes_b(t_stack_node *a, t_stack_node *b);
void	current_index(t_stack_node *stack);

// Commands
void		sa(t_stack_node	**a, bool print);
void		sb(t_stack_node **b, bool print);
void		ss(t_stack_node **a, t_stack_node **b, bool print);
static void	swap(t_stack_node **head);

// Algorihm
void    sort_three(t_stack_node **a);
void	sort_stacks(t_stack_node **a, t_stack_node **b);
void	prep_for_push(t_stack_node **stack, t_stack_node *top_node, char stack_name);

#endif
