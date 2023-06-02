/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigolon <erigolon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 11:27:12 by erigolon          #+#    #+#             */
/*   Updated: 2023/06/02 11:56:11 by erigolon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void	push(t_stack **origin, t_stack **dest)
{
	t_stack	*temp;

	if (*origin == NULL)
		return ;
	temp = (*origin)->next;
	(*origin)->next = *dest;
	*dest = *origin;
	*origin = temp;
}

void	do_pa(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_b, stack_a);
	ft_putstr_fd("pa\n", 1);
}

void	do_pb(t_stack **stack_b, t_stack **stack_a)
{
	push(stack_a, stack_b);
	ft_putstr_fd("pb\n", 1);
}
