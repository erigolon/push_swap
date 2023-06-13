/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigolon <erigolon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 15:03:37 by erigolon          #+#    #+#             */
/*   Updated: 2023/06/13 13:17:46 by erigolon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void	printf_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit (1);
}

int	str_nb_signal(char **str, int i)
{
	int	o;
	int	signal;

	while (str[i])
	{
		o = 1;
		while (str[i][o])
		{
			if (str[i][o] == '+' || str[i][o] == '-')
				if (str[i][o - 1] != ' ')
					return (0);
			o++;
		}
		i++;
	}
	return (1);
}

int	only_space(char **str)
{
	int	o;

	o = 0;
	while (str[1][o])
	{
		if (str[1][o] != ' ')
			return (1);
		o++;
	}
	return (0);
}

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

	if (argv[1][0] == '\0' || !only_space(argv))
		printf_error();
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
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
