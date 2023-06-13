/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigolon <erigolon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 16:24:53 by erigolon          #+#    #+#             */
/*   Updated: 2023/06/01 12:33:11 by erigolon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

t_stack	*lstlast_second(t_stack *lst)
{
	while (lst && lst->next && lst->next->next != NULL)
		lst = lst->next;
	return (lst);
}

t_stack	*lstnew_stack(int value)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->value = value;
	stack->index = 0;
	stack->pos = -1;
	stack->target_pos = -1;
	stack->cost_a = -1;
	stack->cost_b = -1;
	stack->next = NULL;
	return (stack);
}

t_stack	*lstlast_stack(t_stack *lst)
{
	if (!lst)
		return (0);
	while (lst->next != 0)
		lst = lst->next;
	return (lst);
}

void	lstadd_back_stack(t_stack **stack, t_stack *new)
{
	t_stack	*back;

	if (stack && new)
	{
		if (!*stack)
			*stack = new;
		else
		{
			back = lstlast_stack(*stack);
			back->next = new;
		}
	}
}

t_stack	*add_to_list(int argc, char **argv, int i)
{
	t_stack	*stack_a;
	int		first;
	int		number;

	first = 1;
	while (i < argc)
	{
		number = ft_atoi(argv[i]);
		if (first == 1)
		{
			stack_a = lstnew_stack(number);
			first = 0;
		}
		else
			lstadd_back_stack(&stack_a, lstnew_stack(number));
		i++;
	}
	return (stack_a);
}
