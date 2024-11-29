/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_reverse_rotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 08:43:00 by abraekev          #+#    #+#             */
/*   Updated: 2024/10/15 12:45:22 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ops_reverse_rotate(t_stack *stack)
{
	if (stack->size < 2)
		return ;
	stack->top = next_up(stack, stack->top);
	stack->bottom = next_up(stack, stack->bottom);
}

void	rra(t_ps *data)
{
	ops_reverse_rotate(&data->a);
	if (data->log_ops)
		log_ops(data, RRA);
}

void	rrb(t_ps *data)
{
	ops_reverse_rotate(&data->b);
	if (data->log_ops)
		log_ops(data, RRB);
}

void	rrr(t_ps *data)
{
	ops_reverse_rotate(&data->a);
	ops_reverse_rotate(&data->b);
	if (data->log_ops)
		log_ops(data, RRR);
}
