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

void free_array(char **array)
{
	int i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

// t_stack_node	*init_stack_qts(char *args)
// {
// 	t_stack_node		*head;
// 	int			i;
// 	char		**spl_args;

// 	spl_args = ft_split(args, ' ');
// 	head = NULL;
// 	i = 0;
// 	while (spl_args[i] != NULL)
// 	{
// 		if (i == 0)
// 			head = create_new_node(i, ft_atoi_protected(spl_args[i], &head));
// 		else
// 			append_node(&head, i, ft_atoi_protected(spl_args[i], &head));
// 		i++;
// 	}
// 	free_array(spl_args);
// 	error_duplicate(&head, 0);
// 	update_pos(&head);
// 	return (head);
// }

int	is_space_inside(char *str)
{
	while (*str)
	{
		if (*str == ' ' || *str == '\n' || *str == '\t' || *str == '\v')  
			return (1);
		str++;
	}
	return (0);
}

// The Turk Algorithm
int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	int len = 0;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]
		&& argv[1][0] >= '0' && argv[1][0] <= '9'))
		return(1);
	if (argc == 2)
	{
		if (is_space_inside(argv[1]))
		{
			argv = ft_split(argv[1], ' ');
			if (argv == NULL)
				write(2, "Error memory\n", 14);
			init_stack_a_quotes(&a, argv);
		}
		else
		{
			write(2, "Not valid input\n", 18);
			return (EXIT_SUCCESS);
		}
	}
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
	return (0);
}
	// if (argc == 2)
	// {
	// 	argv = ft_split2(argv[1], ' ');
	// 	if (argv == NULL)
	// 		write(2, "Error memory\n", 14);
	// 	if (is_valid_input(argv[1]) == 0)
	// 	{
	// 		write(2, "Not valid input\n", 17);
	// 		free_args(argv);
	// 		return (1);
	// 	}
	// }