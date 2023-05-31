/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigolon <erigolon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 15:03:37 by erigolon          #+#    #+#             */
/*   Updated: 2023/05/31 13:02:55 by erigolon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

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
		printf("%sCOSA\n", str[0]);
		printf("%sCOSA\n", str[1]);
		printf("%sCOSA\n", str[2]);
		if (!checkers(str, 0))
			return (free(str), 0);
		stack_a = add_to_list(ft_strlen(*str), str, 0);
		printf("%zuCOSANUMERO\n", ft_strlen(*str));
		free(str);
	}
	else if (argc > 2)
	{
		if (!checkers(argv, 1))
			return (0);
		stack_a = add_to_list(argc, argv, 1);
	}
	check_order(&stack_a, &stack_b);
	while (stack_a->next != NULL)
	{
		printf("%d\n", stack_a->value);
		stack_a = stack_a->next;
	}
	printf("%d\n", stack_a->value);
	return (0);
}
