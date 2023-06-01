/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigolon <erigolon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 11:58:22 by erigolon          #+#    #+#             */
/*   Updated: 2023/06/01 12:35:36 by erigolon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void	rev_rotate(t_stack	**stack)
{
	t_stack	*temp;
	t_stack	*last;
	t_stack	*second_last;

	last = lstlast_stack(*stack);
	second_last = lstlast_second(*stack);
	temp = *stack;
	*stack = last;
	(*stack)->next = temp;
	second_last->next = NULL;
}

void	do_rra(t_stack **stack_a)
{
	rev_rotate(stack_a);
	ft_putstr_fd("rra\n", 1);
}

void	do_rrb(t_stack **stack_b)
{
	rev_rotate(stack_b);
	ft_putstr_fd("rrb\n", 1);
}

void	do_rrr(t_stack **stack_a, t_stack **stack_b)
{
	rev_rotate(stack_a);
	rev_rotate(stack_b);
	ft_putstr_fd("rrr\n", 1);
}
