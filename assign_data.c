/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigolon <erigolon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 17:04:34 by erigolon          #+#    #+#             */
/*   Updated: 2023/05/31 17:22:36 by erigolon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void	assign_index(t_stack *stack_a, int len_list)
{
	t_stack	*lst;
	t_stack	*highest;
	int		value;

	while (--len_list >= 0)
	{
		lst = stack_a;
		value = INT_MIN;
		highest = NULL;
		while (lst)
		{
			if (lst->value == INT_MIN && lst->index == 0)
				lst->index = 1;
			if (lst->value > value && lst->index == 0)
			{
				value = lst->value;
				highest = lst;
				lst = stack_a;
			}
			else
				lst = lst->next;
		}
		if (highest != NULL)
			highest->index = len_list;
	}
}
