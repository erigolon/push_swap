/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigolon <erigolon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 15:03:37 by erigolon          #+#    #+#             */
/*   Updated: 2023/05/16 12:59:08 by erigolon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

int	main(int argc, char **argv)
{
	int	*str;

	(void) str;
	if (argc != 2)
		return (ft_printf("Error\nWrong number of arguments\n"), 1);
	if (check_string(argv[1]))
		return (ft_printf("Error\nThe components aren't the correct one"), 1);
	return (0);
}
