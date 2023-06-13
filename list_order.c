/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_order.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigolon <erigolon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 10:17:56 by erigolon          #+#    #+#             */
/*   Updated: 2023/06/13 11:46:07 by erigolon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void	free_stack(t_stack **stack)
{
	t_stack	*temp;

	if (!stack || !(*stack))
		return ;
	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
	*stack = NULL;
}

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

int	lstsize_stack(t_stack *stack)
{
	int	nodes;

	nodes = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		stack = stack->next;
		nodes++;
	}
	return (nodes);
}

void	check_order(t_stack **stack_a, t_stack **stack_b)
{
	int	len_list;

	if (is_ordered(*stack_a))
		return ;
	len_list = lstsize_stack(*stack_a);
	assign_index(*stack_a, (len_list + 1));
	if (len_list == 1)
		return ;
	else if (len_list == 2)
		do_sa(stack_a);
	else if (len_list == 3)
		order_three(stack_a);
	else
		order_big(stack_a, stack_b);
}
