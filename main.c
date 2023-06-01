/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigolon <erigolon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 15:03:37 by erigolon          #+#    #+#             */
/*   Updated: 2023/06/01 14:44:20 by erigolon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

int	len_str(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**str;

	if (argc == 1)
		return (0);
	stack_b = NULL;
	if (argc == 2)
	{
		str = ft_split(argv[1], ' ');
		if (!checkers(str, 0))
			return (free(str), 0);
		stack_a = add_to_list(len_str(str), str, 0);
		free(str);
	}
	else if (argc > 2)
	{
		if (!checkers(argv, 1))
			return (0);
		stack_a = add_to_list(argc, argv, 1);
	}
	check_order(&stack_a, &stack_b);
	return (0);
}
