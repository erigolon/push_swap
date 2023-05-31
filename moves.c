/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigolon <erigolon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 11:52:38 by erigolon          #+#    #+#             */
/*   Updated: 2023/05/31 14:27:03 by erigolon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void	swap(t_stack *stack)
{
	int	temp;

	if (stack == NULL || stack->next == NULL)
		return ;
	temp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = temp;
	temp = stack->index;
	stack->index = stack->next->index;
	stack->next->index = temp;
}

void	do_sa(t_stack **stack_a)
{
	swap(*stack_a);
	ft_putstr_fd("sa\n", 1);
}

void	do_sb(t_stack **stack_b)
{
	swap(*stack_b);
	ft_putstr_fd("s\n", 1);
}