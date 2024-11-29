/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 21:57:20 by abraekev          #+#    #+#             */
/*   Updated: 2024/10/15 12:47:05 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ops_swap(t_stack *stack)
{
	int	tmp;

	if (stack->size < 2)
		return ;
	tmp = stack->stack[next_down(stack, stack->top)];
	stack->stack[next_down(stack, stack->top)] = stack->stack[stack->top];
	stack->stack[stack->top] = tmp;
}

void	sa(t_ps *data)
{
	ops_swap(&data->a);
	if (data->log_ops)
		log_ops(data, SA);
}

void	sb(t_ps *data)
{
	ops_swap(&data->b);
	if (data->log_ops)
		log_ops(data, SB);
}

void	ss(t_ps *data)
{
	ops_swap(&data->a);
	ops_swap(&data->b);
	if (data->log_ops)
		log_ops(data, SS);
}
