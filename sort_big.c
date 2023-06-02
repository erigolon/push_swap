/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigolon <erigolon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 14:51:02 by erigolon          #+#    #+#             */
/*   Updated: 2023/06/02 14:25:34 by erigolon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void	push_stack(t_stack **stack_a, t_stack **stack_b)
{
	int	size_lst;
	int	pushed;
	int	i;

	size_lst = lstsize_stack(*stack_a);
	pushed = 0;
	i = 0;
	while (size_lst > 6 && i < size_lst && pushed < size_lst / 2)
	{
		if ((*stack_a)->index <= size_lst / 2)
		{
			do_pb(stack_a, stack_b);
			pushed++;
		}
		else
			do_ra(stack_a);
		i++;
	}
	while (size_lst - pushed > 3)
	{
		do_pb(stack_a, stack_b);
		pushed++;
	}
}

void	order_big(t_stack **stack_a, t_stack **stack_b)
{
	push_stack(stack_a, stack_b);
	order_three(stack_a);
}
