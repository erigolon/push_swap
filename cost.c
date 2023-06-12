/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigolon <erigolon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 12:05:23 by erigolon          #+#    #+#             */
/*   Updated: 2023/06/12 15:11:58 by erigolon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void	cost(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp_a;
	t_stack	*temp_b;
	int		size_a;
	int		size_b;

	temp_a = *stack_a;
	temp_b = *stack_b;
	size_a = lstsize_stack(*stack_a);
	size_b = lstsize_stack(*stack_b);
	while (temp_b)
	{
		temp_b->cost_b = temp_b->pos;
		if (temp_b->pos > size_b / 2)
			temp_b->cost_b = (size_b - temp_b->pos) * -1;
		temp_b->cost_a = temp_b->target_pos;
		if (temp_b->target_pos > size_a / 2)
			temp_b->cost_a = (size_a - temp_b->target_pos) * -1;
		temp_b = temp_b->next;
	}
}

int	abs_n(int n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}

void	cheap_move(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;
	int		cheap;
	int		cost_a;
	int		cost_b;

	temp = *stack_b;
	cheap = INT_MAX;
	while (temp)
	{
		if (abs_n(temp->cost_a) + abs_n(temp->cost_b) < abs_n(cheap))
		{
			cheap = abs_n(temp->cost_a) + abs_n(temp->cost_b);
			cost_a = temp->cost_a;
			cost_b = temp->cost_b;
		}
		temp = temp->next;
	}
	do_move(stack_a, stack_b, cost_a, cost_b);
}
