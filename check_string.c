/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigolon <erigolon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 12:35:28 by erigolon          #+#    #+#             */
/*   Updated: 2023/05/16 12:58:25 by erigolon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

int	check_string(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!((str[i] >= 48 && str[i] <= 57) || str[i] == 32))
			return (1);
		i++;
	}
	return (0);
}
