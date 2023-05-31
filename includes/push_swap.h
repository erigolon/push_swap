/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigolon <erigolon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:04:56 by erigolon          #+#    #+#             */
/*   Updated: 2023/05/31 12:30:48 by erigolon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include <limits.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}					t_stack;

int		checkers(char **str, int i);
t_stack	*add_to_list(int argc, char **argv, int i);
void	check_order(t_stack **stack_a, t_stack **stack_b);
int		lstsize_stack(t_stack *stack);
void	do_sa(t_stack **stack_a);

#endif