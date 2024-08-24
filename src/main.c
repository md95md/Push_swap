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

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

// The Turk Algorithm
int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]
		&& argv[1][0] >= '0' && argv[1][0] <= '9'))
		return (1);
	if (argc == 2)
		argv = ft_split2(argv[1], ' ');
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
	if (argc == 2)
		free_array(argv);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
//int	is_space_inside(char *str)
// {
// 	while (*str)
// 	{
// 		if (*str == ' ' || *str == '\n' || *str == '\t' || *str == '\v')  
// 			return (1);
// 		str++;
// 	}
// 	return (0);
// }