/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_order.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigolon <erigolon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 10:17:56 by erigolon          #+#    #+#             */
/*   Updated: 2023/05/31 13:15:07 by erigolon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include "./includes/push_swap.h"

int	is_ordered(t_stack *stack_a)
{
	while (stack_a->next != NULL)
	{
		if (stack_a->value > stack_a->next->value)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

int	lstsize_stack(t_stack *stack_a)
{
	int	nodes;

	nodes = 0;
	while (stack_a != 0)
	{
		nodes++;
		stack_a = stack_a->next;
	}
	return (nodes);
}

void	check_order(t_stack *stack_a)
{
	int	len_list;

	if (is_ordered(stack_a))
		return ;
	len_list = lstsize_stack(stack_a);
	if (len_list == 1)
		return ;
	else if (len_list == 2)
		sa_move(stack_a);
	else if (len_list == 3)
	{
		order_three(stack_a);
	}
	else
	{	
	}
}
*/