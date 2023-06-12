/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigolon <erigolon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 12:35:25 by erigolon          #+#    #+#             */
/*   Updated: 2023/06/12 13:34:08 by erigolon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void	do_rev_rotate_both(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
	while (*cost_a < 0 && cost_b < 0)
	{
		(*cost_a)++;
		(*cost_b)++;
		do_rrr(a, b);
	}
}

void	do_rotate_both(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && cost_b > 0)
	{
		(*cost_a)--;
		(*cost_b)--;
		do_rr(a, b);
	}
}

void	do_rotate_a(t_stack **stack_a, int *cost_a)
{
	while (cost_a)
	{
		if (*cost_a > 0)
		{
			do_ra(stack_a);
			(*cost_a)--;
		}
		else if (*cost_a < 0)
		{
			do_rra(stack_a);
			(*cost_a)++;
		}
	}
}

void	do_rotate_b(t_stack **stack_b, int *cost_b)
{
	while (cost_b)
	{
		if (*cost_b > 0)
		{
			do_rb(stack_b);
			(*cost_b)--;
		}
		else if (*cost_b < 0)
		{
			do_rrb(stack_b);
			(*cost_b)++;
		}
	}
}

void	do_move(t_stack **stack_a, t_stack **stack_b, int cost_a, int cost_b)
{
	if (cost_a < 0 && cost_b < 0)
		do_rev_rotate_both(stack_a, stack_a, &cost_a, &cost_b);
	else if (cost_a > 0 && cost_b > 0)
		do_rotate_both(stack_a, stack_a, &cost_a, &cost_b);
	do_rotate_a(stack_a, &cost_a);
	do_rotate_b(stack_b, &cost_b);
	do_pa(stack_a, stack_b);
}
