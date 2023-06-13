/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigolon <erigolon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 12:35:28 by erigolon          #+#    #+#             */
/*   Updated: 2023/06/13 11:39:00 by erigolon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

int	str_is_number(char **str, int i)
{
	int	o;

	while (str[i])
	{
		o = 0;
		while (str[i][o])
		{
			if (!(str[i][o] >= '0' && str[i][o] <= '9') && str[i][o] != '+'
				&& str[i][o] != '-')
				return (0);
			o++;
		}
		i++;
	}
	return (1);
}

int	str_signal(char **str, int i)
{
	int	o;
	int	signal;

	if ((str[i][0] == '-' || str[i][0] == '+') && str[i][1] == '\0')
		return (0);
	while (str[i])
	{
		o = 0;
		signal = 0;
		while (str[i][o])
		{
			if (str[i][o] == '+' || str[i][o] == '-')
				signal += 1;
			if (signal >= 2)
				return (0);
			o++;
		}
		i++;
	}
	return (1);
}

int	str_max_min(char **str, int i)
{
	while (str[i])
	{
		if (ft_atoi(str[i]) > INT_MAX || ft_atoi(str[i]) < INT_MIN)
			return (0);
		i++;
	}
	return (1);
}

int	str_double(char **str, int i)
{
	int	number;
	int	test;
	int	o;

	while (str[i])
	{
		number = ft_atoi(str[i]);
		o = i + 1;
		while (str[o])
		{
			test = ft_atoi(str[o]);
			if (number == test)
				return (0);
			o++;
		}
		i++;
	}
	return (1);
}

int	checkers(char **str, int i)
{
	if (!str_is_number(str, i))
		printf_error();
	if (!str_signal(str, i))
		printf_error();
	if (!str_nb_signal(str, i))
		printf_error();
	if (!str_max_min(str, i))
		printf_error();
	if (!str_double(str, i))
		printf_error();
	return (1);
}
