/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigolon <erigolon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:04:56 by erigolon          #+#    #+#             */
/*   Updated: 2023/06/12 14:53:39 by erigolon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
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

void	printf_error(void);
int		checkers(char **str, int i);
t_stack	*lstlast_stack(t_stack *lst);
t_stack	*lstlast_second(t_stack *lst);
t_stack	*add_to_list(int argc, char **argv, int i);
void	check_order(t_stack **stack_a, t_stack **stack_b);
int		lstsize_stack(t_stack *stack);
void	assign_index(t_stack *stack_a, int len_list);
void	order_three(t_stack **stack_a);
int		is_ordered(t_stack *stack_a);
void	do_sa(t_stack **stack_a);
void	do_sb(t_stack **stack_b);
void	do_ss(t_stack **stack_a, t_stack **stack_b);
void	do_ra(t_stack **stack_a);
void	do_rb(t_stack **stack_b);
void	do_rr(t_stack **stack_a, t_stack **stack_b);
void	do_rra(t_stack **stack_a);
void	do_rrb(t_stack **stack_b);
void	do_rrr(t_stack **stack_a, t_stack **stack_b);
void	do_pa(t_stack **stack_a, t_stack **stack_b);
void	do_pb(t_stack **stack_a, t_stack **stack_b);
void	order_big(t_stack **stack_a, t_stack **stack_b);
void	pos_target(t_stack **stack_a, t_stack **stack_b);
void	cost(t_stack **stack_a, t_stack **stack_b);
void	cheap_move(t_stack **stack_a, t_stack **stack_b);
void	do_move(t_stack **stack_a, t_stack **stack_b, int cost_a, int cost_b);
int		index_low_pos(t_stack **stack);

#endif