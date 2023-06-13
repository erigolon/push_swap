/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigolon <erigolon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 13:40:15 by erigolon          #+#    #+#             */
/*   Updated: 2023/06/12 14:57:24 by erigolon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

static void	position(t_stack **stack)
{
	t_stack	*temp;
	int		i;

	temp = *stack;
	i = 0;
	while (temp)
	{
		temp->pos = i;
		temp = temp->next;
		i++;
	}
}

int	index_low_pos(t_stack **stack)
{
	t_stack	*temp;
	int		low_index;
	int		low_pos;

	temp = *stack;
	low_index = INT_MAX;
	position(stack);
	low_pos = temp->pos;
	while (temp)
	{
		if (temp->index < low_index)
		{
			low_index = temp->index;
			low_pos = temp->pos;
		}
		temp = temp->next;
	}
	return (low_pos);
}

static int	get_target(t_stack **a, int b_idx, int target_idx, int target_pos)
{
	t_stack	*tmp_a;

	tmp_a = *a;
	while (tmp_a)
	{
		if (tmp_a->index > b_idx && tmp_a->index < target_idx)
		{
			target_idx = tmp_a->index;
			target_pos = tmp_a->pos;
		}
		tmp_a = tmp_a->next;
	}
	if (target_idx != INT_MAX)
		return (target_pos);
	tmp_a = *a;
	while (tmp_a)
	{
		if (tmp_a->index < target_idx)
		{
			target_idx = tmp_a->index;
			target_pos = tmp_a->pos;
		}
		tmp_a = tmp_a->next;
	}
	return (target_pos);
}

void	pos_target(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;
	int		target_pos;

	temp = *stack_b;
	position(stack_a);
	position(stack_b);
	target_pos = 0;
	while (temp)
	{
		target_pos = get_target(stack_a, temp->index, INT_MAX, target_pos);
		temp->target_pos = target_pos;
		temp = temp->next;
	}
}
